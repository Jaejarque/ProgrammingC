# **Proyecto 5:** *wordfreq (Frecuencia de palabras con histogramas horizontal y vertical)*

K&R pide en los ejercicios 1-13 y 1-14 histogramas de largos de palabra y de frecuencia de caracteres. Este proyecto los lleva más lejos: contar **cuántas veces aparece cada palabra distinta**, lo que obliga a guardar palabras sin tener arreglos de dos dimensiones ni punteros.

- **Objetivo:** Leer un texto por *stdin*, contar la frecuencia de cada palabra distinta y emitir un resumen, un ranking con histograma horizontal y un histograma vertical de largos de palabra.
- **Qué debe resolver:**
    - 1. **Qué es una palabra:** una secuencia de letras `a-z` o `A-Z`. Todo lo demás (espacios, signos, números, saltos de línea) separa palabras. Las mayúsculas se convierten a minúsculas, así que `GATOS` y `gatos` son la misma palabra. Para convertir, usá la misma idea que `c - '0'` de K&R 1.6, pero con letras.
    - 2. **Guardar palabras sin arreglos 2D:** Todas las palabras distintas se guardan una detrás de otra en un solo arreglo grande `char texto[MAX_TEXTO]`, cada una terminada en `'\0'`. En arreglos paralelos `int inicio[MAX_PALABRAS]` e `int cuenta[MAX_PALABRAS]` guardás, para cada palabra, en qué posición de `texto` empieza y cuántas veces apareció. Por ejemplo, después de leer `el gato el`:
        ```
        texto:  e l \0 g a t o \0
        inicio: 0, 3
        cuenta: 2, 1
        ```
    - 3. **Buscar si una palabra ya existe:** Escribí una función que compare carácter por carácter la palabra recién leída con una palabra guardada en `texto` (sin `strcmp`).
    - 4. **Límites:** `#define MAX_PALABRA 40`, `#define MAX_PALABRAS 500` y `#define MAX_TEXTO 10000`. Una palabra más larga que `MAX_PALABRA` se guarda truncada. Si no queda lugar para una palabra nueva, no se guarda pero se cuenta como "sin lugar". Al final se informa cuántas palabras se truncaron y cuántas quedaron sin lugar (solo si hubo alguna). El programa nunca puede escribir fuera de un arreglo.
    - 5. **Resumen:** palabras totales, palabras distintas y la palabra más larga con su cantidad de letras. Si hay empate en el largo, gana la que apareció primero.
    - 6. **Top 10 con histograma horizontal:** Las 10 palabras más frecuentes, de mayor a menor. Si hay empate, va primero la que apareció primero en el texto. Cada línea lleva:
        - la posición con `%2d.` y un espacio,
        - la palabra, completada con espacios hasta ocupar 15 columnas (hacelo con un ciclo de `putchar(' ')`, no con formatos especiales de `printf`),
        - la cantidad con `%3d` y un espacio,
        - una barra de `*` cuyo largo es `cuenta * 40 / maximo` (división entera), con un mínimo de 1 asterisco.
    - 7. **Histograma vertical de largos:** Cuántas palabras (contando repeticiones) tienen 1, 2, …, 11 letras, y la última columna `12+` para 12 o más. Cada columna ocupa 4 caracteres y el `*` va en la cuarta posición. Si la columna más alta pasa de `#define MAX_ALTO 10`, todas se escalan: `altura = cantidad * MAX_ALTO / maximo`. Debajo va una línea de 48 guiones, la fila de etiquetas y la fila de cantidades reales.
- **Por qué es valioso:** Es la forma en que se implementan las tablas de símbolos de un compilador con memoria fija: un buffer plano de texto con índices. Te obliga a pensar en posiciones dentro de un arreglo, que es exactamente la idea que después el capítulo 5 formaliza con punteros.

## **Reglas: solo herramientas del capítulo 1**

| Permitido | Sección de K&R |
|---|---|
| `getchar`, `putchar`, `printf` (`%d`, `%3d`, `%f`, `%.2f`, `%c`, `%s`) | 1.1 – 1.5 |
| Variables `int`, `float`, `char` y constantes con `#define` | 1.2, 1.4 |
| `while`, `for`, `if`, `else if`, `else` | 1.2, 1.3, 1.5, 1.6 |
| Operadores `+ - * /`, `== != < > <= >=`, `&&`, `\|\|`, `++`, `--` | 1.2 – 1.6 |
| Dígitos como números con `c - '0'` | 1.6 |
| Arreglos de `int` y de `char`, cadenas terminadas en `'\0'` | 1.6, 1.9 |
| Funciones propias, parámetros por valor, arreglos como parámetro, `return` | 1.7 – 1.9 |
| Variables externas (globales) | 1.10 |

**No permitido:** `%`, `switch`, `do-while`, `break`, `continue`, `goto`, `?:`, `+=` / `-=` / `*=` / `/=`, punteros, `struct`, arreglos de dos dimensiones, recursión, casts, y las bibliotecas `<string.h>`, `<ctype.h>` y `<stdlib.h>`. Solo `#include <stdio.h>`.

Para cortar un ciclo antes de tiempo sin `break`, usá una variable bandera en la condición del `while` o del `for`.

## **Archivo de prueba** (`input_test.txt`)

```
El gato come. El perro come mas que el gato.
Un gato, dos gatos; tres GATOS!
El perro duerme y el gato no duerme nunca.
Supercalifragilistico es una palabra muy larga.
```

## **Resultado esperado**

```
=== Resumen ===
Palabras totales: 31
Palabras distintas: 20
Palabra mas larga: supercalifragilistico (21 letras)

=== Top 10 ===
 1. el               5 ****************************************
 2. gato             4 ********************************
 3. come             2 ****************
 4. perro            2 ****************
 5. gatos            2 ****************
 6. duerme           2 ****************
 7. mas              1 ********
 8. que              1 ********
 9. un               1 ********
10. dos              1 ********

=== Largos de palabra ===
       *
       *       *
       *       *   *
       *   *   *   *
       *   *   *   *
       *   *   *   *
       *   *   *   *   *
   *   *   *   *   *   *   *                   *
------------------------------------------------
   1   2   3   4   5   6   7   8   9  10  11 12+
   1   8   5   7   6   2   1   0   0   0   0   1
```

Los espacios al final de cada línea del histograma vertical no importan. Si querés sacarlos, podés pasar la salida por tu `detab_fmt` del proyecto 2.

## **Pruebas extra que te conviene armar vos**

- Un texto donde alguna longitud aparezca más de 10 veces, para probar el escalado del histograma vertical.
- Una palabra de más de 40 letras.
- Un archivo vacío: no puede romperse ni dividir por cero.
- Un texto con más de 500 palabras distintas. Podés generar uno con un script o con tu propio `rpncalc`.

## **Ejecución**

```powershell
gcc -Wall -Wextra -pedantic -std=c89 wordfreq.c -o wordfreq.exe
Get-Content input_test.txt -Raw | .\wordfreq.exe
```

## **Desafío extra (opcional)**

Que los empates del Top 10 se ordenen alfabéticamente en vez de por orden de aparición. Para eso necesitás una función que compare dos palabras guardadas en `texto` y diga cuál va primero.
