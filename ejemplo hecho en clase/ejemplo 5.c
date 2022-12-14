#include <stdio.h>
#include <stdlib.h>



int main()
{
    double x = 0.0;
    double b = 0.0;
    double tmp = 0.0;
    int cont = 0;
    int c = 1;



    printf("Calculo Raiz Cuadrada con Metodo de Newton\n");



    while(c)
    {
        printf("\nDame el numero decimal: ");
        scanf("%lf",&x);



        if(x <= 0)
        {
            c = 0;



        }
        else
        {



            for(cont = 1,b=x; !(b == (x/b)); cont++)
            {



                b=0.5*((x/b)+b);



                if(tmp != b)
                {



                    printf("\nCiclo %d valor actual es: %lf\n",cont,b);
                    tmp = b;
                }
                else
                {
                    break;
                }




                if(cont >100)
                {
                    break;



                }
            }
        }




    }



    printf("\nFin de programa\n");
    //printf("\nRaiz cuadrada de %f es: %f\n",x,b);
    //printf("\nEl calculo fue realizado con %d cliclos", cont);
    return 0;
}
