# 1. Apuntes de Clase — Circuitos digitales y Microcontrolares (E0305)

- [1. Apuntes de Clase — Circuitos digitales y Microcontrolares (E0305)](#1-apuntes-de-clase--circuitos-digitales-y-microcontrolares-e0305)
- [2. Lenguaje C](#2-lenguaje-c)
  - [2.1. Modificadores de acceso](#21-modificadores-de-acceso)
    - [2.1.1. Static](#211-static)
    - [2.1.2. Const](#212-const)
    - [2.1.3. Volatile](#213-volatile)
    - [2.1.4. Register](#214-register)
  - [2.2. Preprocesador](#22-preprocesador)
    - [2.2.1. Directivas](#221-directivas)
  - [2.3. Caracteres](#23-caracteres)
    - [2.3.1. String Handling Functions](#231-string-handling-functions)
  - [2.4. Alcance de variables](#24-alcance-de-variables)
  - [2.5. Operadores Logicos](#25-operadores-logicos)
  - [2.6. Prototipos de funciones](#26-prototipos-de-funciones)
  - [2.7. Punteros y arreglos](#27-punteros-y-arreglos)
  - [2.8. Structs](#28-structs)
  - [2.9. Unions](#29-unions)
- [3. Programación modular](#3-programación-modular)
  - [3.1. Comunicación intermodular. Interfaces.](#31-comunicación-intermodular-interfaces)
  - [3.2. Modularización en C](#32-modularización-en-c)
  - [3.3. Plantilla para archivos .h](#33-plantilla-para-archivos-h)
  - [3.4. Plantilla para archivos .c](#34-plantilla-para-archivos-c)
  - [3.5. Header de proyecto](#35-header-de-proyecto)
  - [3.6. Header de puertos o placa](#36-header-de-puertos-o-placa)
  - [3.7. Documentación](#37-documentación)
    - [3.7.1. Ejemplo](#371-ejemplo)
  - [3.8. Convención de nombres](#38-convención-de-nombres)
- [4. Familia de microcontroladores AVR](#4-familia-de-microcontroladores-avr)
  - [4.1. Comparativa](#41-comparativa)
  - [4.2. Arquitectura AVR (Atmega328P)](#42-arquitectura-avr-atmega328p)
    - [4.2.1. CPU](#421-cpu)
- [5. Programación de Entrada/Salida](#5-programación-de-entradasalida)
  - [5.1. Funciones de avr libc para evaluar pines](#51-funciones-de-avr-libc-para-evaluar-pines)
- [6. Interrupciones](#6-interrupciones)
  - [6.1. Paso por paso](#61-paso-por-paso)
  - [6.2. Vectores de interrupcion](#62-vectores-de-interrupcion)
  - [6.3. RESET](#63-reset)
    - [6.3.1. MCU Status Register](#631-mcu-status-register)
  - [6.4. Latencia de interrupcion](#64-latencia-de-interrupcion)
  - [6.5. Interrupciones anidadas](#65-interrupciones-anidadas)
  - [6.6. Interrupciones externas](#66-interrupciones-externas)
    - [6.6.1. Activacion Por Flanco vs. Por Nivel](#661-activacion-por-flanco-vs-por-nivel)
  - [6.7. Interrupciones por Pin Change (PCINT)](#67-interrupciones-por-pin-change-pcint)
    - [6.7.1. Prioridades de atencion](#671-prioridades-de-atencion)
- [7. Timer/Counter 0](#7-timercounter-0)
  - [7.1. Modos de funcionamiento](#71-modos-de-funcionamiento)
    - [7.1.1. Normal](#711-normal)
    - [7.1.2. CTC (Clear Timer on Compare Match)](#712-ctc-clear-timer-on-compare-match)
    - [7.1.3. PWM](#713-pwm)
      - [7.1.3.1. Fast PWM](#7131-fast-pwm)
      - [7.1.3.2. Phase Correct PWM](#7132-phase-correct-pwm)
  - [7.2. Prescaler](#72-prescaler)
  - [7.3. Registros para su programación](#73-registros-para-su-programación)
- [8. MEF](#8-mef)
  - [8.1. Modelo de Mealy](#81-modelo-de-mealy)
  - [8.2. Modelo de Moore](#82-modelo-de-moore)
  - [8.3. Implementación en C](#83-implementación-en-c)
    - [8.3.1. Usando switch-case](#831-usando-switch-case)
    - [8.3.2. Usando punteros a función](#832-usando-punteros-a-función)
- [9. Timer 2. RTC](#9-timer-2-rtc)
- [10. Watchdog Timer](#10-watchdog-timer)
- [11. Planificación y Ejecución de Tareas en Sistemas Embebidos](#11-planificación-y-ejecución-de-tareas-en-sistemas-embebidos)
  - [11.1. Super-Loop o Round Robin Cíclico](#111-super-loop-o-round-robin-cíclico)
  - [11.2. Foreground/Background o Event-Driven](#112-foregroundbackground-o-event-driven)
  - [11.3. Time-triggered (disparadas por tiempo)](#113-time-triggered-disparadas-por-tiempo)
  - [11.4. Resumen](#114-resumen)
- [12. RTOS (Real Time Operative System)](#12-rtos-real-time-operative-system)
  - [12.1. Scheduler](#121-scheduler)
  - [12.2. Modelo de tarea](#122-modelo-de-tarea)
  - [12.3. Componentes de un RTOS simple](#123-componentes-de-un-rtos-simple)
- [13. Timer 1](#13-timer-1)
  - [13.1. Input Capture](#131-input-capture)
  - [13.2. Output Compare](#132-output-compare)
- [14. Generacion y distribucion de reloj](#14-generacion-y-distribucion-de-reloj)
- [15. USART](#15-usart)
- [16. Arquitectura Background/Foreground](#16-arquitectura-backgroundforeground)
- [17. Drivers. Modelo Productor/Consumidor.](#17-drivers-modelo-productorconsumidor)
- [18. Protocolo SPI. I2C](#18-protocolo-spi-i2c)
- [19. PWM](#19-pwm)

# 2. Lenguaje C
## 2.1. Modificadores de acceso
### 2.1.1. Static
In the C programming language, static is used with global variables and functions to set their scope to the containing file. In local variables, static is used to store the variable in the statically allocated memory instead of the automatically allocated memory. While the language does not dictate the implementation of either type of memory, statically allocated memory is typically reserved in the data segment of the program at compile time, while the automatically allocated memory is normally implemented as a transient call stack.
### 2.1.2. Const
The qualifier const can be applied to the declaration of any variable to specify that its value will not be changed (Which depends upon where const variables are stored, we may change the value of const variable by using pointer).
### 2.1.3. Volatile
The volatile keyword is intended to prevent the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler. Their values can be changed by code outside the scope of current code at any time. The system always reads the current value of a volatile object from the memory location rather than keeping its value in temporary register at the point it is requested, even if a previous instruction asked for a value from the same object.
**Use cases:**
* Global variables modified by an interrupt service routine outside the scope
* Global variables within a multi-threaded application
### 2.1.4. Register
Registers are faster than memory to access, so the variables which are most frequently used in a C program can be put in registers using register keyword. The keyword register
hints to compiler that a given variable can be put in a register. It’s compiler’s choice to put it in a register or not. Generally, compilers themselves do optimizations and put the variables in register.
## 2.2. Preprocesador
The C preprocessor, often known as cpp, is a macro processor that is used automatically by the C compiler to transform your program before compilation. It is a text substitution tool. Las directivas para el preprocesador comienzan con el simbolo #.
### 2.2.1. Directivas
* **define**: substitutes a preprocessor macro
* **include**: inserts a particular header from another file
* undef: undefines a preprocessor macro
* **ifdef**: returns true if the macro is defined
* ifndef: returns true if the macro is *not* defined
* if: tests if a compile time condition is true
* else: alternative for #if
* elif: else if in one statement
* endif: ends preprocessor conditional
* error: prints error message on stderr
* pragma: issues special commands to the compiler, using a standardized method.
* **typedef**: use to give a type a new name

## 2.3. Caracteres
* Character Constant: constante que representa un valor perteneciente al conjunto de caracteres. Se indica entre comillas simples 'a'.
* Character array: C language does not support strings as a data type, instead they are handled as a one-dimensional array of characters.
### 2.3.1. String Handling Functions
C supports a large number of string handling functions that can be used to carry out many of the string manipulations. These functions are packaged in the string.h library.
* strcat(dest,src) concatenates two strings
* strlen(str) show the length of a string
* strrev(str) reverse a string
* strcpy(dest,src) copies one string into another
* strcmp(a,b) compares two strings

## 2.4. Alcance de variables
In C programming language, variables defined within some function are known as **Local Variables** and variables which are defined outside of function block and are accessible
to entire program are known as **Global Variables**.

## 2.5. Operadores Logicos
* & -> binary AND
* | -> binary OR
* ^ -> binary XOR
* ~ -> Complemento 1 (invierte los bits)
* << -> binary left shift
* \>> -> binary right shift

**Nota:** La diferencia entre el AND binario (&) y el AND lógico (&&) es que el primero es una operacion que se realiza a nivel de bit.

## 2.6. Prototipos de funciones
A prototype declares the function name, its parameters, and its return type to the rest of the program prior to the function's actual declaration. Many C compilers do not check for parameter matching either in type or count. You can waste an enormous amount of time debugging code in which you are simply passing one too many or too few parameters by
mistake. **The prototype causes the compiler to check for parameters and flag an error for mismatches on count or type.** Prototypes should be placed at the beginning of your program.

## 2.7. Punteros y arreglos
Every variable is a memory location, and every memory location has its address defined which can be accessed using ampersand (&) operator, which denotes an address in memory.
```c
int main(){
    int var1;
    int var2[10];

    printf("address of var1 %x",&var1);
    printf("address of var2 %x",&var2);

    return 0;
}
```  
**A pointer is a variable whose value is the address of another variable.** Like any variable or constant, you must declare a pointer before using it to store any variable address.
```c
int *ip; //pointer to an integer
char str[10]; //pointer to the first element of str array

int num;

ip= &num; //puntero a num

printf(ip); //imprimir direccion de num
printf(*ip); //imprimir contenido de num
```

## 2.8. Structs
A structure is another *user defined data* type available in C that **allows combining data items of different kinds**. Structures are used to represent a record.
```c
struct Books{
    char title[50];
    char author[50];
    char subject[50];
    int id;
}

Books book;

book.title="titulo";
book.author=...
```

## 2.9. Unions
A union is a special data type available in C that allows to store different data types in the same memory location. You can define a union with many members, but only one member can contain a value at any given time. Unions provide an efficient way of using the same memory location for multiple-purpose. To define a union, you must use the union statement in the same way as you did while defining a structure. The union statement defines a new data type with more than one member for your program.
```c
union Data{
    int i;
    float f;
    char str[20];
}data;
```
Now, a variable of Data type can store an integer, a floating-point number, or a string of characters. **It means a single variable, i.e., same memory location, can be used to store multiple types of data**. You can use any built-in or user defined data types inside a union based on your requirement. 

**The memory occupied by a union will be large enough to hold the largest member of the union.**

# 3. Programación modular
Un módulo puede estar formado por un archivo o una colección de archivos que contienen las funciones que realizan en conjunto la tarea especificada. Los módulos pueden ser verificados y mantenidos por separado, además de que pueden ser desarrollados por un equipo de programadores. 

Un módulo bien desarrollado que cumple con una tarea especifica, puede ser separado del resto y puesto en otra aplicación sin problemas. Un módulo puede verse además como una caja negra que presenta una interfaz bien definida (puntos de entrada y puntos de salida) para comunicarse con el resto del mundo.

## 3.1. Comunicación intermodular. Interfaces.
Las variables globales NO se recomiendan para pasar información de un módulo a otro porque atentan contra la independencia y portabilidad del módulo.

Las interfaces permiten la comunicación entre módulos, determinan la forma de uso de cada uno y garantizan la independencia con el resto del sistema, se implementan mediante los parámetros de entrada de las funciones y los valores de retorno de las mismas.

Ocultar la información que maneja un módulo (por ejemplo los registros del MCU, ciertas variables o funciones) mejora la portabilidad. Este es un concepto básico en la POO (Programación Orientada a Objetos)

Por otro lado, es necesario restringir que módulos acceden al hardware (registros del MCU por ejemplo) y sincronizar los accesos entre los mismos (Mecanismos de sincronización de tareas). Una forma de conectar los módulos es en forma jerárquica (De mayor abstracción a menor abstracción (más cercano al hardware)).

Un módulo (o varios) que controlan el funcionamiento de un dispositivo de hardware constituye un “device driver” . Este contiene el conjunto de funciones necesarias para utilizar un dispositivo particular y provee al usuario una interfaz de comunicación estándar del tipo “open()”,“close()”, “ctr()”, “read()” y “write()”.

## 3.2. Modularización en C
* En C, un archivo puede asemejarse a una "clase".
* Las variables pueden encapsularse con el modificador de acceso *static* y proveyendo métodos Set y Get para accederla.
* Lo mismo aplica para las funciones, recordando que las funciones globales al proyecto deben declarar su prototipo en un .h
* Las constantes definidas en .h son globales al proyecto (public constant), las definidas en .c pertenecen al archivo (private constant)

De esta manera un programa completo puede dividirse en un conjunto de archivos que implementan tareas bien definidas, con reglas claras en el control de acceso a los recursos que manejan y con una interfaz de comunicación bien definida con el resto del mundo.

## 3.3. Plantilla para archivos .h
```c
/*======Evitar inclusión múltiple - begin======*/
#ifndef _NOMBRE_MODULO_H_
#define _NOMBRE_MODULO_H_
/*======Inclusión de dependencias de funciones públicas======*/
#include "dependency.h"
#include <dependency.h>
/*======Para compatibilizar el uso de este módulo desde C++======*/
#ifdef __cplusplus
extern "C"{
#endif
/*======Macros de definición de constantes públicas======*/
#define PI 3.14
/*======Macros "function-like"======*/
#define sum(x,y) ((x)+(y))
/*======Definiciones de tipos de datos públicos======*/
typedef void (*callBackFuncPtr_t)(void *);
/*======Declaración de prototipos (funciones públicas)======*/
bool_t rtcInit(rtc_t* rtc);
/*======Declaración de prototipos (funciones de interrupción públicas)======*/
void UART0_IRQHandler(void);
/*======Para compatibilizar el uso de este módulo desde C++======*/
#ifdef __cplusplus
}
#endif
/*======Evitar inclusión múltiple - end======*/
#endif /* _NOMBRE_MODULO_H_ */
```

## 3.4. Plantilla para archivos .c
```c
/*======Inclusio de cabecera propia======*/
#include "nombreModulo.h"
/*======Inclusión de dependencias de funciones privadas======*/
#include "dependency.h"
/*======Definición de constantes privadas======*/
#define MI_CONSTANTE 9
/*======Macros "function-like" privadas======*/
#define rtcConfig rtcInit
/*======Definición de tipos de datos privados======*/
#typedef void (*FuncPtrPrivado_t)(void *);
/*======Definición de variables globales públicas externas======*/
extern int32_t varGlobalExterna
/*======Definición de variables globales públicas======*/
int32_t varGlobalPublica=0;
/*======Definición de variables globales privadas======*/
static int32_t varGlobalPrivada=0;
/*======Prototipos de funciones privadas======*/
static void funPrivada(void);
/*======Implementaciones de funciones públicas======*/
bool_t rtcInit( rtc_t* rtc){
    // ..
}
/*======Implementaciones de manejadores de interrupciones públicos======*/
void UART0_IRQHandler(void){
    // ..
}
/*======Implementaciones de funciones privadas======*/
static void funPrivada(void){
    // ..
}
```
## 3.5. Header de proyecto
Un cambio en el hardware o en el pin out de la placa donde corre la aplicación, se modificará solo en este archivo y no debería afectar el resto de los módulos.
## 3.6. Header de puertos o placa
Permite definir las interfaces de entrada y salida de la aplicación en particular. Por ejemplo, definiciones de los terminales en las placas arduino X.

## 3.7. Documentación
Los comentarios deben tratar de contener la siguiente información:
* ¿Que hace el programa, módulo o función?
* ¿cuales son las entradas y salidas que produce?
* ¿como lo utilizo?,
* ¿cuales son las condiciones que producen errores?,
* ¿que algoritmo usa?,
* ¿como fue verificado?,
* ¿como hago cambios en el mismo?
* ¿quién es el autor? ¿fecha de creación? ¿logs de modificaciones?
* ¿licencia?... Entre otros…

### 3.7.1. Ejemplo
```c
short int SetPoint; /* Especifica la temperatura deseada para el lazo de control de temperatura. Precisión de 16 bits y en un rango de -55 a +125ºC*/

/***********************************************************************
* Propósito de la función: . . .
* Parámetros de entrada (tipo, rango y formato) : . . .
* Parámetros de salida (tipo, rango y formato) : . . .
* Condiciones de Error de la función (poner ejemplos si hace falta) : . . .
* Macros y su significado : . . .
* Otros comentarios: Autor, fecha y log de modificaciones, etc
***********************************************************************/
int FuncionSuma (int, int);
```

## 3.8. Convención de nombres
* Nombres de variables, ctes y funciones deben ser descriptivos no ambiguos.
* Las variables pueden llevar su tipo como prefijo (pcData, cData, ucData,...)
* Utilizar el nombre del archivo como parte del nombre de las funciones públicas del mismo (LCD_Init(), LCD_write_String(),...)
* Utilizar mayusculas o minusculas para indicar el alcance del objeto
  * Definiciones globales: ``PORTA``, ``TRUE``, ``NULL``, ``FREQ_CPU``, ``PI``
  * Definiciones locales : ``Max``, ``Min``, ``BufferTx``
  * Constantes: Variables locales: ``maxTemp``, ``errorCnt``
  * Variables globales (privadas): ``MaxTemp``, ``ErrorCnt``
  * Variables globales (públicas): ``ADC_Channel``, ``LCD_ErrorCnt``
  * Funciones privadas: ``ClearTime()``, ``Get_Char()``
  * Funciones globales (públicas): ``TIMER_ClearTime()``, ``KEPAD_Get_Char()``

# 4. Familia de microcontroladores AVR
## 4.1. Comparativa
<table>
    <tr>
        <th></th>
        <th>Atmega328P</th>
        <th>Atmega2560</th>
    </tr>
    <tr>
        <td>Perifericos</td>
        <td>
            <ul>
                <li>2 8-bit Timer/Counter w/ Separate Prescaler and Compare Mode</li>
                <li>1 16-bit Timer/Counter with Separate Prescaler, Compare Mode, and Capture Mode</li>
                <li>Real Time Counter with Separate Oscillator</li>
                <li>6 PWM Channels</li>
                <li>8-channel 10-bit ADC</li>
                <li>6-channel 10-bit ADC</li>
                <li>Programmable Serial USART</li>
                <li>Master/Slave SPI Serial Interface</li>
                <li>Byte-oriented 2-wire Serial Interface (Philips I2C compatible)</li>
                <li>Programmable Watchdog Timer with Separate On-chip Oscillator</li>
                <li>On-chip Analog Comparator</li>
            </ul>
        </td>
         <td>
            <ul>
                <li>2 8-bit Timer/Counter w/ Separate Prescaler and Compare Mode</li>
                <li>4 16-bit Timer/Counter with Separate Prescaler, Compare Mode, and Capture Mode</li>
                <li>Real Time Counter with Separate Oscillator</li>
                <li>4 8-bit PWM Channels</li>
                <li>12 Programmable resolution (2-16 bits) PWM Channels</li>
                <li>Output Compare Modulator</li>
                <li>8-channel 10-bit ADC</li>
                <li>16-channel 10-bit ADC</li>
                <li>4 Programmable Serial USART</li>
                <li>Master/Slave SPI Serial Interface</li>
                <li>Byte-oriented 2-wire Serial Interface (Philips I2C compatible)</li>
                <li>Programmable Watchdog Timer with Separate On-chip Oscillator</li>
                <li>On-chip Analog Comparator</li>
            </ul>
        </td>
    </tr>
    <tr>
        <td>RAM</td>
        <td>2K Bytes</td>
        <td>8K Bytes</td>
    </tr>
    <tr>
        <td>Flash</td>
        <td>32K Bytes</td>
        <td>256K Bytes</td>
    </tr>
</table>

## 4.2. Arquitectura AVR (Atmega328P)
### 4.2.1. CPU
* RISC: 131 instrucciones de 1 ciclo de reloj (o la mayoría)
* Hardvard: Memoria de programa y memoria de datos con buses independientes
* Basada en registros: 32 de 8 bits.

<img src="img/cpu.png" />

# 5. Programación de Entrada/Salida
Para controlar los puertos de entrada salida se utilizan los registros:
* DDRn: *Port n Data Direction Register*, define para cada pin su dirección (input/output)
* * **1 is output, 0 is input**
* PORTn: *Port n Data Register* registro usado para setear el estado de los pines del *puerto n*
* PINn: *Port n Input Pin Address*, se utiliza para leer el estado los pines de del *puerto n*, es un registro de solo lectura.
## 5.1. Funciones de avr libc para evaluar pines
* *PINC & (1<<PINC1)* **-->** bit_is_set (PINC, PINC1)
* *!(PINB & (1<<PINB2))* **-->** bit_is_clear (PINB, PINB2)
* *while( !(ADCSRA & (1<<ADIF)));* **-->** loop_until_bit_is_set (ADCSRA, ADIF);
* *while( ADCSRA & (1<<ADIF) ));* **-->** loop_until_bit_is_clear (ADCSRA, ADIF);
  
# 6. Interrupciones
La CPU de un microcontrolador ejecuta instrucciones secuencialmente, sin embargo, las aplicaciones requieren del uso de diferentes periféricos (internos o externos) y por lo tanto la CPU debe contar con un mecanismo
para interactuar con ellos y dar respuesta adecuada a sus demandas.

Los periféricos generalmente requieren la atención de la CPU de manera aleatoria en respuesta a algún evento. Para poder detectar estos eventos, la alternativa mas simple es la consulta o polling, en la que el CPU debe encargarse "manualmente" de preguntar al dispositivo si se produjo un evento que requiera su atencion. Esto es poco eficiente ya que gastamos ciclos de ejecucion del CPU en esperar a que se produzca un evento.

Un enfoque distinto es permitir al dispositivo que avise a la CPU solo cuando requiera su atencion. De esta manera la CPU se independiza del dispositivo y puede utilizar esos ciclos de ejecucion que gastaba esperando en otra tarea mas productiva. Para esto se utilizan las interrupciones.

Una interrupción es la ocurrencia de un evento producido por algún recurso del
microcontrolador, que ocasiona la suspensión temporal del programa principal.
La CPU atiende al evento con una función conocida como rutina de servicio a la
interrupción (ISR, Interrupt Service Routine). Una vez que la CPU concluye con las
instrucciones de la ISR, continúa con la ejecución del programa principal, regresando
al punto en donde fue suspendida su ejecución.

## 6.1. Paso por paso
El núcleo AVR cuenta con la **unidad de interrupciones**, un módulo que va a determinar
si se tienen las condiciones para que ocurra una interrupción.
Son tres las condiciones necesarias para que un recurso produzca una interrupción:
* El habilitador global de interrupciones (bit I de ```SREG```) debe estar activado
* El habilitador individual de la interrupción del recurso también debe estar activado
* En el recurso debe ocurrir el evento esperado.

Cuando el microcontrolador se enciende o reinicia, las interrupciones no están habilitadas,
su habilitación requiere la puesta en alto del bit I de SREG y de los habilitadores
individuales de los periféricos incorporados en el microcontrolador.

Al generarse una interrupción, el ```PC``` es almacenado en la pila de datos y a continuacion toma el valor
de una entrada en el vector de interrupciones (según sea la interrupción). Además de desactivar al bit I para no aceptar más interrupciones y finalizar con la instruccion bajo ejecucion en el momento de la interrupcion.

La ISR debe colocarse en una dirección preestablecida por Hardware, la cual corresponde
con un vector de interrupciones.

Una rutina de atención a interrupciones es finalizada con la instrucción ```RETI```, con la
cual el ```PC``` recupera el valor del tope de la pila y pone en alto nuevamente al bit I, para
que la CPU pueda recibir más interrupciones. Ademas, se limpia la flag que genero la interrupcion inicialmente.

## 6.2. Vectores de interrupcion
El grupo de localidades de memoria destinadas a guardar las direcciones de
las RSI, se llama **“Tabla de Vectores de Interrupción”**

El fabricante reserva direcciones de memoria especificas (llamadas vector) para cada interrupción **con una determinada prioridad dada por el orden que aparecen en la tabla**, en caso que se den varios pedidos de interrupción simultáneamente. El orden (y la prioridad) esta dado por el fabricante.

El fabricante especifica donde disponer de esta tabla, en la mayoría de los uC está al principio de la memoria de programa FLASH o al final.

El mecanismo de vector permite distinguir rápidamente entre múltiples
pedidos de interrupción y determinar su origen para ejecutar a la RSI que
corresponda. Para cada fuente de interrupción distinta debe existir **una sola RSI** asociada
que pueda ejecutarse. El programador diseña la RSI que desea se ejecute en cada caso como si
fuese una función especial.

## 6.3. RESET
La inicialización o reset de un microcontrolador es fundamental para su operación
adecuada, porque garantiza que sus registros internos van a tener un valor inicial
conocido. Existen varias causas de RESET:

* **Reset de Encendido (Power-on Reset):** El MCU es inicializado cuando el voltaje
de la fuente está por abajo del voltaje de umbral de encendido ($V_{POT}$), el cual tiene
un valor típico de 2.3 V.
* **Reset Externo:** El MCU es inicializado cuando un nivel bajo está presente en la terminal
RESET por un tiempo mayor a 1.5 uS, que es la longitud mínima requerida ($t_{RST}$).
* **Reset por Watchdog:** El MCU es inicializado cuando se ha habilitado al Watchdog
Timer y éste se ha desbordado.
* **Reset por reducción de voltaje (Brown out):** Se inicializa al MCU cuando el
detector de reducción de voltaje está habilitado y el voltaje de la fuente de
alimentación está por debajo del umbral establecido ($V_{BOT}$). El valor de $V_{BOT}$ es
configurable a 2.7 V ó 4.0 V, y el tiempo mínimo necesario ($t_{BOD}$) para considerar
una reducción de voltaje es de 2 uS.
* **Reset por JTAG:** El MCU es inicializado tan pronto como exista un 1 lógico en el
Registro de Reset del Sistema JTAG.

**NOTA:**  *JTAG hace referencia a una interfaz serial utilizada para la prueba de circuitos integrados y como medio para depurar sistemas empotrados*

### 6.3.1. MCU Status Register
Puesto que hay diferentes causas de reinicio, los AVR incluyen al Registro de Estado
y Control del MCU (```MCUCSR```) en el cual queda indicada la causa de reset por medio de una bandera. Los bits del registro MCUCSR son:

* Bits 7, 6 y 5: No tienen relación con el reset del sistema, en el ATMega8 no están
implementados.
* Bit 4 – JTRF: Bandera de reinicio por JTAG. No está implementada en el ATMega8.
* Bit 3 – WDRF: Bandera de reinicio por desbordamiento del Watchdog timer
* Bit 2 – BORF: Bandera de reinicio por reducción de voltaje (Brown out)
* Bit 1 – EXTRF: Bandera de reinicio desde la terminal de reset
* Bit 0 – PORF: Bandera de reinicio por encendido

## 6.4. Latencia de interrupcion
Es el tiempo que tarda el Controlador de interrupciones en dar respuesta a
una interrupción, se mide desde que se recibe el pedido hasta que efectivamente se ejecuta la primer instrucción de la RSI correspondiente.

En los AVR la latencia es de 4 ciclos de reloj como mínimo, durante este tiempo, se guarda el PC en la pila, se pone el bit I de ```SREG``` en 0 (desactiva la recepcion de otras interrupciones) y se busca el vector de
interrupción de mayor prioridad que corresponda.

En el caso en que el micro este en modo SLEEP, la latencia es de 8 ciclos.

El retorno de la interrupción (RETI) tambien lleva 4 ciclos.

## 6.5. Interrupciones anidadas
El anidamiento de interrupciones se da cuando una interrupcion puede interrumpir la rutina de atencion de otra interrupcion. Esto no esta permitido por defecto ya que al atender una rutina se desactivan las interrupciones, sin embargo puede permitirse este comportamiento manualmente si dentro de la rutina se vuelven a habilitar. Una interrupcion en curso solo puede ser interrumpida por otra interrupcion de mayor prioridad.

El anidamiento de interrupciones **no es recomendable** ya que imposibilita la creacion de codigo que se ajuste bien a todas las combinaciones de interrupciones, reduciendo la posibilidad de predecir el comportamiento del sistema, es decir, se pierde confiabilidad ya que no se pueden testear todas las condiciones.

## 6.6. Interrupciones externas

Las interrupciones externas sirven para detectar un estado lógico o un cambio de estado
en alguna de las terminales de entrada de un microcontrolador, con su uso se evita un
sondeo continuo en la terminal de interés. Son útiles para monitorear interruptores,
botones o sensores con salida a relevador.

En el ATMEGA328p hay dos terminales que pueden generar interrupciones de periféricos externos:

* INT0 (PD2)
* INT1 (PD3)

Estas interrupciones se habilitan con el registro EIMSK – External Interrupt Mask Register. El tipo de activacion es configurable mediante el registro EICRA.

<p style="text-align: center">
<img src="./img/eimsk.png"/>
<br/><i>Registro IMSK</i><br/>
<img src="./img/ext-int.png"/>
<br/><i>Registro EICRA</i><br/>
</p>

Las interrupciones externas pueden configurarse para detectar un nivel bajo de voltaje
o una transición, ya sea por un flanco de subida o de bajada

### 6.6.1. Activacion Por Flanco vs. Por Nivel
Si una interrupción funciona **por nivel** el periférico que la genera *“coloca y mantiene”* el nivel en la línea para que el uC atienda a esa petición. Durante la atención, el uC debería indicar al periférico externo, de algún modo, que ha sido atendido para que éste libere el nivel de la línea.
* Notar que al no ser una “petición registrada”, si el nivel no está presente cuando las interrupciones están habilitadas, el pedido no será tenido en cuenta.
* Por otro lado, si el periférico no retira el nivel de la línea, continuará solicitando interrupción
indefinidamente.

**Por lo tanto**, las interrupciones por nivel **no tienen memoria** y requieren de un aviso al
periférico para que no se procese la misma interrupción múltiples veces.

Si una interrupción funciona **por flanco** quiere decir que el periférico produce un
flanco en la línea y este pedido queda registrado en un Flag (Flip Flop) pidiendo
interrupción. Típicamente el uC borra este flag para indicar que esta interrupción ya
ha sido atendida sin necesidad de comunicárselo al periférico.

De esta manera, si las interrupciones están deshabilitas al momento de producirse el
flanco, los pedidos quedan “pendientes” y serán atendidos por prioridad cuando se
active la máscara de interrupción I.

<p style="text-align: center">
<img src="./img/nivel.png"/>
<br/><i>Activacion por Nivel.</i><br/>
<img src="./img/flanco.png"/>
<br/><i>Activacion por Flanco. No hay Acknowledge.</i><br/>
</p>

## 6.7. Interrupciones por Pin Change (PCINT)

A diferencia de las interrupciones INT0 e INT1 que son capaces de distingar nivel alto, nivel bajo, flanco de subida y flanco de bajada, este tipo de interrupciones se disparan ante cualquier *cambio de nivel* sin distinguir el sentido.

Los interrupciones Pin Change son habilitadas con el registro PCICR, y se habilitan para grupos de pines.<br/>
<p style="text-align:center"><img src="./img/pcicr.png"/></p>

* Bit PCIE0: Cuando esta activado (1) cualquier cambio en los pines PCI7..0 disparara una interrupcion. Los pines se enmascaran desde el registro PCMSK0. El vector de interrupcion asociado es PCINT0_vect.
* Bit PCIE1: Cuando esta activado (1) cualquier cambio en los pines PCI14..8 disparara una interrupcion. Los pines se enmascaran desde el registro PCMSK1. El vector de interrupcion asociado es PCINT1_vect.
* Bit PCIE2: Cuando esta activado (1) cualquier cambio en los pines PCI23..16 disparara una interrupcion.  Los pines se enmascaran desde el registro PCMSK2. El vector de interrupcion asociado es PCINT2_vect.

<p style="text-align:center"><img src="./img/pcmsk.png"/></p>

### 6.7.1. Prioridades de atencion
<table>
<tr>
    <th>Vector No.</th>
    <th>Program Address</th>
    <th>Source</th>
    <th>Interrupt Definition</th>
</tr>
<tr>
<td>4</td>
<td>0x0006</td>
<td>PCINT0</td>
<td>Pin change interrupt request 0</td>
</tr>

<td>5</td>
<td>0x0008</td>
<td>PCINT1</td>
<td>Pin change interrupt request 1</td>
</tr>

<td>6</td>
<td>0x000A</td>
<td>PCINT2</td>
<td>Pin change interrupt request 2</td>
</tr>
</table>

# 7. Timer/Counter 0
Timer/Counter0 es un modulo Timer/Counter de 8 bits de proposito general, con dos unidades de output-compare independientes, y con soporte para PWM. Permite programar tareas de forma temporizada (event management) y generación de ondas.

<p style="text-align:center"><img src="./img/timer0.png"/></p>

* **Registro TCNT0:** Registro contador que suma 1 (o resta, segun la direccion de conteo) cada vez que en su entrada hay un flanco de reloj.
* **BOTTOM:** El contador alcanza el valor BOTTOM cuando pasa a 0x00
* **MAX:** El contador alcanza el valor MAX cuando pasa a 0xFF, 255
* **TOP:** Representa el valor más alto de la secuencia de conteo, puede setearse para usar un valor fijo (MAX) o el valor almacenado en el registro **OCR0A**, dependiendo del modo de operación.
* **Clock Select:** La señal de reloj que alimenta al Timer puede provenir del *Prescaler* interno o puede provenir de una señal externa (pin T0). La unidad logica de reloj controla que fuente y que tipo de flanco se utiliza para incrementar o decrementar el valor del Timer/Counter
*  **OCR0A y OCR0B:** Registros utilizados para comparar todo el tiempo el valor del Timer/Counter. Pueden utilizarse para generar un PWM o una salida de frecuencia variable en los pines de output compare (OC0A y OC0B). El evento de Compare match (TCNT0 == OCR0x) activa la flag de comparación (OCF0A o OCF0B), la cual puede usarse para generar una interrupción temporizada.
*  **TCCR0A y TCCR0B:** Son los registros de control del timer, permiten configurar el modo de operación (Normal, CTC, Fast PWM, Phase Correct PWM), el valor de TOP (default o OCR0A), dirección de conteo, activación de flag TOV0 (overflow con bottom, max o top) y el *Prescaler*, entre otros.

## 7.1. Modos de funcionamiento

### 7.1.1. Normal
El Timer/Counter incrementa (o decrementa) el valor de TCNT0 hasta alcanzar el valor TOP (o BOTTOM). Cuando se alcanza, se reinicia el valor TCNT0 a BOTTOM (o TOP) y se levanta el flag TOV0 (overflow).

* La frecuencia de overflow puede calcularse como $f_{OVF} = \frac{f_{clkT_0}}{2^8}$

* El tiempo de overflow puede calcularse como $T_{OVF} = \frac{1}{f_{OVF}}$

* La resolución de temporización puede calcularse como $T_{clkT_0} = \frac{1}{f_{clkT_0}}$

### 7.1.2. CTC (Clear Timer on Compare Match)
El Timer/Counter incrementa (o decrementa) el valor de TCNT0 hasta alcanzar el valor OCR0. Cuando se alcanza, se reinicia el valor TCNT0 a BOTTOM (o OCR0) y se levanta el flag OC0. También puede configurarse para invertir el pulso en el pin OC0 (waveform generation).

### 7.1.3. PWM
#### 7.1.3.1. Fast PWM
#### 7.1.3.2. Phase Correct PWM


## 7.2. Prescaler
El Atmega328P cuenta con un sistema de preescalado de reloj que se utiliza para dividir la frecuencia del reloj y obtener una menor, permitiendo bajar el consumo de energía cuando el requisito de poder de procesamiento es bajo. Este sistema también puede usarse para suministrar señal de reloj a los distintos dispositivos.

El Timer/Counter puede recibir la señal de clock del reloj del sistema ($f_{CLK\_I/O}$), esto permite la velocidad de operacion más rápida. Alternativamente, puede recibir la señal de clock de una de las 4 alternativas del preescalador. Las frecuencias del preescalador son:

$$\frac{f_{CLK\_I/O}}{8}$$
$$\frac{f_{CLK\_I/O}}{64}$$
$$\frac{f_{CLK\_I/O}}{256}$$
$$\frac{f_{CLK\_I/O}}{1024}$$

El prescaler funciona independientemente de la lógica de Clock select, y es compartido por el Timer/Counter1 y el Timer/Counter0.

## 7.3. Registros para su programación

<p style="text-align:center"><img src="./img/timer0-reg.png"/></p>

# 8. MEF
> Una Máquina de Estados Finitos (MEF) es un modelo abstracto del “comportamiento” del sistema, basado en principio simples.

> Una Máquina de Estados Finitos (MEF) es un modelo matemático (Teoría general de autómatas) usado para describir el comportamiento de un sistemas que puede ser representado por un número finito de estados, un conjunto de entradas y una función de transición que determina el estado siguiente en función del estado actual y de las entradas.

El modelado de problemas usando MEFs hace más sencilla la comprensión del sistema y su funcionamiento. Desde el punto de vista del software es más sencillo de mantener ya que se pueden agregar o quitar estados sin modificar el resto, es más sencillo de depurar, verificar y optimizar.

Un modelo de MEF debe tener las entradas y las reglas bien definidas para cambiar de estado, sus transiciones se pueden especificar mediante un “diagrama de estados” o “tabla de transiciones de estados” y cada transición implica diferentes respuestas o acciones del sistema.

## 8.1. Modelo de Mealy
En el modelo de Mealy, la **salida** depende del **estado actual** y de las **entradas**. Son propensos a este modelo los sistemas donde la salida provoca el cambio de estado. Por ejemplo, en un robot, el movimiento de sus articulaciones produce el cambio de estado (parado-sentado)
<p style="text-align:center"><img src="./img/mealy.png"/></p>

## 8.2. Modelo de Moore
En el modelo de Moore, la **salida** del sistema depende solo del **estado actual**. Puede haber múltiples estados con la misma salida, pero para cada estado el significado es diferente. La salida guarda estrecha relacióon con el estado, por ejemplo un controlador de semáforo.
<p style="text-align:center"><img src="./img/moore.png"/></p>

**NOTA:** *ambos modelos son intercambiables pero es mejor optar por la forma que representa de manera más natural el problema*

## 8.3. Implementación en C
* Definir conjunto de estados
  * ``enum estados = [STATE0,STATE1,..]``
* Definir conjunto de salidas
  * ``enum salidas = [OUT0,OUT1,..]``
* Definir conjunto de entradas
  * ``enum entradas = [IN0,IN1,..]``
* Definir una función de transición de estados
  * ``tabla : [1..n][1..m]`` 
* Definir procedimiento para establecer el estado inicial
```c
Iniciar_MEF() {
    estado=STATE0;
    salida= OUT0;
}
```
* Definir procedimiento para actualizar la MEF
```c
Actualizar_MEF() {
    Leer(entradas);
    estado=table[estado][entradas];
    Actualizar_Salidas(estado,entradas);
}
```
* Definir procedimiento para ejecutar la MEF
```c
Ejecutar_MEF(){
    Iniciar_MEF();
    repetir siempre{ // <- puede ser temporizada (repetir cada S segundos)
        Actualizar_MEF();
    }
}
```
### 8.3.1. Usando switch-case
En implementaciones con switch, los case de cada estado se evaluarán secuencialmente, equivale a una cadena de if consecutivos de resolución. No tarda lo mismo en ejecutar las actualizaciones según el caso.
```c
typedef enum{S0,S1} state; //definicion y declaracion de variables de estado
state estado;

void Iniciar_MEF{ //metodo de inicialización
    estado=S0;
    Z=0; //salida
}

void ActualizarMEF(void){
    X=leerEntradas();
    switch(estado){
        Case S0:
            if(X==1){
                estado=S1; Z=1;
            }else{
                estado=S0; Z=0;
            }
        break;
        Case S1:
            if(X==1){
                estado=S0; Z=0;
            }else{
                estado=S1; Z=1;
            }
        break;
    }
}
```

### 8.3.2. Usando punteros a función
En implementaciones con punteros a función o tablas el tiempo de acceso a las funciones es el mismo independientemente del valor de la variable de estado, equivale a un desvío selectivo de la ejecución del programa. En general implementaciones con punteros o tablas de transición permiten uniformidad en el tiempo de acceso, son más compactas, pero ocupan más memoria. 

```c
typedef enum{S0,S1} state;
state estado;

void fS0(void);
void fS1(void);

void (*MEF[])(void)={fS0,fS1}; //puntero a funciones


void ActualizarMEF(void){
    X=leerEntradas();
    (*MEF[estado])(); //ejecuta la funcion correspondiente
}

void fS0(void){
    if(X==1){
        estado=S1; Z=1;
    }
    else {
        estado=S0; Z=0;
    }
}

void fS1(void){
    if(X==1){
        estado=S0; Z=0;
    }
    else {
        estado=S1; Z=1;
    }
}

```

# 9. Timer 2. RTC
La única diferencia entre el Timer0 y el Timer2 es la siguiente:

* El Timer0 puede ser alimentado por <mark>una señal de reloj externa</mark> a traves del <mark>pin T0</mark>.

* El Timer2 puede ser alimentado una señal de reloj externa <mark>asíncrona</mark> a traves de los pines <mark>TOSC1 y TOSC2</mark>. Esto quiere decir que puede ser alimentado por un <mark>cristal oscilador</mark> completamente diferente e independiente al de la CPU, de hasta 32kHZ

Una de las cosas que permite el modo asíncrono del Timer2 es la implementación de un **Real-Time-Clock**, que puede contar segundos, minutos, horas, días, meses, indistintamente de lo que este haciendo la CPU o el Oscilador principal. Esto permite que la CPU pueda entrar en modo Sleep mientras que el Timer2 continua contando y solo despierta a la CPU ante un evento de Overflow para incrementar el contador necesario

<table>
  <tr>
    <th>Timer0</th>
    <th>Timer2</th>
  </tr>
  <tr>
    <td><img src="./img/timer0.png"/></td>
    <td><img src="./img/timer2.png"/></td>
  </tr>
</table>

# 10. Watchdog Timer
El Watchdog timer es un mecanismo de protección ante fallas de software o hardware, básicamente cuenta pulsos de reloj hasta un valor programable y genera una interrupción o un reset cuando alcanza dicho valor; por lo tanto, el software debe reiniciar el contador utilizando la instrucción WDR antes que este alcance la cantidad establecida (o time out). Si por algún motivo el software no reinicia el contador a tiempo se genera una interrupción o un reset.

En modo interrupción puede utilizarse como despertador (wake-up) de un modo de bajo consumo o para limitar el máximo tiempo permitido para una operación dada.

El modo reset se utiliza para reiniciar el sistema ante bloqueos permanentes o código “colgado”

El modo combinado interrupción y reset se utiliza para “guardar el contexto crítico” ante una supuesta falla (safe shutdown). Para configurarlo y activarlo hay que seguir una secuencia segura para evitar activación ocacional.

Este timer se alimenta con un oscilador interno separado de 128kHz. Cuenta con un Prescaler que permite configurar el "*time-out*" a distintos valores (16 ms - 8.0 s)

<p style="text-align:center"><img src="./img/wdt.png"/></p>

# 11. Planificación y Ejecución de Tareas en Sistemas Embebidos

## 11.1. Super-Loop o Round Robin Cíclico
En este tipo de planificación es dificil temporizar la ejecución ya que las distintas tareas se ejecutaran unicamente después de terminar la previa, que puede tener una duración variable.
```c
/*------------------------------------------------------------------*-
Main.C
------------------------------------------------------------------
Architecture of a simple Super Loop application
-*------------------------------------------------------------------*/
#include "x.h"
#include "y.h"
#include "z.h"
/*------------------------------------------------------------------*/
void main(void){
  X_Init(); // Preparar la tarea X y las condiciones iniciales
  Y_Init(); // Preparar la tarea Y y las condiciones iniciales
  Z_Init(); // Preparar la tarea Z y las condiciones iniciales
  while(1){ // Super Loop
    X(); // Ejecutar la tarea X.
    Y(); // Ejecutar la tarea Y
    Z(); // Ejecutar la tarea Z
  }
}
```
## 11.2. Foreground/Background o Event-Driven
Cada interrupción corresponde a un evento asociado a una tarea específica (múltiples interrupciones). La ejecución de las tareas depende de que el evento ocurra.

Las tareas que se ejecutan en el super-loop se denominan tareas de background y se ejecutan en función de los eventos asociados a las interrupciones.

Las ISR para manejar los eventos asincrónicos se denominan tareas en foreground (también se pueden pensar como hilos de ejecución). Estas ISR deben ser de corta duración, generalmente activan flags o cambian variables de estado de las tareas, para determinar qué procesamiento debe hacerse para ese evento.

El comportamiento No es determinístico. La ISR cambia el flag pero la tarea se procesa cuando le toque el turno en el loop y si no hay otras interrupciones pendientes. Podría darse el caso (es probable) de tener interrupciones simultáneas con lo cual alguna deberá “esperar” a ser atendida, según la prioridad.

La modificación de una tarea de background afecta la temporización de las demás (poca flexibilidad y escalabilidad). Se deben usar funciones “no bloqueantes”.

La comunicación entre el lazo principal (Background task) y las ISR (foreground Task) debe realizarse por medio de variables globales y estas variables de comunicación se convierten en Recursos Compartidos.

Si dos o más tareas acceden simultáneamente a un recurso compartido, el código de acceso al mismo se convierte en una sección crítica de código y deben tomarse medidas por ejemplo deshabilitar las interrupciones.

Administrar los modos de bajo consumo en está arquitectura es complejo ya que debe garantizarse que la CPU ha realizado todas las operaciones de Background y foreground antes de entrar en modo sleep

```c
void main(void) {
  X_Init();
  Y_Init();
  Z_Init();
  sei(); // Globally enable interrupts
  while(1) {
    if (Flag_Z) {
      Z(); //if event Z ocurred->process event Z
      Flag_Z =0; }
    if (Flag_Y) {
      Y(); // if event Y ocurred->process event Y
      Flag_Y =0; }
    if (Flag_X) {
      X(); // if event X ocurred->process event X
      Flag_X =0; }
    }
}
```

```c
/* ------------------------ISR Event X--------------------- */
ISR ( Event_X ){
  Flag_X =1; //event X has ocurred
}
/* ------------------------ISR Event Y--------------------- */
ISR ( Event_Y ){
  Flag_Y =1; //event Y has ocurred
}
/* ------------------------ISR Event Z--------------------- */
ISR ( Event_Z ){
  Flag_Z =1; //event Z has ocurred
}
```

## 11.3. Time-triggered (disparadas por tiempo)
Estas serán tareas planificadas por una única interrupción periódica de Timer comúnmente llamada RTI (Real Time Interrupt). La RTI es la única “base de tiempo” del sistema para temporizar una o más tareas y el manejo de los eventos asincrónicos de los periféricos se realiza exclusivamente por encuesta (polling) periódica.

Cada vez que ocurre la interrupción es como una marca de tiempo o Tick del sistema, que permite planificar que tarea corresponde ejecutar. Cuando la CPU no tenga que ejecutar tareas (zona IDLE) podemos poner el MCU en bajo consumo (SLEEP) hasta el próximo tick y ahorrar energía.

## 11.4. Resumen
<table>
  <tr>
    <th>Super Loop</th>
    <th>Background/Foreground</th>
    <th>Time-Triggered</th>
  </tr>

  <tr>
    <td>
      <ul>
        <li>Simple</li>
        <li>Control x polling</li>
        <li>Sin interrupciones</li>
        <li>Temporización por retardos bloqueantes</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Las tareas se ejecutan en respuestas a eventos asincrónicos (múltiples interrupciones)</li>
        <li>Difícil de predecir para todas las circunstancias</li>
        <li>Problemas de recursos compartidos (secciones críticas)</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Única interrupción RTI</li>
        <li>Los periféricos se utilizan por polling periódico</li>
        <li>Cooperativo</li>
        <li>Más confiable para aplicaciones de tiempo real y críticas porque es predecible</li>
      </ul>
    </td>  
  </tr>
</table>

# 12. RTOS (Real Time Operative System)
Un sistema operativo de tiempo real es un sistema operativo que provee respuestas a determinados eventos con un “tiempo de respuesta acotado”.

Típicamente, las tareas tienen plazos (deadlines) que son valores de tiempo físico en los cuales se debe completar. Más generalmente, los programas en tiempo real pueden tener todo tipo de restricciones de tiempo, no solo deadlines por ejemplo, puede requerirse que una tarea se ejecute **no antes** de un momento determinado o puede requerirse que se ejecute **no más de una cantidad de tiempo después** de que se ejecute otra tarea, o se le puede solicitar que se ejecute **periódicamente** con un período específico. Las tareas pueden ser dependientes unas de otras y pueden actuar cooperativamente o pueden ser independientes (excepto que todas comparten los recursos del MCU).

En un contexto multitareas donde hay más tareas que CPU o tareas que deben ejecutarse en un tiempo preciso es necesaria la planificación de tareas (**Task scheduling**).

## 12.1. Scheduler
Un planificador (Scheduler) decide cual es la siguiente tarea a ejecutar en el instante de tiempo que la CPU se libera. El planificador puede ser:

* Estatico: Se decide el orden y tiempo de ejecución en el diseño.
* Dinámico: Se decide que tarea ejecutar en tiempo de ejecución.
  
* Preemptive: Puede tomar la decisión de detener la ejecución de una tarea y comenzar la ejecución de otra, aún cuando la anterior no haya finalizado.
* Non-preemptive: Permite a las tareas ejecutarse hasta terminar (run to completion) antes de asignar tiempo de CPU a otra tarea.

El planificador puede utilizar la prioridad de una tarea para decidir cuando corresponde su ejecución. Las tareas pueden tener prioridades fijas o pueden alterarse durante la ejecución de programa.

Un **preemptive priority-based scheduler** siempre ejecuta la tarea habilitada de mayor prioridad mientras que un **non-preemptive priority-based** scheduler usa la prioridad para decidir que tarea corresponde ejecutar luego de que la tarea actual finalice su ejecución y nunca interrumpe la ejecución de una tarea por otra.

## 12.2. Modelo de tarea

* Release time: o también tiempo de despacho, es el tiempo a partir del cual la tarea está habilitada para ejecutarse
* Start time: inicio de la ejecución
* Preemption time: la tarea fue suspendida para ejecutar otra
* Resumption time: la tarea fue reanudada
* Finish time: la tarea finalizó su ejecución
* Deadline: es la restricción de tiempo en el cual la tarea debe completarse. Muchas veces esta limitación proviene de las restricciones físicas impuestas por la aplicación y su no cumplimiento pude ser considerado una falla (en los llamados *hard rtos*) o una degradación de performance (*soft rtos*)
* Response time: es el tiempo de respuesta y se mide desde la habilitación de la tarea hasta la finalización de la misma
* Execution time: es el tiempo que la tarea ha usado la CPU (no tiene en cuenta el tiempo apropiado). Se puede asumir conocido y fijo o con su cota más pesimista WCET (Worst Case Execution time)

<p style="text-align:center"><img src="./img/rtos-task.png"/></p>

## 12.3. Componentes de un RTOS simple
* Un planificador de tareas (scheduler) que permite decidir que tarea corresponde ejecutar en base a la temporización basado en una RTI.
* Un despachador de tareas (dispacher) que permita ejecutar las tareas planificadas con distintas prioridades.
* El RTOS y las tareas de aplicación del usuario son parte del mismo proyecto. **No** es una aplicación independiente, pero sí es un módulo portable.

# 13. Timer 1
El Timer/Counter Timer1 es una unidad de 16-bit que permite event management, wave generation y **signal timing measurement**

<p style="text-align:center"><img src="./img/timer1.png"/></p>

A diferencia de Timer0 y Timer2, en Timer1 los registros *contador* TCNT1*, *output compare* OCR1A/B e *input capture* ICR1 son todos de **16 bits**

a) Describa el funcionamiento y los registros del módulo Timer1. Realice un diagrama en bloques del mismo.
b) Explique cuáles son los posibles modos de funcionamiento.
c) Explique los modos de funcionamiento “Output Compare” de cada canal.
d) Describa un método para generar una señal digital de frecuencia o periodo programable. Analice la resolución
y el rango obtenido en función de los parámetros de configuración.
e) Explique el funcionamiento del modo “Input Capture”.
f) ¿Cómo lo utilizaría para medir el ancho de un pulso? ¿Cómo lo utilizaría para medir la frecuencia o período
de una señal periódica? De un ejemplo de uso. En ambos casos, defina y analice la resolución y el rango de
medida.
g) El sensor de temperatura MAX6577 convierte la temperatura ambiente en una señal digital cuya frecuencia
es proporcional a la temperatura en °C. Investigue la hoja de datos de este dispositivo y diga si es posible utilizar
el Timer1 para medir la temperatura de un ambiente.
## 13.1. Input Capture

## 13.2. Output Compare

# 14. Generacion y distribucion de reloj
a) Explique cuáles son las posibles fuentes de reloj y sus rangos de frecuencia para que funcione el MCU.
b) Explique cómo se distribuyen internamente las señales de reloj para la CPU y los distintos periféricos
según las diferentes opciones (diagrama en bloques de la distribución interna de las señales de reloj).
c) Investigue sobre cómo utilizar la biblioteca de funciones de bajo consumo (sleep.h).
d) Explique
 cuál es la configuración del reloj del sistema dispuesta desde fábrica y que tolerancia tiene la
frecuencia del mismo

# 15. USART
a) Describa las características principales de una comunicación serie asincrónica.
b) Explique cómo funcionan los tres subsistemas principales del módulo UART del Atmega: el generador de
tasa de transmisión (baud rate), el transmisor y el receptor serie. Explique la funcionalidad de los registros
correspondientes.
c) Si se tiene una frecuencia de CLK = 8MHz, encuentre el valor de configuración para obtener tasas de
transferencia de 1200, 2400, 4800, 9600, 19200 y 38400 bps. Determine el error resultante (en %) cometido en
la aproximación respecto a los valores ideales.
d) ¿Cuál es el error máximo respecto al baud rate estándar, que puede aceptarse en una comunicación serie
asincrónica con formato 8N1 para que la comunicación sea confiable?

# 16. Arquitectura Background/Foreground
a) Explique las características más importantes de la arquitectura de software Background / Foreground (eventtriggered).
b) Investigue sobre cómo realizar una implementación de bajo consumo utilizando este tipo de arquitectura de
software. Ayuda: descargue el artículo fore_back_MCU.pdf del aula virtual.
c) Compare la arquitectura Background / Foreground con la utilizada en el TP2. Exponga ventajas y
desventajas.
d) Realice una implementación en pseudocódigo del modelo productor-consumidor para el Receptor y
Transmisor del periférico UART

# 17. Drivers. Modelo Productor/Consumidor.

# 18. Protocolo SPI. I2C
a) Describa cuales son las características principales de una comunicación serie sincrónica SPI. Muestre como
interconectar el microcontrolador con varios dispositivos esclavos genéricos.
b) Explique cómo funcionan el módulo SPI del Atmega. Describa la funcionalidad de los registros
correspondientes.
c) Analice la hoja de datos del DS1302 y explique cómo conectarlo, es decir cual terminal del MCU corresponde
conectar con cual terminal del dispositivo externo.
d) Explique cuáles son las características principales de una comunicación serie sincrónica I2C y como se utiliza
para conectar múltiples dispositivos.
e) Analice la hoja de datos del DS3231 y explique cómo conectarlo a la interfaz TWI (I2C) del microntrolador
Atmega.

# 19. PWM