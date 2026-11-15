#include <stdio.h>

/*
 * miniclean: elimina comentarios de un fuente C y verifica que los
 * parentesis, corchetes y llaves esten balanceados.
 *
 * Es una MAQUINA DE ESTADOS: la variable "estado" dice en que parte del
 * codigo estamos, y cada estado tiene sus propias reglas para decidir
 * (1) si el caracter se imprime y (2) a que estado se pasa.
 *
 * Solo usa herramientas del capitulo 1 de K&R (salvo fprintf, ver abajo).
 *
 * Una sola variable de estado hace imposible estar "en un comentario y en
 * un string a la vez", que era el origen de varios errores.
 */

/* ----- Estados ----- */
#define NORMAL            0 /* codigo comun */
#define BARRA             1 /* vimos '/', falta saber si es comentario o division */
#define COM_LINEA         2 /* adentro de // ... */
#define COM_BLOQUE        3 /* adentro de / * ... * / */
#define COM_BLOQUE_AST    4 /* adentro de un bloque y el ultimo caracter fue '*' */
#define STRING            5 /* adentro de "..." */
#define STRING_ESCAPE     6 /* adentro de "..." y el ultimo caracter fue '\' */
#define CARACTER          7 /* adentro de '...' */
#define CARACTER_ESCAPE   8 /* adentro de '...' y el ultimo caracter fue '\' */

/* ----- Variables globales (K&R 1.10) ----- */
int estado = NORMAL;
int linea = 1;              /* numero de linea actual, para los mensajes */
int parentesis = 0;         /* cantidad de ( abiertos sin cerrar */
int corchetes = 0;          /* cantidad de [ abiertos sin cerrar */
int llaves = 0;             /* cantidad de { abiertos sin cerrar */
int errores = 0;            /* cuantos problemas encontramos */

/* Lleva la cuenta de ( ) [ ] { }. Solo se llama desde codigo NORMAL,
   asi que los que estan en comentarios o strings nunca se cuentan.
   Si llega un cierre sin su apertura, lo informamos en el momento
   (con la linea), porque al final ya no sabriamos donde estaba. */
void contar_paridad(int c)
{
  if (c == '(')
    ++parentesis;
  else if (c == '[')
    ++corchetes;
  else if (c == '{')
    ++llaves;
  else if (c == ')')
  {
    if (parentesis == 0)
    {
      fprintf(stderr, "Error linea %d: ')' sin apertura\n", linea);
      ++errores;
    }
    else
      --parentesis;
  }
  else if (c == ']')
  {
    if (corchetes == 0)
    {
      fprintf(stderr, "Error linea %d: ']' sin apertura\n", linea);
      ++errores;
    }
    else
      --corchetes;
  }
  else if (c == '}')
  {
    if (llaves == 0)
    {
      fprintf(stderr, "Error linea %d: '}' sin apertura\n", linea);
      ++errores;
    }
    else
      --llaves;
  }
}

/* Reglas del estado NORMAL. Esta en una funcion aparte porque la usamos
   desde dos lugares: el estado NORMAL y el estado BARRA (cuando la '/'
   resulto ser una division y el caracter siguiente hay que procesarlo
   como codigo comun). */
void procesar_normal(int c)
{
  if (c == '/')
  {
    estado = BARRA;  /* todavia no la imprimimos: puede ser un comentario */
    return;
  }

  putchar(c);

  if (c == '"')
    estado = STRING;
  else if (c == '\'')
    estado = CARACTER;
  else
    contar_paridad(c);
}

int main(void)
{
  int c; /* int y no char, para poder distinguir EOF (K&R 1.5.1) */

  while ((c = getchar()) != EOF)
  {
    if (estado == NORMAL)
    {
      procesar_normal(c);
    }
    else if (estado == BARRA)
    {
      if (c == '/')
        estado = COM_LINEA;      /* era "//" */
      else if (c == '*')
      {
        estado = COM_BLOQUE;     /* era "/ *" */
        /* El estandar de C reemplaza cada comentario por UN espacio.
           Sin esto, "int/ * x * /a;" quedaria "inta;" y no compilaria. */
        putchar(' ');
      }
      else
      {
        /* Era una division (o cualquier otra cosa): imprimimos la '/'
           que habiamos guardado y procesamos c como codigo comun.
           Asi no se pierde c, aunque sea una '"' o un '\n'. */
        putchar('/');
        estado = NORMAL;
        procesar_normal(c);
      }
    }
    else if (estado == COM_LINEA)
    {
      /* Todo se ignora (incluidas comillas, llaves y '/ *'), salvo el '\n',
         que termina el comentario y SI se imprime. */
      if (c == '\n')
      {
        putchar(c);
        estado = NORMAL;
      }
    }
    else if (estado == COM_BLOQUE)
    {
      if (c == '*')
        estado = COM_BLOQUE_AST; /* puede ser el principio del cierre */
      else if (c == '\n')
        putchar(c);              /* preservamos los saltos de linea */
    }
    else if (estado == COM_BLOQUE_AST)
    {
      if (c == '/')
        estado = NORMAL;         /* era "* /": se cerro el comentario */
      else if (c != '*')
      {
        /* Era un '*' suelto, seguimos adentro del comentario.
           (Si llega otro '*', no hacemos nada: ese nuevo '*' tambien
           puede ser el principio del cierre, asi que nos quedamos
           en este mismo estado.) */
        if (c == '\n')
          putchar(c);
        estado = COM_BLOQUE;
      }
    }
    else if (estado == STRING)
    {
      putchar(c);                /* lo de adentro de un string se copia tal cual */
      if (c == '\\')
        estado = STRING_ESCAPE;  /* el proximo caracter no puede cerrar */
      else if (c == '"')
        estado = NORMAL;
    }
    else if (estado == STRING_ESCAPE)
    {
      putchar(c);                /* \" \\ \n ...: se copia y volvemos al string */
      estado = STRING;
    }
    else if (estado == CARACTER)
    {
      putchar(c);
      if (c == '\\')
        estado = CARACTER_ESCAPE;
      else if (c == '\'')
        estado = NORMAL;
    }
    else if (estado == CARACTER_ESCAPE)
    {
      putchar(c);
      estado = CARACTER;
    }

    /* Contamos las lineas de la entrada para los mensajes de error */
    if (c == '\n')
      ++linea;
  }

  /* ----- Al llegar a EOF ----- */

  /* Si el archivo terminaba en '/', esa barra quedo guardada sin imprimir */
  if (estado == BARRA)
    putchar('/');

  /* UNICA EXCEPCION AL CAPITULO 1: fprintf(stderr, ...) (capitulo 7).
     Funciona igual que printf, pero escribe en la "salida de errores".
     Asi los avisos aparecen en la consola pero NO quedan escritos dentro
     de salida_limpia.c (si quedaran ahi, gcc no lo podria compilar).
     Por ahora pensalo como "un printf para mensajes de error". */
  if (estado == COM_BLOQUE || estado == COM_BLOQUE_AST)
  {
    fprintf(stderr, "Error: comentario de bloque sin cerrar\n");
    ++errores;
  }
  if (estado == STRING || estado == STRING_ESCAPE)
  {
    fprintf(stderr, "Error: string sin cerrar\n");
    ++errores;
  }
  if (estado == CARACTER || estado == CARACTER_ESCAPE)
  {
    fprintf(stderr, "Error: caracter sin cerrar\n");
    ++errores;
  }
  if (parentesis > 0)
  {
    fprintf(stderr, "Error: %d '(' sin cerrar\n", parentesis);
    ++errores;
  }
  if (corchetes > 0)
  {
    fprintf(stderr, "Error: %d '[' sin cerrar\n", corchetes);
    ++errores;
  }
  if (llaves > 0)
  {
    fprintf(stderr, "Error: %d '{' sin cerrar\n", llaves);
    ++errores;
  }

  return 0;
}
