# **Proyecto 4:** *rpncalc (Calculadora en notación polaca inversa con diagnóstico de errores)*

En la notación polaca inversa (RPN) el operador va **después** de sus operandos y no hacen falta paréntesis: `3 4 +` vale 7, y `5 1 2 + 4 * + 3 -` vale 14. Se evalúa con una **pila**: los números se apilan y cada operador saca los dos últimos, opera y apila el resultado. Es la base de cómo los compiladores evalúan expresiones.

- **Objetivo:** Leer expresiones RPN por *stdin*, una por línea, evaluar cada una con una pila hecha con un arreglo y mostrar el resultado o un diagnóstico preciso del error, con su número de línea.
- **Qué debe resolver:**
    - 1. **Lectura por líneas:** Escribí tu propia función `leer_linea` (como `getline` de K&R 1.9) con `#define MAX_LINEA 1000`. Si una línea es más larga, informá `error: linea demasiado larga` y descartá el resto de esa línea sin desbordar el arreglo.
    - 2. **Separar los tokens a mano:** Los tokens están separados por uno o más espacios o tabulaciones, y puede haber blancos al principio y al final de la línea.
    - 3. **Convertir texto a número sin bibliotecas:** Nada de `atof`. Construí el valor dígito a dígito con `c - '0'`. Tienen que funcionar enteros (`42`), decimales (`2.5`, `.5`) y negativos (`-3`). Ojo: `-3` es un número, pero `-` solo es el operador de resta.
    - 4. **La pila:** Un arreglo `float pila[MAX_PILA]` con `#define MAX_PILA 100`, una variable externa con la cantidad de elementos y funciones `apilar` y `desapilar`. Nunca leas ni escribas fuera del arreglo.
    - 5. **Diagnóstico de errores**, con el formato `linea N: error: ...`:
        - `faltan operandos para '+'` (un operador encuentra menos de 2 valores en la pila)
        - `division por cero`
        - `token desconocido 'x'`
        - `pila llena` (más de `MAX_PILA` valores)
        - `expresion incompleta, quedan N valores en la pila` (al final de la línea no quedó exactamente 1 valor)
        - Cuando una línea tiene un error, se informa solo el primero y se pasa a la línea siguiente. La pila tiene que empezar vacía en cada línea.
    - 6. **Las líneas vacías** (o con solo blancos) no se evalúan, pero se cuentan.
    - 7. **Resumen final:** cuántas líneas se leyeron, cuántas dieron resultado, cuántas tuvieron error y cuántas estaban vacías.
- **Por qué es valioso:** Combina todo el capítulo 1: lectura por líneas, arreglos de caracteres, conversión de dígitos, funciones que comparten estado por variables externas y manejo de casos borde sin `break` ni punteros. Es el núcleo de cualquier intérprete.

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
3 4 +
5 1 2 + 4 * + 3 -
2.5 2 *
10 -3 +
7 2 /
1 0 /
+
4 5
3 4 x

  	 8   2   -  
.5 .25 +
```

La línea 10 está vacía y la 11 tiene blancos y una tabulación al principio y al final.

## **Resultado esperado**

```
linea 1: 7.00
linea 2: 14.00
linea 3: 5.00
linea 4: 7.00
linea 5: 3.50
linea 6: error: division por cero
linea 7: error: faltan operandos para '+'
linea 8: error: expresion incompleta, quedan 2 valores en la pila
linea 9: error: token desconocido 'x'
linea 11: 6.00
linea 12: 0.75

Lineas leidas: 12
Correctas: 7
Con error: 4
Vacias: 1
```

## **Pruebas extra que te conviene armar vos**

- Una línea de más de 1000 caracteres.
- Más de 100 números seguidos (para provocar `pila llena`).
- `5 -` (resta con un solo operando) frente a `5 -2` (el número negativo).
- Un archivo que no termina en `\n`.

## **Ejecución**

```powershell
gcc -Wall -Wextra -pedantic -std=c89 rpncalc.c -o rpncalc.exe
Get-Content input_test.txt -Raw | .\rpncalc.exe
```

## **Desafío extra (opcional)**

Agregá el operador `^` (potencia con exponente entero), escribiendo tu propia función `potencia` como la de K&R 1.7.
