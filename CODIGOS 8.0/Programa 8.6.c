#include <stdio.h>
#include <string.h>
/* Comercializadora farmacéutica.
El programa maneja información sobre ventas, inventario, reabastecimiento y
➥nuevos productos de una comercializadora farmacéutica. */
typedef struct /* Declaración de la estructura producto. */
{
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;
void Lectura(producto *, int); /* Prototipos de funciones. */
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);
void main(void)
{
    producto INV[100];
    /* Se declara un arreglo unidimensional de tipo estructura producto. */
    int TAM, OPE;
    do
    {
        printf("Ingrese el número de productos: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100, TAM < 1);
    /* Se verifica que el número de productos ingresados sea correcto. */
    Lectura(INV, TAM);
    printf("\nIngrese operación a realizar. \n\t\t1 – Ventas \n\t\t 2 – Reabastecimiento \n\t\t 3 - Nuevos Productos \n\t\t 4 – Inventario \n\t\t 0 - Salir: ");
    scanf("%d", &OPE);

    while (OPE)
    {
        switch (OPE)
        {
        case 1:
            Ventas(INV, TAM);
            break;
        case 2:
            Reabastecimiento(INV, TAM);
            break;
        case 3:
            Nuevos_Productos(INV, &TAM);
            /* Se pasa el parámetro por referencia, porque se puede modificar el número de elementos del arreglo en la función. */
            break;
        case 4:
            Inventario(INV, TAM);
            break;
        };
        printf("\nIngrese operación a realizar. \n\t\t1 – Ventas \n\t\t 2 – Reabastecimiento \n\t\t 3 - Nuevos Productos \n\t\t 4 – Inventario \n\t\t 0 - Salir: ");
        scanf("%d", &OPE);
    }
}
void Lectura(producto A[], int T)
/* Esta función se utiliza para leer un arreglo unidimensional de tipo
➥estructura producto de T elementos. */
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\nIngrese información del producto %d", I+1);
        printf("\n\tClave: ");
        scanf("%d", &A[I].clave);
        fflush(stdin);

        printf("\tNombre:");
        gets(A[I].nombre);
        printf("\tPrecio:");
        scanf("%f", &A[I].precio);
        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
    }
}
void Ventas(producto A[], int T)
/* Esta función se utiliza para manejar las venta a un cliente. Se ingresan
➥productos y cantidades, el fin de datos está dado por el cero. Además de
➥obtener el total de las ventas, se actualiza el inventario. */
{
    int CLA, CAN, I, RES;
    float TOT, PAR;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    TOT = 0.0;
    while (CLA)
    {
        printf("\tCantidad: ");
        scanf("%d", &CAN);
        I = 0;
        while ((I < T) && (A[I].clave < CLA))
            /* Se realiza una búsqueda para localizar la clave del producto. */
            I++;
        if ((I == T),(A[I].clave > CLA))
            printf("\nLa clave del producto es incorrecta");
        else if (A[I].existencia >= CAN)
            /* Se analiza si el stock es suficiente para satisfacer el pedido. */
        {
            A[I].existencia -= CAN; /* Se actualiza el stock del producto. */
            PAR = A[I].precio * CAN;
            TOT += PAR;
        }
        else
        {
            printf("\nNo existe en inventario la cantidad solicitada. Solo hay %d",
                   A[I].existencia);
            printf("\nLos lleva 1 - Si 0 – No?: ");
            scanf("%d", &RES);
            if (RES)
            {
                PAR = A[I].precio * A[I].existencia;
                A[I].existencia = 0; /* El stock queda en cero. */
                TOT += PAR;
            }

}
printf("\nIngrese la siguiente clave del producto -0 para salir-:");
scanf("%d", &CLA);
}
printf("\nTotal de la venta: %f", TOT);
}
void Reabastecimiento(producto A[], int T)
/* Esta función se utiliza para reabastecer al inventario. */
{
int CLA,CAN,I;
printf("\nIngrese clave del producto -0 para salir-: ");
scanf("%d", &CLA);
while (CLA)
{
I = 0;
while ((I < T) && (A[I].clave < CLA))
I++;
if ((I==T) || (A[I].clave > CLA))
printf("\nLa clave del producto ingresada es incorrecta");
else
{
printf("\tCantidad: ");
scanf("%d", &CAN);
A[I].existencia += CAN;
}
printf("\nIngrese otra clave del producto -0 para salir-: ");
scanf("%d", &CLA);
}
}
void Nuevos_Productos(producto A[], int *T)
/* Esta función se utiliza para incorporar nuevos productos al inventario.
➥Dado que los productos se encuentran ordenados por clave, puede suceder que
➥al insertar un nuevo producto haya que mover los elementos del arreglo para
➥que continúen ordenados. */
{
int CLA, I, J;
printf("\nIngrese clave del producto -0 para salir-: ");
scanf("%d", &CLA);
while ((*T < 30) && (CLA))
{
I=0;
while ((I < *T) && (A[I].clave < CLA))
/* Búsqueda de la posición que le corresponde a CLA en el arreglo. */
I++;
if (I == *T) /* Se inserta el elemento en la última posición. */
{
A[I].clave = CLA;
printf("\tNombre:");
fflush(stdin);
gets(A[I].nombre);

printf("\tPrecio:");
scanf("%f", &A[I].precio);
printf("\tCantidad: ");
scanf("%d", &A[I].existencia);
*T = *T + 1;
}
else
if (A[I].clave == CLA)
printf("\nEl producto ya se encuentra en el inventario");
else
{
for (J=*T; J>I; J--)
/* Se inserta el nuevo producto en el arreglo. Se mueven una posición
➥a la derecha los elementos
del arreglo que tengan una clave de producto mayor a la ingresada. */
A[J] = A[J-1];
A[I].clave = CLA;
printf("\tNombre:");
fflush(stdin);
gets(A[I].nombre);
printf("\tPrecio:");
scanf("%f", &A[I].precio);
printf("\tCantidad: ");
scanf("%d", &A[I].existencia);
*T = *T + 1;
}
printf("\nIngrese otra clave de producto -0 para salir-: ");
scanf("%d", &CLA);
}
if (*T == 30)
printf("\nYa no hay espacio para incorporar nuevos productos");
}
void Inventario(producto A[], int T)
/* Esta función se utiliza para escribir la información almacenada en —el
➥inventario— un arreglo unidimensional de tipo estructura producto de T
➥elementos. */
{
int I;
for (I=0; I<T; I++)
{
printf("\nClave: %d", A[I].clave);
printf("\tNombre: %s", A[I].nombre);
printf("\tPrecio: %d", A[I].precio);
printf("\tExistencia: %d \n", A[I].existencia);
}
}
