#include <stdio.h>
#define TABULACION 4
int main(void)
{
  int c;
  int contador = 0;
  int cantidadespacios = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      int espacios = TABULACION - contador;
      for (int i = 0; i < espacios; i++)
        putchar(' ');
      contador = 0;
    }
    else if (c == '\n')
    {
      putchar(c);
      contador = 0;
    }
    else
    {
      putchar(c);
      ++contador;
      if (contador == TABULACION)
        contador = 0;
    }

    if(c == ' '){
      ++cantidadespacios;
    } else{
      cantidadespacios = 0;
    }

    

    
  }
  return 0;
}
