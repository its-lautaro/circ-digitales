#include "utils.h"
#include "uart.h"


static volatile uint8_t comando_flag = 0;
static char bienvenida[] = "Bienvenido\rON: para encender, OFF para apagar, RST para reiniciar\r";
static char invalido[] = "Comando invalido\r";

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

void UART_setMensaje(char *msg)
{
	mensaje = msg;
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

/* Habilito las interrupciones para consultar al sensor*/
void UART_On()
{
	TIMER_clearCount();
	TIMER_Enable();
}


/*
* Deshabilita consultas al sensor
*/
void UART_Off()
{
	TIMER_Disable(); //ya no se consultara al dht
	SerialPort_RX_Interrupt_Enable(); // ?
}

// Retorno el generador a su estado por defecto
// Apago el generador,
// seteo las condiciones para que se imprima el mensaje de bienvenida
// y habilito las interrupciones por transmicion
void UART_Reset()
{
	UART_Off();
	mensaje = bienvenida;
	SerialPort_TX_Interrupt_Enable();
}
// Seteo las condiciones para que se imprima el mensaje de error
// habilito interrupciones por transmicion para que se pueda escribir otro comando

void UART_Print_Error()
{
	mensaje = invalido;
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
	sei();
}
}
