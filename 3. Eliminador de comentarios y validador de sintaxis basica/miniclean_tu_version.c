#include <stdio.h>

//Primera parte: Eliminar comentarios en bloque
int main(){
    char c;
    int COMENTARIO_BLOQUE = 0;
    int COMENTARIO_LINEA = 0;
    int DENTRO_STRING = 0;
    int DENTRO_STRING_ESCAPADO = 0;
    while((c = getchar()) != EOF){
        if(c == '"'){
            DENTRO_STRING = !DENTRO_STRING;
        }
        if(DENTRO_STRING && c == '\\'){
            DENTRO_STRING_ESCAPADO = 1;
        }
        else{
            DENTRO_STRING_ESCAPADO = 0;
        }
        if(!COMENTARIO_BLOQUE && !COMENTARIO_LINEA && !DENTRO_STRING && !DENTRO_STRING_ESCAPADO){
            if(c == '/'){
                //Posible inicio de comentario en bloque
                c = getchar();
                if(c == '*'){
                    //Inicio de comentario en bloque
                    COMENTARIO_BLOQUE = 1;
                    continue;
                }
                else if(c == '/'){
                    //Inicio de comentario en linea
                    COMENTARIO_LINEA = 1;
                    continue;
                }
                else{
                    putchar('/');
                }
            }
        }
        if(COMENTARIO_BLOQUE && !DENTRO_STRING && !DENTRO_STRING_ESCAPADO){
            if(c == '*'){
                //Posible fin de comentario en bloque
                c = getchar();
                if(c == '/'){
                    //Fin de comentario en bloque
                    COMENTARIO_BLOQUE = 0;
                    continue;
                }
            }            
        }
        if(COMENTARIO_LINEA && !DENTRO_STRING && !DENTRO_STRING_ESCAPADO){
            if(c == '\n'){
                //Fin de comentario en linea
                COMENTARIO_LINEA = 0;
                putchar(c);
                continue;
            }
        }
        //Eliminamos todo lo que este dentro de un comentario en bloque
        if(!COMENTARIO_BLOQUE && !COMENTARIO_LINEA){
            putchar(c);
        }
    }


    return 0;
}