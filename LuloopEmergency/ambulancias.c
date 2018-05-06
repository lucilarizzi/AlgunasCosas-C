#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ambulancias.h"
#include "lib.h"


/** \brief Alta Ambulancia
 *
 * \param ESTRUCTURA de llamadas
 * \param CANT DE llamadas
 * \param flag
 * \return flag
 *
 */
int altaAmbu (eAmbu ambulan[], int tamanio, int flag)
{
    int seguir='s';
    int index;
    while (seguir == 's')
        {
            index=searchIndexAmbul(ambulan, tamanio);
            if (index != -1)
                {
                ambulan[index].idAmbu =index+50;
                ambulan[index].status=1;
                ambulan[index].tiempo=0;
                flag=1;
                printf("\n \nel ID de la ambulancia es %d \n",ambulan[index].idAmbu);

                seguir = preguntarSiNo( "\n Cargar otro Ambulancia? ");
                return flag;
                break;
                }
            else
                {
                printf("\n\n\n===========================\n CUPO DE Equipamiento LLENO\n===========================\n");
                break;
                }
        }
}

/** \brief buscar index
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
 * \return primer index disponible
 *
 */
int searchIndexAmbul( eAmbu status[], int tamanio)
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


/** \brief LLeva a todos los estatus a cero de ambulancias
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
 * \return
 *
 */
void indiceAmbus(eAmbu equipos[], int tamanio)
{
    int i;
    for (i=0 ; i<tamanio;i++)
    {
    equipos[i].status=0;
     }
}

/** \brief precarga de informacion de ambulancias
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
 * \return
 *
 */
void cargarAmbus(eAmbu equipos[], int tamanio)
{
    int i;
    int auxAmb [10] = {40,41,42,43,44,45};

  for(i=0;i<tamanio;i++)
    {   equipos[i].idAmbu=i+40;
        equipos[i].status=1;
     }

 }

/** \brief mostrar 1 datos de 1 ambulancia
 *
 * \param ESTRUCTURA de ambulancias
 * \return
 *
 */
  void showOneAmbu(eAmbu equipos)
{
 printf("\nIdAmbulancia %d \t e:%d"  , equipos.idAmbu , equipos.status);
}


/** \brief listado de ambulancias
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
 * \return
 *
 */
  void listadoDeAmbus (eAmbu ambulan [], int tamanio)
 {
      int i;
      printf("\n\n\n========================\n AMBULANCIAS\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (ambulan[i].status==1 ||ambulan[i].status==1)
                    {
                        showOneAmbu(ambulan[i]);
                    }
                }
 }


/** \brief mostrar ambulancias
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
  * \param flag
 * \return
 *
 */
void mostrarAmbulancias (eAmbu ambulan [], int tamanio, int flag)
{
    int i;
            if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY ambulancias\n======================\n");
            }
            else
            {
                listadoDeAmbus(ambulan, tamanio);
                printf("\n========================================================================\n");
            }


}


/** \brief Baja de ambulancia- pasa estado a cero
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
  * \param flag
 * \return
 *
 */
void bajaAmbulancia (eAmbu ambulan[], int tamanio, int flag)
{
int flagDelete;
int i;
int idAux;
int confirm;

     if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY AMBULANCIAS EN SISTEMAS\n======================\n");
            }
        else
            {
               listadoDeAmbus(ambulan, tamanio);
                printf("\n========================================================================\n");

                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id del ambulan que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                        for (i=0; i<tamanio;i++)
                            {
                                if (ambulan[i].idAmbu== idAux)
                                    {
                                    confirm=preguntarSiNo(" \nSeguro que desea borrar a?\t");
                                    break;
                                    }
                            }
               if (confirm == 's')
               {
                   flagDelete=0;
                   for (i=0; i<tamanio;i++)
                    {
                        if (ambulan[i].idAmbu== idAux)
                            {
                            ambulan[i].status=0;
                            printf("\n\n======================================\n");
                            printf("Ambulancia dada de baja con el Id  Nro: %d",ambulan[i].idAmbu);
                            printf("\n======================================\n");
                            flagDelete=1;
                            break;
                            }
                    }
                if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("El ambulancia que desea borrar no existe");
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


