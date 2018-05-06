///////////// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

///////////// LIBRERIAS PERSONALIZADAS
#include "lib.h"
#include "clientes.h"

///////////// CONSTANTES
#define CantClientes 15
#define CantOperadores 5
#define CantEquipos 10
#define CantAlquileres 15


int main()
{
  int opcion =-1;
  int flagClientes=1;
  int flagOperadores=1;
  int flagEquipos=1;


  eClientes clientes[CantClientes];
  eEmpleados operadores [CantOperadores];
  eEquipo equiposs [CantEquipos];
  eAlquiler alquiler [CantAlquileres];



  indiceClientes(clientes, CantClientes);
  indiceEmpleados(operadores, CantOperadores);
  indiceEquipos(equiposs, CantEquipos);
  indiceAlquiler(alquiler, CantAlquileres);

printf("\n===== BIENVENIDO A ALQUILERES LULOOP =======\n");


do
{
// menu principal de opciones del programa
printf ("\n 1- Menu de Usuarios");
printf ("\n 2- Menu de Equipos");
printf ("\n 3- Menu de Operadores");
printf ("\n 4- Menu de Alquileres\n 0- Salir");
printf ("\n\n\t Ingrese la opcion deseada:  ");
scanf("%d", &opcion);

    switch (opcion)
        {
        case 1:
            printf("\n \t============Menu Usuarios ================ \n");
            menuCliente(clientes, CantClientes, &flagClientes);
            cleanScreen();
            break;
        case 2 :
            printf("\n ============ Menu de Equipos ================ \n");
            menuEquipos(equiposs, CantEquipos,&flagEquipos );
            cleanScreen();
            break;
        case 3:
            printf("\n ============ Menu de Empleados ================ \n");
            menuEmpleados(operadores, CantOperadores, &flagOperadores);
            break;
        case 4:
            printf("\n ============ Menu de Alquileres ================ \n");
            if (flagClientes==1 && flagEquipos == 1 && flagOperadores==1)
            {
              menuAlquileres(alquiler,clientes, operadores,equiposs,CantAlquileres,CantClientes, CantOperadores, CantEquipos);
            }
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
