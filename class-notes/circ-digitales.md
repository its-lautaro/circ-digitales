# Lenguaje C
## Modificadores de acceso
### Static
In the C programming language, static is used with global variables and functions to set their scope to the containing file. In local variables, static is used to store the variable in the statically allocated memory instead of the automatically allocated memory. While the language does not dictate the implementation of either type of memory, statically allocated memory is typically reserved in the data segment of the program at compile time, while the automatically allocated memory is normally implemented as a transient call stack.
### Const
The qualifier const can be applied to the declaration of any variable to specify that its value will not be changed (Which depends upon where const variables are stored, we may change the value of const variable by using pointer).
### Volatile
The volatile keyword is intended to prevent the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler. Their values can be changed by code outside the scope of current code at any time. The system always reads the current value of a volatile object from the memory location rather than keeping its value in temporary register at the point it is requested, even if a previous instruction asked for a value from the same object.
**Use cases:**
* Global variables modified by an interrupt service routine outside the scope
* Global variables within a multi-threaded application
### Register
Registers are faster than memory to access, so the variables which are most frequently used in a C program can be put in registers using register keyword. The keyword register
hints to compiler that a given variable can be put in a register. It’s compiler’s choice to put it in a register or not. Generally, compilers themselves do optimizations and put the variables in register.
## Preprocesador
The C preprocessor, often known as cpp, is a macro processor that is used automatically by the C compiler to transform your program before compilation. It is a text substitution tool. Las directivas para el preprocesador comienzan con el simbolo #.
### Directivas
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

## Caracteres
* Character Constant: constante que representa un valor perteneciente al conjunto de caracteres. Se indica entre comillas simples 'a'.
* Character array: C language does not support strings as a data type, instead they are handled as a one-dimensional array of characters.
### String Handling Functions
C supports a large number of string handling functions that can be used to carry out many of the string manipulations. These functions are packaged in the string.h library.
* strcat(dest,src) concatenates two strings
* strlen(str) show the length of a string
* strrev(str) reverse a string
* strcpy(dest,src) copies one string into another
* strcmp(a,b) compares two strings

## Alcance de variables
In C programming language, variables defined within some function are known as **Local Variables** and variables which are defined outside of function block and are accessible
to entire program are known as **Global Variables**.

## Operadores Logicos
* & -> binary AND
* | -> binary OR
* ^ -> binary XOR
* ~ -> Complemento 1 (invierte los bits)
* << -> binary left shift
* \>> -> binary right shift

**Nota:** La diferencia entre el AND binario (&) y el AND lógico (&&) es que el primero es una operacion que se realiza a nivel de bit.

## Prototipos de funciones
A prototype declares the function name, its parameters, and its return type to the rest of the program prior to the function's actual declaration. Many C compilers do not check for parameter matching either in type or count. You can waste an enormous amount of time debugging code in which you are simply passing one too many or too few parameters by
mistake. **The prototype causes the compiler to check for parameters and flag an error for mismatches on count or type.** Prototypes should be placed at the beginning of your program.

## Punteros y arreglos
Every variable is a memory location, and every memory location has its address defined which can be accessed using ampersand (&) operator, which denotes an address in memory.
```
int main(){
    int var1;
    int var2[10];

    printf("address of var1 %x",&var1);
    printf("address of var2 %x",&var2);

    return 0;
}
```  
**A pointer is a variable whose value is the address of another variable.** Like any variable or constant, you must declare a pointer before using it to store any variable address.
```
int *ip; //pointer to an integer
char str[10]; //pointer to the first element of str array

int num;

ip= &num; //puntero a num

printf(ip); //imprimir direccion de num
printf(*ip); //imprimir contenido de num
```

## Structs
A structure is another *user defined data* type available in C that **allows combining data items of different kinds**. Structures are used to represent a record.
```
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

## Unions
A union is a special data type available in C that allows to store different data types in the same memory location. You can define a union with many members, but only one member can contain a value at any given time. Unions provide an efficient way of using the same memory location for multiple-purpose. To define a union, you must use the union statement in the same way as you did while defining a structure. The union statement defines a new data type with more than one member for your program.
```
union Data{
    int i;
    float f;
    char str[20];
}data;
```
Now, a variable of Data type can store an integer, a floating-point number, or a string of characters. **It means a single variable, i.e., same memory location, can be used to store multiple types of data**. You can use any built-in or user defined data types inside a union based on your requirement. 

**The memory occupied by a union will be large enough to hold the largest member of the union.**

# Familia de microcontroladores AVR
## Comparativa
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

## Arquitectura AVR (Atmega328P)
### CPU
* RISC: 131 instrucciones de 1 ciclo de reloj (o la mayoría)
* Hardvard: Memoria de programa y memoria de datos con buses independientes
* Basada en registros: 32 de 8 bits.

<img src="img/cpu.png" />

# Programación de Entrada/Salida
Para controlar los puertos de entrada salida se utilizan los registros:
* DDRn: *Port n Data Direction Register*, define para cada pin su dirección (input/output)
* * **1 is output, 0 is input**
* PORTn: *Port n Data Register* registro usado para setear el estado de los pines del *puerto n*
* PINn: *Port n Input Pin Address*, se utiliza para leer el estado los pines de del *puerto n*, es un registro de solo lectura.
## Funciones de avr libc para evaluar pines
* *PINC & (1<<PINC1)* **-->** bit_is_set (PINC, PINC1)
* *!(PINB & (1<<PINB2))* **-->** bit_is_clear (PINB, PINB2)
* *while( !(ADCSRA & (1<<ADIF)));* **-->** loop_until_bit_is_set (ADCSRA, ADIF);
* *while( ADCSRA & (1<<ADIF) ));* **-->** loop_until_bit_is_clear (ADCSRA, ADIF);
  
# Interrupciones
a) Explique cuál es la secuencia de pasos que realiza el MCU cuando recibe una señal de pedido de
interrupción. ¿cómo se retorna a la ejecución normal del programa?
b) Explique para qué sirve el bit I que se encuentra en el SREG. ¿Cuál es el valor por defecto luego del
RESET? ¿Cuáles son las instrucciones que permiten modificarlo?
c) Explique que es un RESET, las distintas maneras por las que puede generarse y la función del registro
MCU Status Register.
d) Explique qué es la latencia de una interrupción y cuáles son los valores mínimos que puede tomar medida
en ciclos de reloj.
e) Explique qué entiende por interrupciones anidadas. ¿Es posible por defecto?
f) Investigue sobre la configuración y el uso de los terminales de interrupción Externa (INTx). ¿Cuál es la
diferencia entre configurar la interrupción por flanco o por nivel?
g) Interrupciones desde los puertos de Entrada/Salida (PIN Change Interrupts).
 Describa que terminales I/O pueden generar interrupciones por cambio de estado
 Investigue como se configuran estas interrupciones en los puertos de Entrada/Salida
 Describa cuales son los vectores de interrupción asociados y sus prioridades relativas.
 Comente las diferencias más importantes con las interrupciones del punto f).

# Timer 0
a) Describa los componentes principales del módulo TIMER0 y explique sus modos de funcionamiento.
b) Explique cómo funciona el prescalador (Prescaler) y obtenga una expresión para calcular la frecuencia de
reloj del contador (CLKTn) y la frecuencia de desborde (Overflow) en función de las distintas opciones de fuentes
de reloj. ¿Cómo se borra la bandera de desborde?
c) Si se tiene una frecuencia de CLKIO de 8MHz, establezca con que valores debería inicializar los registros
pertinentes del TIMER0 para realizar un retardo de 1ms. ¿es posible generar un retardo de 1000 ms?
d) Si se tiene una frecuencia de CLKIO de 8MHz, configure TIMER0 para generar una interrupción periódica
de 1ms

# RTC
a) Describa los componentes principales del módulo TIMER0 y explique sus modos de funcionamiento.
b) Explique cómo funciona el prescalador (Prescaler) y obtenga una expresión para calcular la frecuencia de
reloj del contador (CLKTn) y la frecuencia de desborde (Overflow) en función de las distintas opciones de fuentes
de reloj. ¿Cómo se borra la bandera de desborde?
c) Si se tiene una frecuencia de CLKIO de 8MHz, establezca con que valores debería inicializar los registros
pertinentes del TIMER0 para realizar un retardo de 1ms. ¿es posible generar un retardo de 1000 ms?
d) Si se tiene una frecuencia de CLKIO de 8MHz, configure TIMER0 para generar una interrupción periódica
de 1ms

# MEF
¿Qué es un modelo de Estados Finitos? ¿Qué elementos contiene? ¿Cómo se especifica?
b) ¿Cuál es la diferencia entre el modelo propuesto por Moore y el de Mealy?
c) Describa diferentes maneras para implementar en C un modelo MEF, ¿Cómo conviene declarar las
variables de estados? De un ejemplo resumido del código para una posible implementación.
d) ¿Cómo se inicializa una MEF? ¿Cómo se actualiza una MEF?
e) Analice diferencias y similitudes de una implementación MEF en lenguaje C y en lenguaje VHDL partiendo
del mismo modelo de la MEF.

# Planificacion de tareas
a) Explique en qué consiste un esquema de planificación cooperativo con interrupción periódica de timer.
b) Determine el periodo de la interrupción para la planificación de tres tareas periódicas x(), y(), z() con
períodos 10, 25 y 50ms respectivamente. ¿Qué condiciones tiene que asumir para que el funcionamiento del
sistema esté garantizado y sea confiable?
c) Explique mediante pseudocódigo como implementar el planificador y despachador de las tareas y muestre
con un diagrama temporal un ejemplo de la ejecución de las mismas.
d) En el caso de que haya superposición de tareas en el mismo tick de sistema, explique cómo puede hacerse
la planificación del inciso b) para que no haya superposición en la ejecución de x(), y(), z().
e) Explique qué entiende por modularización de software y qué ventajas tiene.
f) Explique la manera de modularizar archivos en C a partir del concepto de clases tomado de la P.O.O.
g) Explique cómo se emplea el modificador static con las funciones, variables y constantes para
modularizar un programa en C.
h) Explique que son las funciones privadas y las funciones públicas de un módulo, de un ejemplo de
implementación de cada una

# Generacion y distribucion de reloj
a) Explique cuáles son las posibles fuentes de reloj y sus rangos de frecuencia para que funcione el MCU.
b) Explique cómo se distribuyen internamente las señales de reloj para la CPU y los distintos periféricos
según las diferentes opciones (diagrama en bloques de la distribución interna de las señales de reloj).
c) Investigue sobre cómo utilizar la biblioteca de funciones de bajo consumo (sleep.h).
d) Explique cuál es la configuración del reloj del sistema dispuesta desde fábrica y que tolerancia tiene la
frecuencia del mismo

# UART
a) Describa las características principales de una comunicación serie asincrónica.
b) Explique cómo funcionan los tres subsistemas principales del módulo UART del Atmega: el generador de
tasa de transmisión (baud rate), el transmisor y el receptor serie. Explique la funcionalidad de los registros
correspondientes.
c) Si se tiene una frecuencia de CLK = 8MHz, encuentre el valor de configuración para obtener tasas de
transferencia de 1200, 2400, 4800, 9600, 19200 y 38400 bps. Determine el error resultante (en %) cometido en
la aproximación respecto a los valores ideales.
d) ¿Cuál es el error máximo respecto al baud rate estándar, que puede aceptarse en una comunicación serie
asincrónica con formato 8N1 para que la comunicación sea confiable?

# Timer 1
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

# Background Foreground
a) Explique las características más importantes de la arquitectura de software Background / Foreground (eventtriggered).
b) Investigue sobre cómo realizar una implementación de bajo consumo utilizando este tipo de arquitectura de
software. Ayuda: descargue el artículo fore_back_MCU.pdf del aula virtual.
c) Compare la arquitectura Background / Foreground con la utilizada en el TP2. Exponga ventajas y
desventajas.
d) Realice una implementación en pseudocódigo del modelo productor-consumidor para el Receptor y
Transmisor del periférico UART

# SPI I2C
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