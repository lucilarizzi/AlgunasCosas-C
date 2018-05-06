
///////////// LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

///////////// LIBRERIAS PERSONALIZADAS

#include "lib.h"
#include "usuarios.h"
#include "producto.h"

///////////// CONSTANTES

#define CantUsuario 50
#define CantProduct 100

int main()
{
    ////// DECLARACION DE VARIABLES
    int opcion =-1;
    int flagLog=0;
    int flagUsuarios=0;
    int opcion2=-1;

//  int flagProducto=0;
//   float;
//   char;

    ////// DECLARACION DE ESTRUCTURAS
    eUsuario users [CantUsuario];
    eUsuario oneUser;
    eProducto productos [CantProduct];
    eProducto producto;
    eRelaciones relaciones[CantProduct*CantUsuario];


  ////// INDICES Y HARCODEOS

    indiceUsuarios(users, CantUsuario);
    indiceProducto(productos, CantProduct);
    indiceRelaciones(relaciones,(CantProduct*CantUsuario) );

   // listadoDeUsuarios(users, CantUsuario);

printf("\n===== BIENVENIDO A MERCADO CAUTIVO =======\n");
do
{
// menu principal de opciones del programa
printf ("\n 1- Ingrese con Id de Usuario");
printf ("\n 2- Dar de alta un usuario");
printf ("\n 3- Listar usuarios ya cargados\n 0- Salir");
printf ("\n \n Ingresar como id: 10 y pass :1111\n");
printf ("\n\t Ingrese la opcion deseada:");
scanf("%d", &opcion2);

    switch (opcion2)
    {
      case 1:
        flagLog=logIn(users, CantUsuario);
        switch (flagLog)
        {
            case 1:
                flagUsuarios = menuGeneral(users, productos, relaciones, CantUsuario, CantProduct);
                break;
            case 0:
                printf("\n-------- USUARIO O PASSWORD INCORRECTOS ------------ \n");
                break;
        }
        break;
      case 2 :
        printf("\n ============ Area alta de usuarios ================ \n");
        flagUsuarios =altaUsuario(users, CantUsuario, flagUsuarios);
        cleanScreen();
        break;

      case 3:
        listadoDeUsuarios(users, CantUsuario);
        break;
      case 0:
        printf("\n ============ Usted ha salido ================ \n");
        break;

    }

} while(opcion2==0);



    return 0;
}
