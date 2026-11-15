# **ProgrammingC**

Proyectos de practica para aprender C siguiendo el libro **El lenguaje de programacion C** de Brian W. Kernighan y Dennis M. Ritchie (K&R). Cada proyecto toma los ejercicios de un capitulo y los lleva a una herramienta real de linea de comandos.

## **Distribucion de los proyectos**

### **Capitulo 1:** *Introduccion general*

| # | Proyecto | Programa | Ejercicios de K&R | Estado |
|---|---|---|---|---|
| 1 | [Analizador lexico y contador con diagnostico](1.%20Analizador%20lexico%20y%20contador%20con%20diagnostico/consigna.md) | `uniwc` | 1-8, 1-11, 1-16 | Resuelto |
| 2 | [Normalizador de fuentes y expansor de tabulaciones](2.%20Normalizador%20de%20fuentes%20y%20expansor%20de%20tabulaciones/consigna.md) | `detab_fmt` | 1-18, 1-20, 1-22 | Resuelto |
| 3 | [Eliminador de comentarios y validador de sintaxis basica](3.%20Eliminador%20de%20comentarios%20y%20validador%20de%20sintaxis%20basica/consigna.md) | `miniclean` | 1-23, 1-24 | Resuelto |
| 4 | [Calculadora RPN con diagnostico de errores](4.%20Calculadora%20RPN%20con%20diagnostico%20de%20errores/consigna.md) | `rpncalc` | 1-7, 1-16 (ampliados) | Pendiente |
| 5 | [Frecuencia de palabras con histogramas](5.%20Contador%20de%20frecuencia%20de%20palabras%20con%20histogramas/consigna.md) | `wordfreq` | 1-13, 1-14 (ampliados) | Pendiente |

### **Capitulo 2:** *Tipos, operadores y expresiones*

| # | Proyecto | Programa | Que hace | Ejercicios de K&R | Estado |
|---|---|---|---|---|---|
| 1 | Explorador de tipos y limites | `typeinfo` | Calcula los rangos de `char`, `short`, `int` y `long` (con y sin signo) operando con bits, y los compara con `<limits.h>` | 2-1 | Pendiente |
| 2 | Conversor de bases con deteccion de desborde | `baseconv` | Convierte numeros entre decimal, hexadecimal, octal y binario leidos de *stdin*, avisando cuando no entran en el tipo | 2-3 | Pendiente |
| 3 | Laboratorio de bits | `bitlab` | Implementa `setbits`, `invert`, `rightrot` y `bitcount` y muestra cada operacion en binario, bit por bit | 2-6, 2-7, 2-8, 2-9 | Pendiente |
| 4 | Filtro de conjuntos de caracteres | `squeeze` | Elimina de la entrada todos los caracteres de un conjunto y busca la primera aparicion de cualquiera de ellos | 2-2, 2-4, 2-5 | Pendiente |
| 5 | Codificador XOR/ROT13 con checksum | `xorsum` | Codifica y decodifica texto con XOR y ROT13 y calcula un checksum para verificar que el archivo no cambio | 2-10 | Pendiente |

### **Capitulo 3:** *Control de flujo*

| # | Proyecto | Programa | Que hace | Ejercicios de K&R | Estado |
|---|---|---|---|---|---|
| 1 | Busqueda binaria con medicion | `binsearch` | Compara dos versiones de busqueda binaria contando cuantas comparaciones hace cada una | 3-1 | Pendiente |
| 2 | Escapador y desescapador de cadenas | `escape` | Convierte caracteres invisibles en secuencias `\n`, `\t`, etc. y viceversa, usando `switch` | 3-2 | Pendiente |
| 3 | Expansor de rangos | `expand` | Convierte abreviaturas como `a-z0-9` en la lista completa, con todos los casos borde (`-a`, `a-`, `a-b-c`) | 3-3 | Pendiente |
| 4 | Formateador de numeros | `numfmt` | Convierte enteros a texto en cualquier base y con ancho minimo, incluyendo el caso del entero mas negativo | 3-4, 3-5, 3-6 | Pendiente |
| 5 | Comparador de algoritmos de ordenamiento | `sortbench` | Ordena con Shell sort y con insercion, y compara cuantos intercambios y comparaciones hace cada uno | Seccion 3.5 | Pendiente |

### **Capitulo 4:** *Funciones y la estructura del programa*

| # | Proyecto | Programa | Que hace | Ejercicios de K&R | Estado |
|---|---|---|---|---|---|
| 1 | Calculadora RPN extendida y en varios archivos | `rpncalc2` | Evolucion del proyecto 1.4: modulo, comandos de pila (`dup`, `swap`, `clear`), funciones matematicas, variables y `getch`/`ungetch`, separada en varios `.c` y un `.h` | 4-3 a 4-10 | Pendiente |
| 2 | Buscador de patrones | `minigrep` | Imprime las lineas que contienen un patron, con numero de linea, y la posicion de la ultima aparicion | 4-1 | Pendiente |
| 3 | Conversor de notacion cientifica | `atofx` | Convierte texto a `double` aceptando notacion cientifica (`1.5e-3`) y rechazando entradas invalidas | 4-2 | Pendiente |
| 4 | Laboratorio de recursion | `reclab` | `itoa` y `reverse` recursivos y Quicksort, mostrando la profundidad de cada llamada | 4-12, 4-13, seccion 4.10 | Pendiente |
| 5 | Modulos con `static` y macros | `modstack` | Una pila y una cola en archivos separados que ocultan sus datos con `static`, mas macros como `swap(t,x,y)` | 4-11, 4-14 | Pendiente |

### **Capitulo 5:** *Apuntadores y arreglos*

| # | Proyecto | Programa | Que hace | Ejercicios de K&R | Estado |
|---|---|---|---|---|---|
| 1 | Biblioteca de cadenas con punteros | `mystring` | Reescribe `strcat`, `strncpy`, `strncmp`, `strend` y otras usando solo punteros, con pruebas automaticas | 5-3 a 5-6 | Pendiente |
| 2 | Ultimas lineas de un archivo | `tail` | Imprime las ultimas *n* lineas de la entrada (`-n`), guardandolas de forma eficiente | 5-13 | Pendiente |
| 3 | Ordenador de lineas con opciones | `sort` | Ordena lineas con opciones `-n`, `-r`, `-f`, `-d` y por campos, usando punteros a funciones | 5-14 a 5-17 | Pendiente |
| 4 | Evaluador RPN desde la linea de comandos | `expr` | Evalua expresiones pasadas como argumentos (`expr 2 3 4 + '*'`) con `argc` y `argv` | 5-10 | Pendiente |
| 5 | Traductor de declaraciones de C | `dcl` | Traduce declaraciones como `char (*(*x())[])()` a palabras y viceversa | 5-18, 5-19, 5-20 | Pendiente |

### **Capitulo 6:** *Estructuras*

| # | Proyecto | Programa | Que hace | Ejercicios de K&R | Estado |
|---|---|---|---|---|---|
| 1 | Frecuencia de palabras con arbol binario | `wordfreq2` | Evolucion del proyecto 1.5: sin limites fijos, con un arbol binario y memoria dinamica, ordenado por frecuencia | 6-4 | Pendiente |
| 2 | Referencias cruzadas | `xref` | Lista cada palabra de un documento con todos los numeros de linea donde aparece, ignorando palabras comunes | 6-3 | Pendiente |
| 3 | Agrupador de identificadores | `varnames` | Agrupa los nombres de variables de un programa C que comparten sus primeros *n* caracteres | 6-2 | Pendiente |
| 4 | Contador de palabras clave de C | `keycount` | Cuenta las palabras clave de un fuente C ignorando strings, comentarios y directivas (reutiliza ideas del proyecto 1.3) | 6-1, seccion 6.3 | Pendiente |
| 5 | Mini preprocesador | `minicpp` | Procesa `#define` y `#undef` simples con una tabla hash y reemplaza las macros en el codigo | 6-5, 6-6 | Pendiente |

### **Capitulo 7:** *Entrada y salida*

| # | Proyecto | Programa | Que hace | Ejercicios de K&R | Estado |
|---|---|---|---|---|---|
| 1 | Mini `printf` y `scanf` | `minio` | Implementa versiones propias de `printf` y `scanf` con argumentos variables (`<stdarg.h>`) | 7-3, 7-4 | Pendiente |
| 2 | Visor hexadecimal | `hexdump` | Muestra cualquier archivo, incluso binario, en hexadecimal y ASCII; ademas cambia mayusculas o minusculas segun el nombre del programa | 7-1, 7-2 | Pendiente |
| 3 | Comparador de archivos | `minidiff` | Compara dos archivos e imprime la primera linea donde difieren, con su numero | 7-6 | Pendiente |
| 4 | Buscador en varios archivos | `find` | Busca un patron en una lista de archivos e indica en que archivo y linea esta cada coincidencia | 7-7 | Pendiente |
| 5 | Paginador para imprimir | `pr` | Imprime varios archivos con encabezado, numero de pagina y salto de pagina al cambiar de archivo | 7-8 | Pendiente |

### **Capitulo 8:** *La interfaz del sistema UNIX*

| # | Proyecto | Programa | Que hace | Ejercicios de K&R | Estado |
|---|---|---|---|---|---|
| 1 | `cat` con llamadas al sistema | `mycat` | Concatena archivos usando directamente `open`, `read`, `write` y `close`, y compara su velocidad con la version de `stdio` | 8-1 | Pendiente |
| 2 | Biblioteca de E/S propia | `mystdio` | Implementa `fopen`, `getc`, `putc`, `fflush`, `fclose` y `fseek` sobre las llamadas al sistema | 8-2, 8-3, 8-4 | Pendiente |
| 3 | Listador de archivos | `fsize` | Recorre directorios y muestra tamano, fechas y tipo de cada archivo | 8-5 | Pendiente |
| 4 | Asignador de memoria | `mymalloc` | Implementa `malloc`, `free`, `calloc` y `bfree` con lista libre, con verificaciones de errores | 8-6, 8-7, 8-8 | Pendiente |
| 5 | Proyecto final integrador | `textindex` | Indexador de palabras de varios archivos de texto que usa tu propio `mystdio` y tu propio `mymalloc` | Integra todo el libro | Pendiente |

> El capitulo 8 usa llamadas al sistema de UNIX. En Windows, MinGW trae `open`, `read` y `write` (en `<io.h>` y `<fcntl.h>`), pero lo mas comodo es hacerlo en WSL (Linux dentro de Windows).

## **Estructura de cada carpeta**

A partir del capitulo 2, cada capitulo tiene su propia carpeta:

```
Capitulo N/
└── M. Nombre del proyecto/
    ├── consigna.md
    └── ...
```

Dentro de cada proyecto:

```
N. Nombre del proyecto/
├── consigna.md       ← que hay que resolver y resultado esperado
├── input_test.txt    ← archivo de prueba (en algunos proyectos, test_dirty.c)
├── programa.c        ← la solucion
└── programa.exe      ← el ejecutable compilado
```

## **Regla: solo lo visto hasta ese capitulo**

Solo se usan herramientas vistas en el capitulo 1: `getchar`, `putchar`, `printf`, `while`, `for`, `if / else if / else`, arreglos de `int` y `char`, funciones propias, variables externas y constantes con `#define`. Solo `#include <stdio.h>`.

No se usan: `%`, `switch`, `do-while`, `break`, `continue`, punteros, `struct`, arreglos de dos dimensiones, `+=` y similares, ni `<string.h>`, `<ctype.h>` o `<stdlib.h>`. Las excepciones puntuales estan marcadas con un comentario en el codigo.

La misma regla vale para el resto del libro, de forma acumulativa: un proyecto del capitulo N puede usar todo lo de los capitulos 1 a N, y nada de los siguientes. Por ejemplo, los punteros recien se pueden usar desde el capitulo 5, y `struct` desde el capitulo 6.

## **Compilar y ejecutar**

Todos los programas leen de la entrada estandar (*stdin*) y escriben en la salida estandar (*stdout*). Se compilan en modo estricto C89, el estandar del libro:

```powershell
gcc -Wall -Wextra -pedantic -std=c89 programa.c -o programa.exe
Get-Content input_test.txt -Raw | .\programa.exe
```

### **Ojo con PowerShell 5.1**

El operador `>` de Windows PowerShell 5.1 guarda los archivos en UTF-16, y gcc no puede compilarlos. Para guardar la salida de un programa en un archivo, usar:

```powershell
Get-Content entrada.txt -Raw | .\programa.exe | Set-Content -Encoding Ascii salida.txt
```

o hacer la redireccion con `cmd`:

```powershell
cmd /c "programa.exe < entrada.txt > salida.txt"
```

En PowerShell 7 (`pwsh`) el problema no existe.
