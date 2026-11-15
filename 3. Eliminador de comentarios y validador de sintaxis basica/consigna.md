# **Proyecto 3:** *Eliminador de Comentarios y Validador de Sintaxis Básica*

Inspirado directamente en los ejercicios finales del capítulo. Es literalmente el primer paso del compilador: el preprocesador.

- **Objetivo:** Leer un archivo fuente en C por entrada estándar y emitir una versión limpia sin comentarios, advirtiendo si hay errores sintácticos de cierre de bloques.
- **Qué debe resolver:**
    - 1. **Eliminar comentarios de una línea (// ...):** Ignorar todo hasta el siguiente \n.
    - 2. **Eliminar comentarios multilínea (/* ... */):** Ignorar todo hasta encontrar la secuencia de cierre, preservando los saltos de línea para no desfasar el número de línea.
    - 3. **Respeto a literales de cadena:** Si aparece /* dentro de una cadena "esto no es /* un comentario */", no debe eliminarse.
    - 4. **Contador de paridad:** Rastrear si al llegar a EOF quedaron paréntesis (), corchetes [] o llaves {} abiertos sin su respectivo cierre.
- **Por qué es valioso:** Es una introducción pura a la construcción de autómatas finitos y analizadores léxicos, el cimiento de los motores de análisis estático y seguridad.


## **Resultado esperado**

#include <stdio.h>


int main(void) {
    char *s1 = "Esto NO es /* un comentario */ y esto tampoco // sigue vivo";
    char *s2 = "Comilla escapada \" /* sigue dentro del string */ \" fin";
    char c1 = '/'; 
    char c2 = '"'; 
    int arr[2] = {1, 2}; 

    printf("%s %s %c %c %d\n", s1, s2, c1, c2, arr[0]);
    return 0; 
}

# 1. Ejecutar tu limpiador y guardar el resultado en salida_limpia.c
Get-Content test_dirty.c -Raw | .\miniclean.exe | Set-Content -Encoding Ascii salida_limpia.c

# 2. Inspeccionar lo que generó
Get-Content salida_limpia.c

# 3. Prueba de fuego: compilar el archivo limpio con GCC estricto
gcc -Wall -Wextra -pedantic -std=c89 salida_limpia.c -o test_ok.exe
.\test_ok.exe

./miniclean < test_dirty.c > salida_limpia.c
cat salida_limpia.c
gcc -Wall -Wextra -pedantic -std=c89 salida_limpia.c -o test_ok && ./test_ok