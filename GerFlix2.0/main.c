#include <stdio.h>
#include <stdlib.h>
#include "serie.h"
#include "usuario.h"
#include "usuarioSerie.h"

/**
*
    1. los datos de la serie que ve cada usuario
    2. por cada serie todos los usuarios que la ven
    3. por cada serie cuantos usuarios la ven
*
*/
int main()
{
    eSerie series [5];
    eUsuario usuarios [3];
    eUsuarioSerie relaciones [9];
    int i;
    int j;
    int h;

    int opcion;

////////////// harcodeos
    CrearListadoSeries(series, 5);
    CrearListadoDeTresUsuarios(usuarios);
    CrearListadoUsuariosYSeries(relaciones);
////////////// listados de muestran
        printf("\n\=======================================================\n");
            listarSerie(series, 5);
        printf("\n\=======================================================\n");
            listarUsuario(usuarios,3);
        printf("\n\=======================================================\n");
        for (i=0; i<9;i++) //recorro usuarioseries
        {
          printf("idSerie %d -- IdUser %d \n", relaciones[i].idSerie,relaciones[i].idUsuario);
        }
        printf("\n\=======================================================\n");
        do {
        opcion =displayMenuABM("\nMenu de Consulta\n 1- que series ve cada usuario \n 2- Mostrar por cada serie, los usuarios que la ve \n 3- mostrar las series menos populares \n 4- ingresar usuario y listar sus series \n 5- Ingresar Serie y listar sus usuarios \n 6- top 3 de series \n 9- Para salir! \n \n \t Ingrese la Opcion Elegida: ");
        switch (opcion) {
        case 1:
              printf("\n============ Serie por Usuarios ============\n");
               allSerieForUser(relaciones, usuarios, series);
               break;
        case 2:
            printf("\n============ Usuarios por Serie ============\n");
            allUserforSeries (relaciones, usuarios, series);
            break;
        case 3:
            printf("\n============ Series Menos Populares ============\n");
            contarUsuariosPorSerie(relaciones, usuarios, series);
            break;
        case 4:
            printf("\n============ Buscar Un Usuario ============\n");
            searchUser (relaciones, usuarios, series);
            break;
        case 5:
            printf("\n============ Buscar Una Serie ============\n");
            searchSerie (relaciones, usuarios, series);
            break;
        case 6:
            printf("\n============ TOP 3 ============\n");
            top3series (relaciones, usuarios, series);
            break;
        case 9:
            printf("\n============ SALIR ============\n");
            opcion= 9;
            break;
        }
printf("---------------------------------------------");
cleanScreen();
    } while (opcion != 9);


//////////////////
printf("\n \n \n Chau\n \n");
    printf("\n \n \n Lucila Rizzi\n \n");
    return 0;
}








