#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *cad0 = "Buenos dias";
    char cad1[20] = "Hola";
    char cad2[] = "Mexico";
    char cad3[] = {'B', 'i','e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'};
    char cad4[20], cad5[20], cad6[20];
    printf("\nLa cadena cad0 es: ");
    puts(cad0);
    printf("\nLa cadena cad1 es: ");
    printf("%s", cad1);
    printf("\nLa cadena cad2 es: ");
    puts(cad2);
    printf("\nLa cadena cad3 es: ");
    puts(cad3);
    printf("\nIngrese una linea de texto —se lee con gets—: \n");
    gets(cad4);
    printf("\nLa cadena cad4 es: ");
    puts(cad4);
    fflush(stdin);
    printf("\nIngrese una linea de texto —se lee con scanf—: \n");
    scanf("%s", cad5);
    printf("\nLa cadena cad5 es: ");
    printf("%s", cad5);
    fflush(stdin);
    char p;
    int i = 0;
    while ((p = getchar())!= '\n')
        cad6[i++] = p;
    cad6[i] = '\0';
    printf("\nLa cadena cad6 es: ");
    puts(cad6);

}
