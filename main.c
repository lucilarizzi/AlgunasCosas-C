
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
    float;
    char;

    eUsuario users [CantUsuario];
    eProducto productos [CantProduct];

  ////// INDICES Y HARCODEOS

    indiceUsuarios(users, CantUsuario);
    indiceProducto(productos, CantProduct);
    indiceRelaciones(relaciones,(CantProduct*CantUsuario) );

  ////// LOG IN CON PASSWORD

   do
    {
    flagLog=logIn(users, CantUsuario);

       switch (flagLog)
        {
        case 1:
            flagUsuarios = menuGeneral(users, productos, CantUsuario, CantProduct);
            break;
        case 0:
            printf("\n-------- USUARIO O PASSWORD INCORRECTOS ------------ \n");
            break;
        case 2:
            break;
        case 3:
            flagUsuarios =altaUsuario(users, CantUsuario, flagUsuarios);
            cleanScreen();
            break;

            }
    } while(flagLog!=2);

    return 0;
}
