#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"
#include "lib.h"


/** \brief ALTA DE CLIENTE
 *
 * \param
 * \param
 * \return
 *
 */
int  altaCliente (eClientes users[], int tamanio, int flag)
{
    int seguir='s';
    int index;
    while (seguir == 's')
        {
            index=searchIndexUsers(users, tamanio);
            if (index != -1)
                {
                printf("\n\n---PRUEBA DE INDEX %d \t STATUS %d\n\n",index, users[index].status);

                users[index].idCliente =index+99;
                printf("\n \nel ID del cliente es %d \n", users[index].idCliente);

                printf("Ingrese el nombre:\t");
                fflush(stdin);
                gets(users[index].nombre);

                printf("Ingrese el apellido:\t");
                fflush(stdin);
                gets(users[index].apellido);

                printf("ingrese el DNI\t");
                scanf("%d",&users[index].dni);
                users[index].dni = validarDNI(users[index].dni);

                users[index].status=1;
                flag=1;

                printf("\t \t Cargar otro Cliente? S-N\t");
                fflush(stdin);
                seguir= getche();
                seguir = ValidacionSiNo(seguir,"\n Respuesta Incorrecta - Cargar otro usuario? S-N");
                return flag;
                }
            else
                {
                printf("\n\n\n===========================\n CUPO DE CLIENTES LLENO\n===========================\n");
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


int searchIndexUsers ( eClientes status[], int tamanio)
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


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void indiceClientes(eClientes usuarios[], int tamanio)
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
        usuarios[i].idCliente=i+10;
        strcpy(usuarios[i].nombre,"Prueba");
        strcpy(usuarios[i].apellido ,"Rizzi");
        usuarios[i].dni=30887699-i;
        usuarios[i].status=1;
        }

        else if (i%2==0)
        {
        usuarios[i].idCliente=i+10;
        strcpy(usuarios[i].nombre,"Lucila");
        strcpy(usuarios[i].apellido ,"Lopez");
        usuarios[i].dni=30887699-i;
        usuarios[i].status=1;
        }
        else
        {
        usuarios[i].idCliente=i+10;
        strcpy(usuarios[i].nombre,"Ana");
        strcpy(usuarios[i].apellido,"Gomez");
        usuarios[i].dni=30887699-i;
        usuarios[i].status=1;
        }

    }


}


/** \brief mostrar 1 datos de 1 clientes
 *
 * \param
 * \param
 * \return
 *
 */
  void showOneClient (eClientes usuarios)
{
 printf("\nIdCliente %d \t Nombre y Apellido: %s %s Dni:%d e:%d"  , usuarios.idCliente , usuarios.nombre , usuarios.apellido , usuarios.dni, usuarios.status);
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
  void listadoDeClientes (eClientes users [], int tamanio)
 {
      int i;
      printf("\n\n\n========================\n CLIENTES CARGADOS\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (users[i].status==1)
                    {
                        showOneClient(users[i]);
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

void mostrarCliente (eClientes users[], int tamanio, int flag)
{
    int i;
            if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY CLIENTES CARGADOS\n======================\n");
            }
            else
            {
                listadoDeClientes(users, tamanio);
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


void bajaCliente(eClientes users[], int tamanio, int flag)
{
int flagDelete;
int i;
int idAux;
int confirm;

     if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY Clientes CARGADOS\n======================\n");
            }
        else
            {
               listadoDeClientes(users, tamanio);
                printf("\n========================================================================\n");

                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id del Cliente que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                        for (i=0; i<tamanio;i++)
                            {
                                if (users[i].idCliente== idAux)
                                    {
                                    printf(" \nSeguro que desea borrar a %s %s ? S/N\t", users[i].nombre, users[i].apellido);
                                    fflush(stdin);
                                    confirm= tolower(getche());
                                    confirm =ValidacionSiNo(confirm," Respuesta incorrecta - Seguro que desea borrar el cliente:\t");
                                    break;
                                    }
                            }
               if (confirm == 's')
               {
                   flagDelete=0;
                   for (i=0; i<tamanio;i++)
                    {
                        if (users[i].idCliente== idAux)
                            {
                            users[i].status=0;
                            printf("\n\n======================================\n");
                            printf("Usuario borrado: %s %s, con el Id  Nro: %d", users[i].nombre, users[i].apellido, users[i].idCliente);
                            printf("\n======================================\n");
                            flagDelete=1;
                            break;
                            }
                    }
                if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("El cliente que desea borrar no existe");
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


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


 void modificarCliente (eClientes users[], int tamanio, int flag)
 {
     int i;
     int idAux;
     int confirm;
     int flagchange=0;
     int opcion;

              if(flag!=0)
               {
               listadoDeClientes(users, tamanio);
               printf("\n===================================================================================\n");
               printf("\n\n Ingrese el Id del Cliente que desea Modificar:\t");
               scanf("%d", &idAux);

               for (i=0; i<tamanio;i++)
                            {
                                if (users[i].idCliente== idAux)
                                    {
                                    printf(" \nSeguro que desea modificar el Usuario %s %s ? S/N\t", users[i].nombre , users[i].apellido );
                                    fflush(stdin);
                                    confirm= tolower(getche());
                                    confirm =ValidacionSiNo(confirm," Respuesta incorrecta - Seguro que desea modificar el cliente :\t");
                                    break;
                                    }
                            }

                flagchange=0;
                if( confirm == 's')
                    {
                for (i=0; i<tamanio;i++)
                {
                    if (users[i].idCliente == idAux)
                        {
                        printf("\n \nEl cliente a modificar es");
                        showOneClient(users[i]);

                        printf("\n=========================\nOPCIONES \n 1- Nombre \n 2- Apellido \n 3- DNI \n \t \t Que dato desea modificar?\t");
                        scanf ("%d", &opcion);
                        switch(opcion)
                                {
                                case 1:
                                     printf("\n Ingrese el nuevo nombre\t");
                                     fflush(stdin);
                                     gets(users[i].nombre);
                                     break;
                                case 2:
                                    printf("\n Ingrese el nuevo apellido\t");
                                      fflush(stdin);
                                     gets(users[i].apellido);
                                     break;
                                case 3:
                                    printf("\n Ingrese el nuevo DNI\t");
                                    fflush(stdin);
                                    scanf("%d", &users[i].dni);
                                    users[i].dni= validarDNI(users[i].dni);


                                }

                        printf("\n\n\n======================\n Serie modificada\n======================\n");
                        flagchange=1;
                        showOneClient(users[i]);
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

 }

/** \brief HARD USUARIOS
 *
 * \param
 * \param
 * \return
 *
 */
 int hardClientes(eClientes MisUsuarios[], int tamanio, int CantCli, int flag)
{
    int i;
    int contaHard=0;
    int contarUnos=0;
    int contarCero=0;

    for(i=0;i<CantCli;i++)
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
        MisUsuarios[i].idCliente=i+999;
        strcpy(MisUsuarios[i].nombre,"LOLO");
        strcpy(MisUsuarios[i].apellido,"LOLO");
        MisUsuarios[i].dni=1000000+i;
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

