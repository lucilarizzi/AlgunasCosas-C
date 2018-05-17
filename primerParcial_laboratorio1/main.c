///////////// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

///////////// LIBRERIAS PERSONALIZADAS
#include "funciones.h"
#include "propietarios.h"
#include "ingresoEgresos.h"

///////////// CONSTANTES
#define CantPropietarios 10
#define CantLugares 20

#define Alpha_Romeo 1
#define Ferrari 2
#define Audio 3
#define Otro 4



int main()
{
    int opcion =-1;
    int flagProp=0;
    int flagIngreso=0;

        ePropietario propietario[CantPropietarios];
        eIngresoyEgreso ingresoEgreso [CantLugares];

        indicePropietario(propietario, CantPropietarios);
        flagProp= cargarPropietario(propietario, 4);

        indiceIngresoyEgreso(ingresoEgreso, CantLugares);
        flagIngreso= cargarIngresos(ingresoEgreso, 10);
do
{
printf("\n===== BIENVENIDO Al Estacionamiento =======\n\n");
printf ("\n 1- Alta Propietarios");
printf ("\n 2- Modificacion Propietario");
printf ("\n 3- Baja Propietario");
printf ("\n 4- Ingreso Automovil");
printf ("\n 5- Egreso Automovil");
printf ("\n 6- Consultas");
printf ("\n 0- Salir");
printf ("\n\n\t Ingrese la opcion deseada:  ");
scanf("%d", &opcion);

    switch (opcion)
        {
        case 1:
            printf("\n \t============ Alta Propietarios================ \n");
            flagProp= altaCliente(propietario, CantPropietarios);
            cleanScreen();
            break;
        case 2 :
            printf("\n ============ Modificacion Propietario ================ \n");
            modificarPropietario(propietario, CantPropietarios, flagProp);
            cleanScreen();
            break;
         case 3:
            printf("\n ============ Baja Propietario ================ \n");
            if (flagProp==1 )
            {
            bajaCliente(propietario, CantPropietarios, flagProp);
            }
            else
            {
            printf("\n     === NO HAY PROPIETARIOS CARGADOS === \n");
            }
            cleanScreen();
            break;
        case 4:
            printf("\n \t============ Ingreso Automovil ================ \n");
            if (flagProp==1)
            {
            flagIngreso=1;
            recibiringreso(ingresoEgreso,propietario, CantLugares, CantPropietarios, flagProp);
            }
            cleanScreen();
            break;
        case 5:
           printf("\n ============ Egreso Automovil ================ \n");
           if (flagIngreso!=0)
           {
               egresarAuto(ingresoEgreso,propietario,CantLugares, CantPropietarios);
            }
           else
            {
            printf("\n ============ No hay autos Ingresados ================ \n");
           }
           cleanScreen();
            break;

         case 6:
            system ("cls");
           // printf("\n ============ Consultas ================ \n");
            menuConsulta(ingresoEgreso,propietario,CantLugares, CantPropietarios);
            cleanScreen();
            break;
        case 0:
            printf("\n ============ Usted ha salido ================ \n");
            break;
         default:
            printf("no ha ingresado una opcion valida");
            printf("\n");
            system ("cls");
            break;
    }

} while(opcion!=0);

    return 0;
}
