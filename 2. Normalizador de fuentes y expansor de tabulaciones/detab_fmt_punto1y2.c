#include <stdio.h>
#define TABULACION 4

int main(void)
{
  int c;
  int contador = 0;
  int pendientes = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      ++pendientes;
      ++contador;
      if (contador == TABULACION)
        contador = 0;
    }
    else if (c == '\t')
    {
      int espacios_tab = TABULACION - contador;
      pendientes += espacios_tab;
      contador = 0;
    }
    else if (c == '\n')
    {
      pendientes = 0;
      putchar(c);
      contador = 0;
    }
    else
    {
      while (pendientes > 0)
      {
        putchar(' ');
        --pendientes;
      }

      putchar(c);
      ++contador;
      if (contador == TABULACION)
        contador = 0;
    }
  }
  return 0;
}
