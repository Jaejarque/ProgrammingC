 

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
