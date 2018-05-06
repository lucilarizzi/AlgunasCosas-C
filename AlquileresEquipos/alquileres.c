#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"
#include "empleados.h"
#include"equipo.h"
#include"alquileres.h"



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void indiceAlquiler(eAlquiler alquiler[], int tamanio)
{
    int auxClientes [10] ={10, 11, 10, 10, 11, 15, 14,10, 11, 16};
    int auxEquipos[10] ={41,42, 41, 43, 41,41,42, 41, 43, 41};
    int auxOperador [10] ={22,21,22,21,22,21,22,21,22,21};
     int auxTiempoAlq [10] ={1,2,3,4,5,6,7,8,9,10};
     int auxTiempoReal [10] ={1,2,3,4,5,6,7,8,9,10};

    int i;
    for (i=0 ; i<tamanio;i++)
    {
    strcpy(alquiler[i].status, "LIBRE");
     }
    for (i=0 ; i<10;i++)
    {
    alquiler[i].idAlquiler=i+1;
    alquiler [i].idCliente= auxClientes[i];
    alquiler [i].idEquipo= auxEquipos[i];
    alquiler [i].idOperador= auxOperador[i];
    alquiler [i].tiempoAlquiler= auxTiempoAlq[i];
    alquiler [i].tiempoReal= auxTiempoReal[i]+2;
    strcpy(alquiler[i].status, "ALQUILADO");
    }

   }








/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void alquilarEquipo(eAlquiler alquiler[], eClientes cliente[],eEmpleados operador[] ,eEquipo equipo[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos)
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

    listadoDeClientes(cliente, CantClientes);
    printf("\n\nIngrese el id de cliente que desea alquilar un equipo :");
    scanf("%d", &idClienteAux);

for (i=0; i <CantAlquileres; i++)
{
    if (strcmp(alquiler[i].status,"LIBRE")==0) // busco el indice disponible en las relaciones de alquiler
    {
       strcpy(alquiler[i].status,"ALQUILADO");
       alquiler [i].idAlquiler=i+1;
       for (j=0; j<CantClientes; j++) // recorro
        {
           if (idClienteAux== cliente[j].idCliente)
                {
                alquiler [i].idCliente=idClienteAux;
                listadoDeEquipos(equipo, CantEquipos);
                printf("\n\nIngrese el id de equipo que desea alquilar un equipo :");
                scanf("%d", &idEquipoAux);
                for (k=0; k<CantEquipos; k++)
                {
                    if (idEquipoAux== equipo[k].idEquipo)
                    {
                        alquiler [i].idEquipo=idEquipoAux;

                        listadoDeEmpleados(operador, CantOperadores);
                        printf("\n\nIngrese el id del operario :");
                        scanf("%d", &idOperadorAux);

                        for(l=0; l<CantOperadores; l++)
                        {
                            if(idOperadorAux==operador[l].idEmpleado)
                            {
                                alquiler[i].idOperador=idOperadorAux;

                                printf("\n\nIngrese cuantos dias que estara alquilado el equipo :");
                                scanf("%d", &alquiler[i].tiempoAlquiler);
                                break;
                            }
                        }
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
        printf("\nCliente:");
        showOneClient(cliente[j]);
        printf("\n");
        printf("\nEquipo:");
        showOneEquip(equipo[k]);
        printf("\n");
        printf("\nSera Operado por:");
        showOneEmploye(operador[l]);
        printf("\n");
        printf("\nEstara alquilado por %d Dias", alquiler[i].tiempoAlquiler);

    printf("\n\n=========== ALQUILER INGRESADO ==============");

 }

 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

  void devolucionEquipo(eAlquiler alquiler[], eClientes cliente[],eEmpleados operador[] ,eEquipo equipo[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos)
 {
     int i;
     int j;
     int k;
     int l;
     int m;
     int idAlquilerAux;
     int idClienteAux;
     int idOperadorAux;
     int idEquipoAux;
     int auxTiempo;
     char seguir;
     int flag=0;

    listadoDeClientes(cliente, CantClientes);
    flag=clienteAlquilerPeoducto(alquiler, cliente, operador,equipo,CantAlquileres, CantClientes, CantOperadores, CantEquipos);
    if (flag==0)
         {
             printf("\n\n=========== No existe el usuario ==============\n");
         }
    else if (flag==2)
         {
             printf("\n\n=========== Este Cliente no tiene transacciones ==============\n");
         }
    else
         {
             printf("\n\nIngrese el id de transaccion que desea devolver el equipo :");
            scanf("%d", &idAlquilerAux);

             int flagTrans=0;
             for (m=0; m<CantAlquileres; m++)
             {
                 if(idAlquilerAux==alquiler[m].idAlquiler)
                 {
                     flagTrans=1;
                     printf("\t \t Esta seguro que desea borrar la transaccion  S-N\t");
                     fflush(stdin);
                     seguir=tolower(getche());
                    seguir = ValidacionSiNo(seguir,"\n Respuesta Incorrecta - desea borrar la transaccion ? S-N");
                     if (seguir=='s')
                     {
                        strcpy(alquiler[m].status,"FINALIZADO");
                        printf("\n\n=========== DEVOLUCION INGRESADA ==============\n");
                        break;
                     }
                     else
                    {
                        printf("\n\n=========== OPERACION CANCELADA ==============\n");
                    }

                 }
             }

             if(flagTrans==0 )
                {
                        printf("\n\n=========== la transaccion ingresado no existe ==============\n");
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

void consultaMejorCliente(eAlquiler alquiler[], eClientes cliente[],eEmpleados operador[] ,eEquipo equipo[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos)
{
    int i;
      int j;
       int k;
      int idClienteAux;
      int flag=0;
      int f;
      int contador[CantClientes];
 char max[30];

    for (j=0; j<CantClientes; j++) // recorro los clientes
        { contador [j]=0;
          for (i=0; i <CantAlquileres; i++) // recorro los alquileres realizados
                {
                    if (alquiler[i].idCliente == cliente[j].idCliente)
                        {
                        for (k=0; k<CantEquipos; k++) // recorro lo equipo
                        {
                            if (alquiler[i].idEquipo== equipo[k].idEquipo) //i si el equipo del alquiler coincide con la base
                            {
                            contador[j]++;
                            }
                        }
                        }
                    }
              }

 for (j=0; j<CantClientes; j++) // recorro los clientes
        {
            if (contador[j]<contador[j+1]|| flag ==0)
            {
            strcpy(max , cliente[j].nombre);
            strcat(max, " ");
            strcat(max , cliente [j].apellido);
            flag =1;
            }


        }
        printf(" El usuario que mas alquileres hizo fue \t %s", max);

}


  /** \brief recorre cliente, busca alquileres, lista producto alquilado
   *
   * \param
   * \param
   * \return
   *
   */

   int clienteAlquilerPeoducto(eAlquiler alquiler[], eClientes cliente[],eEmpleados operador[] ,eEquipo equipo[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos)
  {
      int i;
      int j;
       int k;
      int idClienteAux;
      int flag=0;


    printf("\n\nIngrese el id de cliente que desea devolver un equipo :");
    scanf("%d", &idClienteAux);

       for (j=0; j<CantClientes; j++) // recorro los clientes
        {
           if (idClienteAux== cliente[j].idCliente) // si el cliente es igual al que busco
                {
                flag=2;
           for (i=0; i <CantAlquileres; i++) // recorro los alquileres realizados
                {
                if (cliente[j].idCliente==alquiler[i].idCliente && strcmp(alquiler[i].status,"ALQUILADO")==0 ) // busci los alquilere que realizo ese cliente
                    {
                       for (k=0; k<CantEquipos; k++) // recorro lo equipo
                        {
                            if (alquiler[i].idEquipo== equipo[k].idEquipo) //i si el equipo del alquiler coincide con la base
                            {
                            flag=1;
                            printf("\nTRANSACCION %d                -- Estado %s------",alquiler[i].idAlquiler, alquiler[i].status);
                            showOneEquip(equipo[k]); // muestro una linea de equipo
                            break;
                            }

                            }
                    }
                }
                 break;
                }
          }
          return flag;
}


/** \brief Compara los alquileres y calcula los equipo con mas usos
 *
 * \param estructura de alquileres
 * \param estructura de equipos
 * \param cantidad de alquileres
  * \param cantidad de equipos
 * \return flag
 *
 */
void consultaEquipoMasAlquilado (eAlquiler alquiler [] ,eEquipo equiposs [] , int CantAlquileres  ,  int CantEquipos )
{
      int i;
      int j;
       int k;
      int contador [CantEquipos] ;

      int flag=0;
      int max ;

      for (i=0; i<CantEquipos; i++)
      {
          contador[i]=0;
      }


           for (i=0; i <CantAlquileres; i++) // recorro los alquileres realizados
                {
                  for (k=0; k<CantEquipos; k++) // recorro los equipos
                        {
                            if (alquiler[i].idEquipo== equiposs[k].idEquipo)
                            {
                            contador [k]++;
                            }
                        }
                }

              for (k=0; k<CantEquipos-1; k++) // recorro los equipos
                        {
                        if (max<=contador[k]|| k==0)
                            {
                           max= contador[k];
                            flag=1;
                            }
                           }


              printf("\n-------------los equipos mas alquilados son %d veces", max);
              for (k=0; k<CantEquipos; k++) // recorro los equipos
                        {
                            if ( max==contador[k])
                            {
                            showOneEquip(equiposs[k]);
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
void promedioTiempoAlquiler(eAlquiler alquiler [] ,eEquipo equiposs [] , int CantAlquileres  ,  int CantEquipos )
{
      int i;
      int j;
       int k;
      float contador [CantEquipos] ;
      float acumulador [CantEquipos] ;
      float promedio [CantEquipos];

      int flag=0;
      int max ;

      for (i=0; i<CantEquipos; i++)
      {
          contador[i]=0;
          acumulador[i]=0;
      }


           for (i=0; i <CantAlquileres; i++) // recorro los alquileres realizados
                {
                  for (k=0; k<CantEquipos; k++) // recorro los equipos
                        {
                            if (alquiler[i].idEquipo== equiposs[k].idEquipo)
                            {
                            contador [k]++;

                            acumulador[k]=acumulador[k]+(alquiler [i].tiempoAlquiler-alquiler [i].tiempoReal) ;
                            }
                        }
                }


              for (k=0; k<CantEquipos; k++) // recorro los equipos
                        {

                          showOneEquip(equiposs[k]);

                          if (contador[k]>0)
                          {
                             promedio [k] = acumulador [k] /contador [k];
                              printf("\n---------------------------------El promedio de este equipos es %.2f", promedio [k]);

                          }
                          else
                            {
                            printf("\n------------------------------Equipo nunca alquilado");
                            }


                        }



}
