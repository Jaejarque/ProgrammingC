// Consignas:
// 1. Total de bytes/caracteres
// 2. Total de lineas
// 3. Total de palabras
// 4. Longitud de la palabra mas larga encontrada
// 5. Conteo discriminado de caracteres visibles vs espacios en blanco vs caracteres de control
#include <stdio.h>
#define IN 1
#define OUT 0

int main()
{

    long nc, c, nl, nw, pml, auxpml;
    int state = OUT;

    nc = nl = nw = pml = auxpml = 0;

    printf("=== ANALIZADOR LEXICO Y CONTADOR CON DIAGNOSTICO ===\n\n");

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (auxpml > pml)
            {
                pml = auxpml;
            }
            auxpml = 0;
        }
        else
        {
            ++auxpml;
            if(state == OUT){
              state = IN;
              ++nw;
            }
        } 
    }
    if(auxpml > pml){
      pml = auxpml;
    }
    printf("Cantidad de caracteres: %ld\n", nc);
    printf("Cantidad de lineas: %ld\n", nl);
    printf("Cantidad de palabras: %ld\n", nw);
    printf("Palabra mas larga encontrada: %ld\n", pml);
    return 0;
}
