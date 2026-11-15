#include <stdio.h>

#define TABULACION 4 /* cada cuantas columnas hay una parada de tab */
#define MAX_COL 80   /* largo maximo de una linea de salida */

/*
 * Idea general
 * ------------
 * En vez de imprimir cada caracter apenas llega, lo guardamos en "linea"
 * (la linea de salida que se esta armando). Asi podemos:
 *   - PUNTO 2: sacar los espacios del final antes de imprimirla.
 *   - PUNTO 3: si se pasa de MAX_COL, volver atras hasta el ultimo espacio
 *              y cortar ahi.
 * Como los tabs se guardan ya convertidos en espacios, la cantidad de
 * caracteres guardados ES la columna real (cada uno ocupa 1 columna).
 *
 * Decision para palabras mas largas que MAX_COL (ej: la URL del test):
 * no hay espacio donde cortar, asi que se corta a la fuerza en MAX_COL.
 */

char linea[MAX_COL]; /* la linea que se esta armando (nunca mas de MAX_COL) */
int largo = 0;       /* cuantos caracteres hay en linea = columna real */
int ultimo_espacio = -1; /* posicion del ultimo ' ' en linea, -1 si no hay */
int recien_plegada = 0;  /* 1 si la linea actual es continuacion de un corte */

/* Imprime los primeros n caracteres de linea, sin los espacios del final. */
void imprimir_sin_trailing(int n)
{
  int i;

  /* PUNTO 2: retrocedemos mientras el ultimo caracter sea un espacio */
  while (n > 0 && linea[n - 1] == ' ')
    --n;

  for (i = 0; i < n; i++)
    putchar(linea[i]);
}

/* Agrega UN caracter (ya sin tabs) a la linea, plegando si hace falta. */
void agregar(char ch)
{
  int i;     /* para el for que mueve el resto de la palabra */
  int resto; /* cuantos caracteres quedan despues del ultimo espacio */

  /* Despues de un corte, los espacios al principio de la continuacion
     sobran (eran el "hueco" entre dos palabras). La indentacion real de
     una linea nueva NO se toca, porque ahi recien_plegada vale 0. */
  if (recien_plegada && largo == 0 && ch == ' ')
    return;

  if (largo == MAX_COL)
  {
    /* PUNTO 3: la linea esta llena y llega un caracter mas. Hay que cortar. */
    if (ch == ' ')
    {
      /* Caso facil: justo llega un espacio, cortamos aca y lo descartamos. */
      imprimir_sin_trailing(largo);
      putchar('\n');
      largo = 0;
      ultimo_espacio = -1;
      recien_plegada = 1;
      return;
    }
    else if (ultimo_espacio >= 0)
    {
      /* Cortamos en el ultimo espacio: imprimimos lo de antes... */
      imprimir_sin_trailing(ultimo_espacio);
      putchar('\n');

      /* ...y lo de despues del espacio pasa al principio de la linea nueva.
         Esta parte no tiene espacios (ultimo_espacio era el ultimo). */
      resto = largo - (ultimo_espacio + 1);
      for (i = 0; i < resto; i++)
        linea[i] = linea[ultimo_espacio + 1 + i];
      largo = resto;
      ultimo_espacio = -1;
      recien_plegada = 1;
    }
    else
    {
      /* No hay ningun espacio (palabra larguisima): corte forzado. */
      imprimir_sin_trailing(largo);
      putchar('\n');
      largo = 0;
      recien_plegada = 1;
    }
  }

  /* Aca siempre hay lugar: largo < MAX_COL, no nos salimos del arreglo. */
  if (ch == ' ')
    ultimo_espacio = largo;
  linea[largo] = ch;
  ++largo;
}

/* Fin de una linea de la entrada: se imprime lo que quedo y se reinicia. */
void terminar_linea(void)
{
  imprimir_sin_trailing(largo);
  largo = 0;
  ultimo_espacio = -1;
  recien_plegada = 0;
}

int main(void)
{
  int c;
  int i;
  int espacios;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      /* PUNTO 1: espacios que faltan hasta la proxima parada.
         "largo" es la columna real, y largo % TABULACION es la posicion
         dentro del bloque (lo mismo que hacia el "contador" de antes). */
      /* El operador % (resto de la division) se explica en K&R 2.5. */
      espacios = TABULACION - (largo % TABULACION);
      for (i = 0; i < espacios; i++)
        agregar(' ');
    }
    else if (c == '\n')
    {
      terminar_linea();
      putchar('\n');
    }
    else
    {
      agregar(c);
    }
  }

  /* Si el archivo no terminaba en '\n', queda una ultima linea sin imprimir. */
  if (largo > 0)
    terminar_linea();

  return 0;
}
