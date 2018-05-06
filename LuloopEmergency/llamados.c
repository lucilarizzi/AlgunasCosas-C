

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "llamados.h"

#define motivo1 "INFARTO"
#define motivo2 "ACV"
#define motivo3 "GRIPE"

#define estado0 "LIBRE"
#define estado1 "PENDIENTE"
#define estado2 "CUMPLIDO"


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void indiceLlamados(eLlamados llamadas [], int tamanio)
{
     int i;
    for (i=0 ; i<tamanio;i++)
    {
    strcpy(llamadas[i].status, estado0);
    llamadas  [i].tiempoAsignacion= 0;
     }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void cargarLlamados(eLlamados llamadas [], int tamanio)
{
     int i;
    int auxSocio [10] ={10, 11, 10, 10, 11, 15, 14,10, 11, 16};
    int auxAmbulancia[10] ={41,42, 41, 43, 41,41,42, 41, 43, 41};
    int auxTiempoA[10] ={1,2,3,4,5,6,7,8,9,10};
     for (i=0 ; i<10;i++)
    {
    llamadas [i].idLlamado=i+1;
    llamadas  [i].idSocios= auxSocio[i];
    llamadas  [i].idAmbulancia = auxAmbulancia[i];
    llamadas  [i].tiempoAsignacion= auxTiempoA[i];
    strcpy(llamadas [i].status,estado1);
      }

      for (i=0 ; i<3;i++)
      strcpy(llamadas [i].motivo, motivo1);
      for (i=3 ; i<6;i++)
      strcpy(llamadas [i].motivo, motivo2);
      for (i=6 ; i<10;i++)
      strcpy(llamadas [i].motivo, motivo2);
   }


   /** \brief
    *
    * \param
    * \param
    * \return
    *
    */

    void recibirLlamado(eLlamados llamado [], eSocio socio[],eAmbu ambulancia[],int CantLlamadas, int CantSocios ,int CantAmbulancias )
    {
     int i;
     int j;
     int k;
     int l;
     int m;
     int n;
     int idClienteAux;
     int idOperadorAux;
     int idEquipoAux;

    listadoDeSocio(socio, CantSocios);
    printf("\n\nIngrese el id de Socio que necesita una ambulancia :");
    scanf("%d", &idClienteAux);

for (i=0; i <CantLlamadas; i++)
{
    if (strcmp(llamado[i].status,estado0)==0) // busco el indice disponible en las relaciones de llamado
    {
       strcpy(llamado[i].status, estado1);
       llamado [i].idLlamado=i+1;
       for (j=0; j<CantSocios; j++) // recorro
        {
           if (idClienteAux== socio[j].idSocio)
                {
                llamado [i].idSocios=idClienteAux;
                listadoDeAmbus(ambulancia, CantAmbulancias);
                printf("\n\nIngrese el id de ambulancia:");
                scanf("%d", &idEquipoAux);
                for (k=0; k<CantAmbulancias; k++)
                {
                    if (idEquipoAux== ambulancia[k].idAmbu)
                    {
                        llamado [i].idAmbulancia=idEquipoAux;
                        printf("\n\nIngrese la hora de asignacion de ambulancia id %d : ", llamado [i].idAmbulancia);
                        scanf("%f", &llamado[i].tiempoAsignacion);
                        break;
                    }
                }
                break;
                }

            }
             break;
    }
}
       printf("\n================================================");
        printf("\nSocio:");
        showOneClient(socio[j]);
        printf("\n");
        printf("\nAmbulancia:");
        showOneAmbu(ambulancia[k]);
        printf("\n");
        mostrarLlamado(llamado[i]);

    printf("\n\n=========== AMBULANCIA ENVIADA ==============");

 }

 void finzalarLlamada(eLlamados llama[], eSocio socio [],eAmbu ambulanc[],int CantLlamadas,int CantSocios,int CantAmbulancias)
 {
     int i;
     int j;
     int k;
     int l;
     int m;
     int idAlquilerAux;
     int idClienteAux;
     int idEquipoAux;
     int auxTiempo;
     char seguir;
     int flag=0;

    flag=buscarLlamado(llama, socio,ambulanc,CantLlamadas, CantSocios,CantAmbulancias);
    if (flag==0)
         {
             printf("\n\n=========== No existe la llamada ==============\n");
         }
    else
         {

         }

}




/** \brief recorre cliente, busca alquileres, lista producto alquilado
   *
   * \param
   * \param
   * \return
   *
   */

   int buscarLlamado(eLlamados llamadass[], eSocio cliente[],eAmbu equipo[],int CantLlamadas, int CantSocios,int CantAmbulancias)
  {
      int j;
      int idClienteAux;
      int flag=0;

    listarLlamado(llamadass, CantLlamadas);
    printf("\n\nIngrese el id de llamada que desea dar de baja :");
    scanf("%d", &idClienteAux);

       for (j=0; j<CantSocios; j++) // recorro los clientes
        {
           if (idClienteAux==llamadass[j].idLlamado) // si el cliente es igual al que busco
                {
                flag=1;
                mostrarLlamado(llamadass[j]);
                strcpy(llamadass[j].status,estado2);
                printf("\n\n=========== LLAMADA FINALIZADA ==============\n");
                break;
                }
          }
          return flag;
}


/** \brief MOSTRAR 1 LLAMADO
 *
 * \param
 * \param
 * \return
 *
 */
 void mostrarLlamado (eLlamados llamado)
 {
     printf("\nLlamado: %d\ Socio: %d Motivo: %s  Estado %s  Hora: %.2f " ,llamado.idLlamado , llamado.idSocios , llamado.motivo, llamado.status, llamado.tiempoAsignacion);
 }


 /** \brief LISTADO DE LLAMADAS
 *
 * \param
 * \param
 * \return
 *
 */
 void listarLlamado (eLlamados llamado [], int tamanio)
 {
      int i;
      printf("\n\n\n========================\nLLAMADAS PENDIENTES\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (strcmp(llamado[i].status,estado1)==0)
                    {
                        mostrarLlamado(llamado[i]);
                    }

                }
 }
