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
            printf("\nParte real e imaginaria del complejo %d: ",j);
            scanf("%f %f",&ptr_1->x,&ptr_1->y);
        }
    }



    for(j = 0; j< n; j++,ptr_2++)
    {
        printf("\nNumero Complejo %d: %fi%f",j,ptr_2->x,ptr_2->y);
        printf("\n\n");
    }



    free(ptr_1);
    return(0);
}
