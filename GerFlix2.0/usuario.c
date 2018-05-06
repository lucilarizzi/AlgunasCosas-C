#include "usuario.h"


void CrearListadoDeTresUsuarios(eUsuario MisUsuarios[])
{
    int i;
    for(i=0;i<3;i++)
    {
        MisUsuarios[i].idUsuario=i+100;

    }
     strcpy(MisUsuarios[0].nombre,"Maria pia");
     strcpy(MisUsuarios[1].nombre,"Jose luis");
     strcpy(MisUsuarios[2].nombre,"Dafne");


}

void showOneUser (eUsuario lolo)
{
 printf("\nIdUser %d \t Nombre: %s"  , lolo.idUsuario , lolo.nombre);
}

void listarUsuario (eUsuario lolo [], int cantidad)
{
    int i;
     for (i=0; i<cantidad; i++)
    {
        showOneUser(lolo[i]);
     }
}


