///////////// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

///////////// LIBRERIAS PERSONALIZADAS
#include "socio.h"
#include "llamados.h"
#include "ambulancias.h"
#include "lib.h"

///////////// CONSTANTES
#define CantSocios 15
#define CantAmbulancias 10
#define CantLlamadas 15
#define motivo1 "INFARTO"
#define motivo2 "ACV"
#define motivo3 "GRIPE"
#define estado0 "LIBRE"
#define estado1 "PENDIENTE"
#define estado2 "CUMPLIDO"







int main()
{
  int opcion =-1;
  int flagSocios=1;
  int flagAmbu=1;
  eSocio socios[CantSocios];
eAmbu ambulancias [CantAmbulancias];
eLlamados llamada [CantLlamadas];

  indiceSocio(socios, CantSocios);
  cargarSocios(socios, 5);

indiceAmbus(ambulancias, CantAmbulancias);
cargarAmbus(ambulancias, 5);

indiceLlamados(llamada, CantLlamadas);
cargarLlamados(llamada, 10);


do
{
// menu principal de opciones del programa
printf("\n===== BIENVENIDO A LULOOP EMERGENCY =======\n\n");
printf ("\n 1- Menu de Socios");
printf ("\n 2- Menu de Ambulancias");
printf ("\n 3- Menu de LLAMADAS");
printf ("\n 0- Salir");
printf ("\n\n\t Ingrese la opcion deseada:  ");
scanf("%d", &opcion);

    switch (opcion)
        {
        case 1:
            printf("\n \t============ Menu Socios ================ \n");
            menuCliente(socios, CantSocios, &flagSocios);
            cleanScreen();
            break;
     case 2 :
            printf("\n ============ Menu de Ambulancias ================ \n");
            menuAmbulancias(ambulancias, CantAmbulancias,&flagAmbu );
            cleanScreen();
            break;
         case 3:
            printf("\n ============ Menu de Llamadas ================ \n");
            if (flagSocios==1 && flagAmbu == 1 )
            {
              menuLlamadas(llamada,socios,ambulancias,CantLlamadas,CantSocios, CantAmbulancias);
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
