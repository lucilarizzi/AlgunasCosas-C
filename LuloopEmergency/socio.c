
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "socio.h"
#include "lib.h"


/** \brief ALTA DE CLIENTE
 *
 * \param array de estrcutrad de socio
 * \param tamaño del array
 * \return numero de index
 *
 */
int  altaCliente (eSocio users[], int tamanio)
{
    int dni;
    int seguir='s';
    int index;
    while (seguir == 's')
        {
            index=searchIndexUsers(users, tamanio);
            if (index != -1)
                {
                printf("\n\n---PRUEBA DE INDEX %d \t STATUS %d\n\n",index, users[index].status);

                users[index].idSocio =index+99;
                printf("\n \nel ID del cliente es %d \n", users[index].idSocio);

                printf("Ingrese el nombre:\t");
                fflush(stdin);
                gets(users[index].nombre);

                printf("Ingrese el apellido:\t");
                fflush(stdin);
                gets(users[index].apellido);

                dni=pedirDNI();

                users[index].status=1;
                flag=1;

                seguir= preguntarSiNo( "\t \t Cargar otro Socio? S-N\t");
                return flag;
                }
            else
                {
                printf("\n\n\n===========================\n CUPO DE CLIENTES LLENO\n===========================\n");
                break;
                }
        }

}

/** \brief buscar el primer index vacion en la usuarios/cliente/socio
 *
 * \param array de estrcutrad de socio
 * \param tamaño del array
 * \return numero de index
 *
 */
int searchIndexUsers ( eSocio status[], int tamanio)
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


/** \brief lleva a CERO todo el indice de status de  la estrcutura usuario/cliente/socio
 *
 * \param estructura de usuarios/cliente/socio
 * \param tamanio total del array de usuarios/cliente/socio
 * \return
 *
 */
void indiceSocio(eSocio usuarios[], int tamanio)
{
    int i;
    for (i=0 ; i<tamanio;i++)
    {
    usuarios[i].status=0;
     }
}
/** \brief Carga de Datos Inicial para poder operar
 *
 * \param estructura de usuarios/cliente/socio
 * \param tamanio total del array de usuarios/cliente/socio
 * \return
 *
 */
void cargarSocios(eSocio usuarios[], int tamanio)
{
    int i;
  for(i=0;i<tamanio;i++)
    {

       if (i==0)
        {
        usuarios[i].idSocio=i+10;
        strcpy(usuarios[i].nombre,"Prueba");
        strcpy(usuarios[i].apellido ,"Usuario");
        usuarios[i].dni=30887699-i;
        usuarios[i].edad =35+i;
        usuarios[i].status=1;
        }

        else if (i%2==0)
        {
        usuarios[i].idSocio=i+10;
        strcpy(usuarios[i].nombre,"Lucila");
        strcpy(usuarios[i].apellido ,"Lopez");
        usuarios[i].dni=30887699-i;
        usuarios[i].edad =35+i;
        usuarios[i].status=1;
        }
        else
        {
        usuarios[i].idSocio=i+10;
        strcpy(usuarios[i].nombre,"Ana");
        strcpy(usuarios[i].apellido,"Gomez");
        usuarios[i].dni=30887699-i;
        usuarios[i].edad =35+i;
        usuarios[i].status=1;
        }

    }

}


/** \brief mostrar 1 datos de 1 usuario/socio/cliente
 *
 * \param  un punto de la estrcutura de usuario/socio/cliente
 * \return
 *
 */
  void showOneClient (eSocio usuarios)
{
 printf("\nidSocio %d \t Nombre y Apellido: %s %s Dni:%d e:%d"  , usuarios.idSocio , usuarios.nombre , usuarios.apellido , usuarios.dni, usuarios.status);
}


/** \brief mostrar listado de usuario/socio/cliente
 *
 * \param  array estrcutura de usuario/socio/cliente
 * \param  cantidad maxima de usuario/socio/cliente
 * \return
 *
 */
  void listadoDeSocio (eSocio users [], int tamanio)
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


 /** \brief mostrar listado de usuario/socio/cliente
 *
 * \param  array estrcutura de usuario/socio/cliente
 * \param  cantidad maxima de usuario/socio/cliente
  * \param  flag general de carga de usuarios;
 * \return
 *
 */
void mostrarCliente (eSocio users[], int tamanio, int flag)
{
    int i;
            if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY SOCIOS CARGADOS\n======================\n");
            }
            else
            {
                listadoDeSocio(users, tamanio);
                printf("\n========================================================================\n");
            }


}


/** \brief DAR DE BAJA UN USUARIO PASANDO A 2 SU STATUS
 *
 * \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return
 *
 */
void bajaCliente(eSocio users[], int tamanio, int flag)
{
int flagDelete;
int i;
int idAux;
int confirm;

     if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY SOCIOS CARGADOS\n======================\n");
            }
        else
            {
               listadoDeSocio(users, tamanio);
                printf("\n========================================================================\n");

                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id del SOCIO que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                        for (i=0; i<tamanio;i++)
                            {
                                if (users[i].idSocio== idAux)
                                    {
                                     confirm =preguntarSiNo("Seguro que desea borrar el socio:\t");
                                    break;
                                    }
                            }
               if (confirm == 's')
               {
                   flagDelete=0;
                   for (i=0; i<tamanio;i++)
                    {
                        if (users[i].idSocio== idAux)
                            {
                            users[i].status=0;
                            printf("\n\n======================================\n");
                            printf("Usuario borrado: %s %s, con el Id  Nro: %d", users[i].nombre, users[i].apellido, users[i].idSocio);
                            printf("\n======================================\n");
                            flagDelete=1;
                            break;
                            }
                    }
                if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("El SOCIO que desea borrar no existe");
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


/** \brief modificacion de usuario/socio/cliente
 *
* \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return
 * \return
 *
 */
 void modificarCliente (eSocio users[], int tamanio, int flag)
 {
     int i;
     int idAux;
     int confirm;
     int flagchange=0;
     int opcion;

              if(flag!=0)
               {
               listadoDeSocio(users, tamanio);
               printf("\n===================================================================================\n");
               printf("\n\n Ingrese el Id del SOCIO que desea Modificar:\t");
               scanf("%d", &idAux);

               for (i=0; i<tamanio;i++)
                            {
                                if (users[i].idSocio== idAux)
                                    {
                                    confirm =preguntarSiNo("Seguro que desea modificar el socio:\t");
                                    break;
                                    }
                            }

                flagchange=0;
                if( confirm == 's')
                    {
                for (i=0; i<tamanio;i++)
                {
                    if (users[i].idSocio == idAux)
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
                                    users[i].dni= pedirDNI();


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
* \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
  * \param Cantidad de hards a realziar
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return flag;
 *
 */
 int hardClientes(eSocio MisUsuarios[], int tamanio, int CantCli, int flag)
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
        MisUsuarios[i].idSocio=i+999;
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

