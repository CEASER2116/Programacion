#include <stdio.h>
#include <stdlib.h>



int main ()
{



    struct complejo
    {



        float x,y;
    };



    int n, j;
    struct complejo *ptr_1;
    struct complejo *ptr_2;



    printf("Cuntos numeros necesitas?");
    scanf("%d",&n);



    ptr_1 = (struct complejo *) malloc(n * sizeof(struct complejo));



    ptr_2 = ptr_1;



    if(ptr_1 == NULL)
    {
        printf("Memoria no disponible");
    }
    else
    {



        for(j = 0; j< n; j++,ptr_1++)
        {
            ptr_1->x = j;
            ptr_1->y = j;



            printf("\n%d - Parte real %f y parte imaginaria %f",j,ptr_1->x,ptr_1->y);
        }
    }




    for(j = 0; j< n; j++,ptr_2++)
    {
        printf("\nNumero Complejo %d: %fi%f",j,ptr_2->x,ptr_2->y);
        printf("\n");
    }



    free(ptr_1);
    return(0);
}
