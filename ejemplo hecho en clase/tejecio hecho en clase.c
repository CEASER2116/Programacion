#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/*
  ANSI C program generated by devFlowcharter
  for BubbleSort_C project
*/



#define ARRAY_SIZE 25



int a[ARRAY_SIZE];



int i;//indice



int change;//bandera para indicar intercambio



int n;//cantidad de numero



int buf;//memoria temporal para almacenar dato



time_t seed;




int main(int argc, char* argv[])
{
  seed = 0;
  srand(time(&seed));



  //n = sizeof(a) / sizeof(*a);
  n = ARRAY_SIZE;
  for (i = 0; i <= n-1; i++)
  {
    a[i] = rand() % 1000;
  }



    printf("\nElement desordenados\n");
  for (i = 0; i <= n-1; i++)
  {
    printf("Element a[%d]: %d\n", i, a[i]);
  }



  change = 1;
  while (change == 1)
  {
    change = 0;
    for (i = 0; i <= n-2; i++)
    {
      if (a[i] > a[i+1])
      {
        buf = a[i];
        a[i] = a[i+1];
        a[i+1] = buf;
        change = 1;
      }
    }
  }
  printf("\nElement ordenados\n");
  for (i = 0; i <= n-1; i++)
  {
    printf("Element a[%d]: %d\n", i, a[i]);
  }
  return 0;
