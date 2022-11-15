#include <stdio.h>
#include <stdlib.h>

const int TAM = 100;

void imprime(int, int);
void primo(int, int *);

void main(void)
{
    int P[TAM]= 1,2;
    int FLA, J = 2, PRI = 3;
    while (J<= TAM)
    {
        FLA = 1;
        if (FLA)
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2;
    }
    imprime(P, TAM);
}
void primo(int A, int *B)
{
    int DI = 3;
    while (*B && (DI < (A / 2)))
    {
        if ((A % DI) == 0)
            *B = 0;
        DI++;
    }
}
void Imprime(int primos[], int T)
{
    int I;
    for (I=0; I<T; I++)
        printf("\nprimos[%d]: %d", I, Primos[I]);
}


