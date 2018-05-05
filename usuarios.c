#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "usuarios.h"

#define CantUsuario 50


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void  menuUsuario (eUsuario usuarioss[], int tamanio, int *flag)
{
    int i;
    int opcion;
    int usuariosParaHard;
    int auxflag=0;


do{

    printf( "\n \n \t--Menu de Usuario-- \n"
            "\t 2- Baja \n\t 3- Modificacion \n"
            "\t 4- Hard X Usuarios\n"
            "\t 5- Mostrar Usuarios\n"
            "\t 6- Mostrar Usuarios,dado de baja\n"
            " \t 8- Borrar definitivamente los usuarios dados de baja\n\n"
            "\t 0- Salir\tSeleccione la opcion: \t ");

    scanf("%d", &opcion);
    switch (opcion)
                {
                    case 1:
                        auxflag =altaUsuario(users, CantUsuario, flagUsuarios);
                        cleanScreen();
                        break;

                    case 2:
                        auxflag=*flag;
                        bajaUsuario(usuarioss, tamanio,auxflag);
                        cleanScreen();
                        break;
                    case 3:
                        auxflag=*flag;
                        modificarUsuario(usuarioss, tamanio, auxflag);                                                break;
                    case 4:

                        printf("\t Ingrese cuando usuarios desea harcodear: \t");
                        scanf("%d", &usuariosParaHard);
                          if (usuariosParaHard>CantUsuario)
                        {
                            printf("\t Ingrese un numero inferior a %d: \t",CantUsuario);
                            scanf("%d", &usuariosParaHard);
                        }
                        *flag=hardUsuario(usuarioss, usuariosParaHard, flag);
                        cleanScreen();
                        break;
                    case 5:
                    auxflag=*flag;
                    mostrarUsuarios(usuarioss, tamanio, auxflag);
                    cleanScreen();
                        break;
                   case 6:
                     mostrarUsuariosDadoBaja(usuarioss, tamanio, &auxflag);
                     cleanScreen();
                        break;
                    /*  case 8:
                        break;
                    case 9:
                        break;
                    case 10:
                        break; */
                    case 0:
                        opcion=0;
                        break;
                    default:
                        printf("no ha ingresado una opcion valida");
                        printf("\n");
                        system ("cls");
                        break;
                }
 }while (opcion !=0);


}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void indiceUsuarios (eUsuario usuarios[], int tamanio)
{

    int i;
    for (i=0 ; i<tamanio;i++)
    {
    usuarios[i].status=0;
     }


  for(i=0;i<10;i++)
    {

       if (i==0)
        {
        usuarios[i].idUsuario=i+10;
        strcpy(usuarios[i].nombre,"Prueba          ");
        strcpy(usuarios[i].password ,"1111");
        usuarios[i].status=1;
        }

        else if (i%2==0)
        {
        usuarios[i].idUsuario=i+10;
        strcpy(usuarios[i].nombre,"Lucila Rizzi");
        strcpy(usuarios[i].password ,"1234");
        usuarios[i].status=1;
        }
        else
        {
        usuarios[i].idUsuario=i+10;
        strcpy(usuarios[i].nombre,"Ana");
        strcpy(usuarios[i].password ,"00lolo");
        usuarios[i].status=1;
        }

    }

    listadoDeUsuarios(usuarios, 10);

    printf("\n \n \t Usar ID 10 --- Clave 1111");




}
/** \brief
 * \param
 * \param
 * \return
 *
 */

int hardUsuario (eUsuario MisUsuarios[], int tamanio, int flag)
{
    int i;
    int contaHard=0;
    int contarUnos=0;
    int contarCero=0;

    for(i=0;i<CantUsuario;i++)
    {
        if (MisUsuarios[i].status==0)
        {
           contarCero++;
        }
        else
        {
            contarUnos++;
        }

    }


  for(i=0;i<(tamanio+contarUnos);i++)
    {
        if (MisUsuarios[i].status==0)
        {
         MisUsuarios[i].idUsuario=i+1001;
        strcpy(MisUsuarios[i].nombre,"LOLO");
        MisUsuarios[i].status=1;
        flag=1;
        contaHard++;
        }
    }


    printf(" \n-----------------------------");
    printf(" %d Hards Cargados", contaHard);
    printf(" -----------------------------");


    return flag;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void showOneUser (eUsuario usuarios)
{
 printf("\nIdUser %d \t Nombre: %s status:%d"  , usuarios.idUsuario , usuarios.nombre, usuarios.status);
}


int searchIndexUsers ( eUsuario status[], int tamanio)
{
    int index=-1;
    int i;
    for (i=0 ; i<tamanio ; i++)
            {
                if (status[i].status==0)
                {
                   index = i;
                   break;
                }
            }
    return index;
}


int  altaUsuario (eUsuario users[], int tamanio, int flag)
{
    int seguir='s';
    int index;
    while (seguir == 's')
        {
            index=searchIndexUsers(users, tamanio);
            if (index != -1)
                {
                printf("\n\n---PRUEBA DE INDEX %d \t STATUS %d\n\n",index, users[index].status);

                users[index].idUsuario=index+101;
                printf("\n \nel ID de la Usuario es %d \n", users[index].idUsuario);

                printf("Ingrese el nombre del usuario:\t");
                fflush(stdin);
                gets(users[index].nombre);

                printf("ingrese un password\t");
                gets(users[index].password);

           /*    printf("\n============== LISTADO DE SERIES DISPONIBLE ==========================\n");
             for (i=0; i<tamanio; i++)
                 {
                  showOneSerie(serie[i]);
                }

                printf("\n ingrese la serie que desea ver el usuario %s\t",users[index].nombre);
                scanf("%d", &users[index].idSerie);]*/

                users[index].status=1;
                flag=1;

                printf("\t \t Cargar otro usuario? S-N\t");
                fflush(stdin);
                seguir= getche();
                seguir = ValidacionSiNo(seguir,"\n Respuesta Incorrecta - Cargar otro usuario? S-N");
 return flag;
                }
            else
                {
                printf("\n\n\n===========================\n CUPO DE USUARIOS LLENO\n===========================\n");
                break;
                }
        }

}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarUsuarios (eUsuario users[], int tamanio, int flag)
{
    int i;
            if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY USUARIOS CARGADOS\n======================\n");
            }
            else
            {  printf("\n\n\n========================\n USUARIOS CARGADOS\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if(users[i].status==1)
                    {
                    showOneUser(users[i]);
                    }

                }
                printf("\n========================================================================\n");
            }


}
/** \brief DAR DE BAJA UN USUARIO PASANDO A 2 SU STATUS
 *
 * \param
 * \param
 * \return
 *
 */


void bajaUsuario (eUsuario users[], int tamanio, int flag)
{
int flagDelete;
int i;
int idAux;
int confirm;

     if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY USUARIOS CARGADOS\n======================\n");
            }
        else
            {
               listadoDeUsuarios(users, tamanio);
                printf("\n========================================================================\n");

                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id del Usuarios que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                        for (i=0; i<tamanio;i++)
                            {
                                if (users[i].idUsuario== idAux)
                                    {
                                    printf(" \nSeguro que desea borrar la IdUser %s ? S/N\t", users[i].nombre);
                                    fflush(stdin);
                                    confirm= tolower(getche());
                                    confirm =ValidacionSiNo(confirm," Respuesta incorrecta - Seguro que desea borrar la users %d:\t", users[i].nombre);
                                    break;
                                    }
                            }
               if (confirm == 's')
               {
                   flagDelete=0;
                   for (i=0; i<tamanio;i++)
                    {
                        if (users[i].idUsuario== idAux)
                            {
                            users[i].status=2;
                            printf("\n\n======================================\n");
                            printf("Usuario borrado: %s, con el Id  Nro: %d", users[i].nombre, users[i].idUsuario);
                            printf("\n======================================\n");
                            flagDelete=1;
                            break;
                            }
                    }
                if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("El users que desea borrar no existe");
                            printf("\n==========================================\n");
                    }
               }
               else
               {
                            printf("\n\n==========================================\n");
                            printf("Operacion Cancelada");
                            printf("\n==========================================\n");
               }
            }

}


/** \brief MOSTRAR USUARIOS DADOS DE BAJA
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarUsuariosDadoBaja(eUsuario users[], int tamanio, int *flag)
{
    int i;
    if(*flag==0)
            {
                printf("\n\n\n======================\n NO HAY USUARIOS CARGADOS\n======================\n");
            }
            else
            {  printf("\n\n\n========================\n USUARIOS DADO DE BAJA\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if(users[i].status==2)
                    {
                    showOneUser(users[i]);
                    }

                }
                printf("\n----------------------------------------------------------------\n");
            }
        cleanScreen();

}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
 void modificarUsuario (eUsuario users[], int tamanio, int flag)
 {
     int i;
     int idAux;
     int confirm;
     int flagchange=0;
     int opcion;

              if(flag!=0)
               {
               listadoDeUsuarios(users, tamanio);
               printf("\n===================================================================================\n");
               printf("\n\n Ingrese el Id del Usuario que desea Modificar:\t");
               scanf("%d", &idAux);

               for (i=0; i<tamanio;i++)
                            {
                                if (users[i].idUsuario== idAux)
                                    {
                                    printf(" \nSeguro que desea modificar el Usuario %s ? S/N\t", users[i].nombre);
                                    fflush(stdin);
                                    confirm= tolower(getche());
                                    confirm =ValidacionSiNo(confirm," Respuesta incorrecta - Seguro que desea modificar el usuario %d:\t", users[i].nombre);
                                    break;
                                    }
                            }

                flagchange=0;
                if( confirm == 's')
                    {
                for (i=0; i<tamanio;i++)
                {
                    if (users[i].idUsuario == idAux)
                        {
                        printf("\n \nEl usuario a modificar es");
                        showOneUser(users[i]);

                        printf("\n=========================\nOPCIONES \n 1- Nombre \n 2- Password \n \t \t Que dato desea modificar?\t");
                        scanf ("%d", &opcion);
                        switch(opcion)
                                {
                                case 1:
                                     printf("\n Ingrese el nuevo nombre\t");
                                     fflush(stdin);
                                     gets(users[i].nombre);
                                     break;
                                case 2:
                                    printf("\n la actual password es %s\t",users[i].password);
                                      printf("\n Ingrese la nueva password\t");
                                      fflush(stdin);
                                     gets(users[i].password);
                                     break;
                                }

                        printf("\n\n\n======================\n Serie modificada\n======================\n");
                        flagchange=1;
                        showOneUser(users[i]);
                        break;
                        }
                }
                    }
                    else
                          {
                printf("\n\n=====================================\n");
                printf("OPERACION CANCELADA");
                printf("\n=====================================\n");
                }
            }
            else
                {
                printf("\n\n=====================================\n");
                printf("NO HAY USUARIOS CARGADOS");
                printf("\n=====================================\n");
                }
        cleanScreen();

 }


 void listadoDeUsuarios (eUsuario users [], int tamanio)
 {
      int i;
      printf("\n\n\n========================\n USUARIOS CARGADOS\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (users[i].status==1)
                    {
                        showOneUser(users[i]);
                    }

                }
 }
