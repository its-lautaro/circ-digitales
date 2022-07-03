/*
 * DHT11.c
 * Author: Lau
 *
 * Single-bus data format is used for communication and synchronization between MCU and DHT11 sensor. One communication process is about 4ms.
 *
 * Data consists of decimal and integral parts. A complete data transmission is 40bit, and the sensor sends higher data bit first.
 * * 8bit integral RH data
 * * 8bit decimal RH data
 * * 8bit integral T data
 * * 8bit decimal T data
 * * * 8bit check sum. * * *
 */

#define DHT11_PIN PINC0

#include "utils.h"
#include "dht11.h"

static uint8_t data[5];
static char msg[50];
static char humidity[50];
static char temperature[50];
/*************************************************************************************************************************************************
When MCU sends a start signal, DHT11 changes from the low-power-consumption mode to the running-mode, waiting for MCU completing the start signal.
Once it is completed, DHT11 sends a response signal of 40-bit data that include the relative humidity and temperature information to MCU.

Without the start signal from MCU, DHT11 will not give the response signal to MCU.

Once data is collected, DHT11 will change to the lowpower-consumption mode until it receives a start signal from MCU again.
*************************************************************************************************************************************************/
static void Start()
{
    DDRC |= (1 << DHT11_PIN);   // output
    PORTC &= ~(1 << DHT11_PIN); // dht low
    _delay_ms(20);              // hold 20ms
    PORTC |= (1 << DHT11_PIN);  // dht high
}

static void Response()
{
    DDRC &= ~(1 << DHT11_PIN); // input
    while (PINC & (1 << DHT11_PIN))
        ; // wait for dht low
    while ((PINC & (1 << DHT11_PIN)) == 0)
        ; // dht low
    while (PINC & (1 << DHT11_PIN))
        ; // dht high
}

/*************************************************************************************************************************************************
When DHT is sending data to MCU, every bit of data begins with the 50us low-voltage-level
and the length of the following high-voltage-level signal determines whether data bit is "0" or "1"
* 0 -> 26-28us
* 1 -> 70us
**************************************************************************************************************************************************/
static uint8_t ReadByte()
{
    uint8_t data = 0;
    for (int i = 0; i < 8; i++)
    {
        while ((PINC & (1 << DHT11_PIN)) == 0)
            ; // dht holds 0 before sending data
        _delay_us(30);
        if (PINC & (1 << DHT11_PIN))
        { // if dht high lasted >30ms it's a 1
            data = ((data << 1) | 1);
        }
        else
        {
            data = (data << 1);
        }
        while (PINC & (1 << DHT11_PIN))
            ; // wait for dht low (next bit signal)
    }
    return data;
}

static uint8_t ReadData(char *humidity, char *temperature)
{
    uint8_t checksum = 0;
    cli();
    Start();
    Response();
    data[0] = ReadByte(); // humidityedad high byte
    data[1] = ReadByte(); // humidityedad low byte
    data[2] = ReadByte(); // temperature high
    data[3] = ReadByte(); // temperature low
    data[4] = ReadByte(); // checksum
    checksum = data[0] + data[1] + data[2] + data[3];
    // end listening
    DDRC |= 1 << DHT11_PIN;
    PORTC |= 1 << DHT11_PIN;
    sei();
    if (checksum == data[4])
    {
        sprintf(humidity, "humedad Relativa: %2d.%1d", data[0], data[1]);
        sprintf(temperature, "temperatura: %2d.%1d C", data[2], data[3]);
        return 1;
    }
    else
    {
        return 0;
    }
}

char *DHT11_getMessage()
{
    ReadData(humidity, temperature);
    strcpy(msg, humidity);
    strcat(msg, "\r");
    strcat(msg, temperature);
    strcat(msg, "\r");
    return msg;
}