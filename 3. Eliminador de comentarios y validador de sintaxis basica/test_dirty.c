/* Comentario inicial de bloque
   que ocupa dos lineas */
#include <stdio.h>

// Comentario de linea simple con llaves falsas { [ (
int main(void) {
    char *s1 = "Esto NO es /* un comentario */ y esto tampoco // sigue vivo";
    char *s2 = "Comilla escapada \" /* sigue dentro del string */ \" fin";
    char c1 = '/'; /* No debe confundirse con inicio de comentario */
    char c2 = '"'; // Comilla simple con doble comilla adentro: NO abre string!
    int arr[2] = {1, 2}; /* Bloque en medio de linea */

    printf("%s %s %c %c %d\n", s1, s2, c1, c2, arr[0]);
    return 0; /* Comentario sin salto de linea antes de llave */
}