#include <stdio.h>
int a = 0;
int *ptr;



int main()
{
    a = 5;
    ptr = &a;

    printf("Hello World\n");

    printf("\nValor &ptr: %d",&ptr);
    printf("\nValor *ptr: %d",*ptr);
    return 0;
}
