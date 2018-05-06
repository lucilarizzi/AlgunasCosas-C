#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "equipo.h"
#include "lib.h"


/** \brief ALTA DE Empleado
 *
 * \param
 * \param
 * \return
 *
 */
int  altaEquipo (eEquipo equipo[], int tamanio, int flag)
{
    int seguir='s';
    int index;
    while (seguir == 's')
        {
            index=searchIndexEquipment(equipo, tamanio);
            if (index != -1)
                {
                printf("\n\n---PRUEBA DE INDEX %d \t STATUS %d\n\n",index, equipo[index].status);

                equipo[index].idEquipo =index+50;
                printf("\n \nel ID del Equipo es %d \n", equipo[index].idEquipo);

                printf("Ingrese el tipo:\t");
                fflush(stdin);
                gets(equipo[index].tipo);

                printf("Ingrese la marca:\t");
                fflush(stdin);
                gets(equipo[index].marca);

                equipo[index].status=1;
                flag=1;

                printf("\t \t Cargar otro Equipamiento? S-N\t");
                fflush(stdin);
                seguir= getche();
                seguir = ValidacionSiNo(seguir,"\n Respuesta Incorrecta - Cargar otro Equipo? S-N");
                return flag;
                }
            else
                {
                printf("\n\n\n===========================\n CUPO DE Equipamiento LLENO\n===========================\n");
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
int searchIndexEquipment( eEmpleados status[], int tamanio)
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
void indiceEquipos(eEquipo equipos[], int tamanio)
{
    int i;
    for (i=0 ; i<tamanio;i++)
    {
    equipos[i].status=0;
     }


  for(i=0;i<10;i++)
    {

       if (i<3)
        {
        equipos[i].idEquipo=i+40;
        strcpy(equipos[i].tipo,"TALADRO");
        strcpy(equipos[i].marca,"Black & Decker");
        equipos[i].status=1;
        }

      /*  else if (i%2==0)
        {
        equipos[i].idEmpleado=i+30;
        strcpy(equipos[i].nombre,"Lucila");
        strcpy(equipos[i].apellido ,"Lopez");
        equipos[i].status=1;
        }
        else
        {
        equipos[i].idEmpleado=i+10;
        strcpy(equipos[i].nombre,"Ana");
        strcpy(equipos[i].apellido,"Gomez");
        equipos[i].status=1;
        }
*/
    }


}

/** \brief mostrar 1 datos de 1 clientes
 *
 * \param
 * \param
 * \return
 *
 */
  void showOneEquip(eEquipo equipos)
{
 printf("\nIdEquipo %d \t Tipo: %s  Marca: %s \t e:%d"  , equipos.idEquipo , equipos.tipo , equipos.marca, equipos.status);
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
  void listadoDeEquipos (eEquipo equipo [], int tamanio)
 {
      int i;
      printf("\n\n\n========================\n Equipos CARGADOS\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (equipo[i].status==1)
                    {
                        showOneEquip(equipo[i]);
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

void mostrarEquipos (eEquipo equipo [], int tamanio, int flag)
{
    int i;
            if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY Equipos CARGADOS\n======================\n");
            }
            else
            {
                listadoDeEquipos(equipo, tamanio);
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


void bajaEquipo (eEquipo equipo[], int tamanio, int flag)
{
int flagDelete;
int i;
int idAux;
int confirm;

     if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY Equipos CARGADOS\n======================\n");
            }
        else
            {
               listadoDeEquipos(equipo, tamanio);
                printf("\n========================================================================\n");

                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id del equipo que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                        for (i=0; i<tamanio;i++)
                            {
                                if (equipo[i].idEquipo== idAux)
                                    {
                                    printf(" \nSeguro que desea borrar a %s %s ? S/N\t", equipo[i].tipo, equipo[i].marca);
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
                        if (equipo[i].idEquipo== idAux)
                            {
                            equipo[i].status=0;
                            printf("\n\n======================================\n");
                            printf("Equipo borrado: %s %s, con el Id  Nro: %d", equipo[i].tipo, equipo[i].marca, equipo[i].idEquipo);
                            printf("\n======================================\n");
                            flagDelete=1;
                            break;
                            }
                    }
                if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("El equipo que desea borrar no existe");
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

 void modificarEquipo (eEquipo equipo[], int tamanio, int flag)
 {
     int i;
     int idAux;
     int confirm;
     int flagchange=0;
     int opcion;

              if(flag!=0)
               {
               listadoDeEquipos(equipo, tamanio);
               printf("\n===================================================================================\n");
               printf("\n\n Ingrese el Id del Equipo que desea Modificar:\t");
               scanf("%d", &idAux);

               for (i=0; i<tamanio;i++)
                            {
                                if (equipo[i].idEquipo== idAux)
                                    {
                                    printf(" \nSeguro que desea modificar el Equipo %s de %s ? S/N\t", equipo[i].tipo , equipo[i].marca );
                                    fflush(stdin);
                                    confirm= tolower(getche());
                                    confirm =ValidacionSiNo(confirm," Respuesta incorrecta - Seguro que desea modificar el Equipo :\t");
                                    break;
                                    }
                            }

                flagchange=0;
                if( confirm == 's')
                    {
                for (i=0; i<tamanio;i++)
                {
                    if (equipo[i].idEquipo == idAux)
                        {
                        printf("\n \nEl Equipo a modificar es");
                        showOneEquip(equipo[i]);

                        printf("\n=========================\n \nOPCIONES \n 1- Tipo \n 2- Marca\n \t \t Que dato desea modificar?\t");
                        scanf ("%d", &opcion);
                        switch(opcion)
                                {
                                case 1:
                                     printf("\n Ingrese el nuevo tipo\t");
                                     fflush(stdin);
                                     gets(equipo[i].tipo);
                                     break;
                                case 2:
                                    printf("\n Ingrese el nuevo apellido\t");
                                      fflush(stdin);
                                     gets(equipo[i].marca);
                                     break;
                                  }

                        printf("\n\n\n======================\n Equipo modificado\n======================\n");
                        flagchange=1;
                        showOneEquip(equipo[i]);
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
                printf("NO HAY Equipo CARGADOS");
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
 int hardEquipo(eEquipo MisEquipos[], int tamanio, int CantEqui, int flag)
{
    int i;
    int contaHard=0;
    int contarUnos=0;
    int contarCero=0;

    for(i=0;i<CantEqui;i++)
    {
        if (MisEquipos[i].status==0)
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
        if (MisEquipos[i].status==0)
        {
        MisEquipos[i].idEquipo=i+999;
        strcpy(MisEquipos[i].tipo,"GRUA");
        strcpy(MisEquipos[i].marca,"ROJOYVERDE");
        MisEquipos[i].status=1;
        flag=1;
        contaHard++;
        }
    }


    printf(" \n-----------------------------");
    printf(" %d Hards Cargados", contaHard);
    printf(" -----------------------------");


    return flag;
}


