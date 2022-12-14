#include <stdio.h>
#include <stdlib.h>



int main()
{
    char p;
    int i = 0;
    int n = 0;
    char cad[20];



    n = sizeof(cad)/sizeof(*cad);



    printf("Ingrese un maximo de 20 letras!\n");



    //termina el while con 19 elemetos o cuando llega \n
    while ((p = getchar()) != '\n')
            cad[i++] = p;



    cad[i] = '\0';



    printf("\nLa cadena cad es: ");
    puts(cad);



    return 0;
}
