#include <stdio.h>
#include <stdlib.h>

int main()
{
    char p1;
    printf("\nIngrese un caracter para analizar si este es un digito: ");
    p1 = getchar();
    if (isdigit (p1))
        printf("%c es un digito \n", p1);
    else
        printf("%c no es digito \n", p1);
    fflush(stdin);
    printf("\nIngrese un caracter para examinar si este es una letra ");
    p1 = getchar();
    if (isalpha (p1))
        printf("%c es una letra \n", p1);
    else
        printf("%c no es una letra \n", p1);
    fflush(stdin);
    printf("\nIngrese un caracter para examinar si este es una letra minuscula: ");
    p1 = getchar();
    if (isalpha (p1))
        if (islower (p1))
        printf("%c es una letra minuscula \n", p1);
    else
        printf("%c no es una letra minuscula \n", p1);
    else
        printf("%c no es una letra \n", p1);
        fflush(stdin);
            printf("\nIngrese una letra para convertirla de mayuscula a minuscula: ");
            p1 = getchar();
            if (isalpha (p1))
                printf("%c fue conertida de mayuscula a minuscula \n", tolower(p1));
            else
                printf("%c es una letra minuscula \n", p1);
            else
                printf("%c no es una letra \n", p1);

                }
