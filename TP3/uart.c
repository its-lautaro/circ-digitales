/*
 * usart.c
 *
 * Created : 15-08-2020 07:24:45 PM
 * Author  : Arnab Kumar Das
 * Website : www.ArnabKumarDas.com
 */

#define F_CPU 16000000UL // Defining the CPU Frequency

#include <avr/io.h>		// Contains all the I/O Register Macros
#include <util/delay.h> // Generates a Blocking Delay
#include <string.h>
#include "serialPort.h"
#include "dht11.h"

#define USART_BAUDRATE 9600 // Desired Baud Rate
#define BAUD_PRESCALER (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define ASYNCHRONOUS (0 << UMSEL00) // USART Mode Selection

#define DISABLED (0 << UPM00)
#define EVEN_PARITY (2 << UPM00)
#define ODD_PARITY (3 << UPM00)
#define PARITY_MODE DISABLED // USART Parity Bit Selection

#define ONE_BIT (0 << USBS0)
#define TWO_BIT (1 << USBS0)
#define STOP_BIT ONE_BIT // USART Stop Bit Selection

#define FIVE_BIT (0 << UCSZ00)
#define SIX_BIT (1 << UCSZ00)
#define SEVEN_BIT (2 << UCSZ00)
#define EIGHT_BIT (3 << UCSZ00)
#define DATA_BIT EIGHT_BIT // USART Data Bit Selection

static volatile uint8_t comando_flag = 0;
static volatile uint8_t bienvenida_condicion = 1;
static char bienvenida[] = "Bienvenido \r ON: para encender, OFF para apagar, RST para reiniciar \r";
static char invalido[] = "Comando invalido \r";
static char hum[5];
static char temp[5];
static char *mensaje;

static char buffer[20];

void UARTinit()
{
	// Set Baud Rate
	UBRR0H = BAUD_PRESCALER >> 8;
	UBRR0L = BAUD_PRESCALER;

	// Set Frame Format
	UCSR0C = ASYNCHRONOUS | PARITY_MODE | STOP_BIT | DATA_BIT;

	mensaje = bienvenida;

	// Enable Receiver and Transmitter
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UART_Off(); // apago el generador
	SerialPort_TX_Interrupt_Enable();
	SerialPort_RX_Interrupt_Enable();
}

void UART_TransmitPolling(uint8_t DataByte)
{
	while ((UCSR0A & (1 << UDRE0)) == 0)
	{
	}; // Do nothing until UDR is ready
	UDR0 = DataByte;
}

void UART_TransmitString(char *msg)
{
	uint8_t i = 0;
	for (i = 0; i < strlen(msg); i++)
	{
		UART_TransmitPolling(msg[i]);
	}
}

// retorno el valor del flag de comandos
uint8_t UART_HayComando()
{
	return comando_flag;
}

// Deshabilito el flag de comandos

void UART_Set_False_Command_Flag()
{
	comando_flag = 0;
}

// Deshabilito las interrupciones para recepcion
// y devuelvo el valor del buffer donde se guarda el comando

char *UART_GetComando()
{
	SerialPort_RX_Interrupt_Disable();
	return buffer;
}

// Seteo la frecuencia con el valor recibido por parametro
// y habilito las interrupciones para recepcion para que el serial port pueda recibir los mensajes del sensor

void UART_On()
{
	DHT11_read_data(hum, temp);
	mensaje = "HOLA \r";
	SerialPort_TX_Interrupt_Enable();
}

// Apago el generador, configurando como entrada el PINB1 (OC1A)
// y habilito interrupciones por recepcion

void UART_Off()
{
	SerialPort_RX_Interrupt_Enable();
}

// Retorno el generador a su estado por defecto
// Apago el generador,
// seteo las condiciones para que se imprima el mensaje de bienvenida
// y habilito las interrupciones por transmicion
void UART_Reset()
{
	UART_Off();
	mensaje = bienvenida;
	bienvenida_condicion = 1;
	SerialPort_TX_Interrupt_Enable();
}
// Seteo las condiciones para que se imprima el mensaje de error
// habilito interrupciones por transmicion para que se pueda escribir otro comando

void UART_Print_Error()
{
	mensaje = invalido;
	bienvenida_condicion = 0;
	SerialPort_TX_Interrupt_Enable();
}

ISR(USART_RX_vect) // interrupci�n de recepci�n
{

	static volatile uint8_t i = 0;
	unsigned char dato;

	dato = UDR0; // leo dato del buffer de recepcion

	// leo datos hasta llegar al enter, en caso de leer el
	// caracter de borrado se sobreescribe el caracter previo

	if (dato == '\r')
	{
		buffer[i] = '\0';
		i = 0;
		comando_flag = 1;
		SerialPort_RX_Interrupt_Disable(); // deshabilito las interrupciones ya que tengo una secci�n critica por mis variables compartidas 'buffer' y 'acci�nFlag'
	}
	else
	{
		if (dato == '\b')
			i--;
		else
		{
			buffer[i] = dato;
			i++;
		}
	}
}

ISR(USART_UDRE_vect) // interrupci�n de transmisi�n
{
	static volatile uint8_t i = 0;
	// Transmito el el caracter en la posicion i del mensaje, si es un fin de linea se termina la transmicion
	// y se deshabilitan las interrupciones por transmicion y se habilitan las interrupciones por recepcion

	if (mensaje[i] != '\0')
	{
		SerialPort_Send_Data(mensaje[i]);
		i++;
	}
	else
	{
		i = 0;
		SerialPort_TX_Interrupt_Disable();
		SerialPort_RX_Interrupt_Enable(); // Puede recibir para que se le manden mensajes
	}
}
