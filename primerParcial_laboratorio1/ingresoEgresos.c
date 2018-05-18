///////////// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "funciones.h"
#include "propietarios.h"
#include "ingresoEgresos.h"

#define Alpha_Romeo 1
#define Ferrari 2
#define Audi 3
#define Otro 4


/** \brief niicializa los estados a cero
 *
 * \param array de estrcutura
 * \param  tamanio del arrau
 * \return
 *
 */
void indiceIngresoyEgreso(eIngresoyEgreso ingresos [], int tamanio)
{
     int i;
    for (i=0 ; i<tamanio;i++)
    {
    ingresos[i].status=0;
    ingresos [i].idPropietario= 0;

     }
}

/** \brief carga inicial de ingresos para poder operar
 *
 * \param array de estrcutura
 * \param  tamanio del arrau
 * \return
 *
 */
int cargarIngresos(eIngresoyEgreso ingresos [], int tamanio)
{
    int i;
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA010","CCC020","DDD020","BBB040","ZZZ050","III666","HHH555","EEE635","FFF987","GGG123"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    for (i=0 ; i<tamanio;i++)
    {
    ingresos [i].idPropietario=propietario[i];
    strcpy(ingresos [i].patente,patente[i]);
    ingresos [i].marca=marca[i];
    ingresos[i].idIngresoEgreso=id[i];
    ingresos[i].status=1;
    }


    return 1;
   }

/** \brief recibir ingreso
 *
 * \param ARRAY ESTRUCTURA de ingresos
 * \param ARRAY ESTRUCTURA de propiestarioss
 * \param CANT DE ingresos
 * \param CANT DE propiestarios
 * \return
 *
 */
 void recibiringreso(eIngresoyEgreso ingreso [], ePropietario propiestarios[],int CantLugares, int CantPropietarios, int flag)
    {
     int i;
     int j;
     int idClienteAux;
     int auxMarca;
     int flagProp=0;
     int flagIndex=0;


for (i=0; i <CantLugares; i++) // recorro los lugares disponible
{
    if (ingreso[i].status==0) // busco el indice disponible  de ingreso
    {
        flagIndex=1;

        listadoDePropietario(propiestarios, CantPropietarios, flag);
        printf("\n\nIngrese el id del propietario ingresante :");
        scanf("%d", &idClienteAux);

        for(j=0; j<CantPropietarios;j++) //recorro propietarios
        {
            if(propiestarios[j].idPropietario== idClienteAux)
            {
                flagProp=1;

                ingreso[i].status=1;
                ingreso [i].idIngresoEgreso =i+1;

                ingreso[i].idPropietario=propiestarios[j].idPropietario;
                printf("Ingrese la patente:\t");
                fflush(stdin);
                gets(ingreso[i].patente);

                do{
                printf("\n 1- Alpha_Romeo");
                printf("\n 2- Ferrari");
                printf("\n 3- Audi");
                printf("\n 4- Otro");
                printf("\nIngrese la marca:\t");
                scanf("%d", &auxMarca);

                switch (auxMarca)
                          {
                            case 1:
                            ingreso[i] .marca=1;
                            break;
                            case 2:
                            ingreso[i] .marca=2;
                            break;
                            case 3:
                            ingreso[i] .marca=3;
                            break;
                            case 4:
                            ingreso[i] .marca=4;
                            break;
                            default:
                            printf("\n opcion incorrecta\t");
                            auxMarca=0;
                            break;
                            }
                } while (auxMarca==0);
                 break;
            }

            }
       if (flagProp==0)
        {
          printf("\n\n=========== el propietario no existe ==============");
        }
            break;
        }


    }
    if (flagIndex==0)
    {
          printf("\n\n=========== NO HAY LUGAR DISPONIBLE ==============");
    }
    else if (flagProp==1)
    {
    printf("\n\n=========== AUTO INGRESADO ==============");
    }



 }




/** \brief recorre propiestarios, busca LA ingreso , LA DA POR FINALIZADA
 *
 * \param ARRAY ESTRUCTURA de ingresos
 * \param ARRAY ESTRUCTURA de propiestarioss
 * \param CANT DE ingresos
 * \param CANT DE propiestarios
 * \return
 *
 */
void egresarAuto(eIngresoyEgreso ingresoss[], ePropietario cliente[],int CantLugares, int CantPropietarios)
  {
      int j;
      int m;
      int idClienteAux;
      int auxTiempo;
      int flag=0;
      int auxProp [20];

   auxTiempo=devolverHorasEstadia();

    listaringreso(ingresoss, CantLugares);

    printf("\n\nIngrese el id de INGRESO que desea dar de baja :");
    scanf("%d", &idClienteAux);
       for (j=0; j<CantLugares; j++) // recorro los clientes
        {
           if (idClienteAux==ingresoss[j].idIngresoEgreso && ingresoss[j].status==1) // si el cliente es igual al que busco
                {
                flag=1;
                ingresoss[j].status=2;
                ingresoss[j].tiempoTranscurrido =devolverHorasEstadia();
                switch (ingresoss[j].marca)
                {
                case 1:
                    ingresoss[j].totalPagado =ingresoss[j].tiempoTranscurrido*150;
                    break;
                case 2:
                    ingresoss[j].totalPagado=ingresoss[j].tiempoTranscurrido*175;
                    break;
                case 3:
                    ingresoss[j].totalPagado=ingresoss[j].tiempoTranscurrido*200;
                    break;
                case 4:
                    ingresoss[j].totalPagado=ingresoss[j].tiempoTranscurrido*250;
                    break;
                }


                for (m=0; m<CantPropietarios; m++)
                {
                    if (ingresoss[j].idPropietario==cliente[m].idPropietario)
                    {
                            strcpy(auxProp,cliente[m].nombreyApellido);
                            break;
                    }
                }


                mostraringreso(ingresoss[j]);
                printf("\n---------------------------");
                printf("\nEl propietario es:%10s",auxProp);
                printf("\nTiempo transcurrido:%6d Hrs", ingresoss[j].tiempoTranscurrido);
                printf("\nEl Monto a abonar :$%8d", ingresoss[j].totalPagado);
                printf("\n---------------------------");


                printf("\n\n=========== EGRESO FINALIZADO ==============\n");
                break;
                }




          }
    if (flag==0)
         {
             fflush(stdin);
             printf("\n\n=========== No existe el ingreso ==============\n");
         }
}


/** \brief MOSTRAR 1 ingreso
 *
 * \param array de estrcutura DE ingreso
 * \param  tamanio del arraY
 * \return
 *
 */
 void mostraringreso (eIngresoyEgreso ingreso)
  {
     char auxMarca [20];
     switch (ingreso.marca)
     {
         case 1:
         strcpy(auxMarca, "Alpha");
         break;
         case 2:
         strcpy(auxMarca, "Ferrari");
         break;
         case 3:
         strcpy(auxMarca, "Audi");
         break;
         case 4:
         strcpy(auxMarca, "Otro");
         break;
     }

     printf("\nIngreso: %3d  Prop: %8d Marca: %8s  Estado %d " ,ingreso.idIngresoEgreso , ingreso.idPropietario, auxMarca , ingreso.status);
 }


 /** \brief LISTADO DE ingresos
 *
 * \param array de estrcutura DE ingreso
 * \param  tamanio del arraY
 * \return
 *
 */
 void listaringreso (eIngresoyEgreso ingreso [], int tamanio)
 {
      int i;
      printf("\n\n\n========================\n AUTOS INGRESADOS \n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (ingreso[i].status==1)
                    {
                        mostraringreso(ingreso[i]);
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

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}


void menuConsulta(eIngresoyEgreso ingresoss[], ePropietario cliente[],int CantLugares, int CantPropietarios, int flag)
{

     int opcion =-1;

        do
        {
        printf("\n===== Menu de Consultas =======\n");
        printf ("\n 1- Recaudacacion Total");
        printf ("\n 2- Recaudacion Total Por Marca");
        printf ("\n 3- Buscar Propietario por ID y sus Patentes estacionadas");
        printf ("\n 4- Todos los datos de los propietarios cuyos autos"
                "\n    estacionados sean de la marca AUDI");
        printf ("\n 5- Listado de autos estacionados con sus propietarios,"
                "\n    ordenado por patente");
        printf ("\n 0- Salir");
        printf ("\n\n\t Ingrese la opcion deseada:  ");
        scanf("%d", &opcion);

    switch (opcion)
        {
        case 1:
            printf("\n \t============ Recaudacacion Total ================ \n");
            recaudacionTotal(ingresoss, CantLugares);
            cleanScreen();
            break;
        case 2 :
            printf("\n \t============ Recaudacion Total Por Marca ================ \n");
            recaudacionTotalPorMarca(ingresoss, CantLugares);
            cleanScreen();
            break;
         case 3:
            printf("\n ============ Buscar Propietario por ID y sus Patentes estacionadas ================ \n");
            buscarPropySusPatentes (cliente, ingresoss, CantPropietarios, CantLugares, flag);
            cleanScreen();
            break;
        case 4:
            printf("\n ========= Propietarios cuyos autos estacionados sean de la marca AUDI =========\n");
            buscarAudi (cliente, ingresoss, CantPropietarios, CantLugares);

            cleanScreen();
            break;
        case 5:
            printf("\nListado de autos estacionados con sus propietarios, ordenado por patente\n");
            printf("\n ==================================================================== \n");
            autosPorPatente(cliente, ingresoss, CantPropietarios, CantLugares);
            cleanScreen();
            break;
         case 0:
            printf("\n ============ Usted ha salido ================ \n");
            break;
         default:
            printf("\n-----------no ha ingresado una opcion valida---------------\n");
            fflush(stdin);
            cleanScreen();
            break;
        }
    } while (opcion !=0);
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void recaudacionTotal(eIngresoyEgreso ingresoss[], int CantLugares)
 {
     int i;
     int acumulador=0;

     for (i=0; i<CantLugares; i++)
     {

         if (ingresoss[i].status==2)
         {
             acumulador=acumulador+ ingresoss[i].totalPagado;
         }

     }

     printf("\n\tEl monto total recaudado hasta el momento es $%d\n \n", acumulador);


 }


  int recaudacionTotalPorMarca(eIngresoyEgreso ingresoss[], int CantLugares)
 {
     int i;
     int acumulador1=0;
     int acumulador2=0;
     int acumulador3=0;
     int acumulador4=0;
     int acumuladorTotal=0;

     for (i=0; i<CantLugares; i++)
     {

         if (ingresoss[i].status==2)
         {
             switch (ingresoss[i].marca)
             {
             case 1:
                acumulador1=acumulador1+ingresoss[i].totalPagado;
                break;
             case 2:
                acumulador2=acumulador2+ingresoss[i].totalPagado;
                break;
             case 3:
                acumulador3=acumulador3+ingresoss[i].totalPagado;
                break;
             case 4:
                acumulador4=acumulador4+ingresoss[i].totalPagado;
                break;
             }
             acumuladorTotal=acumuladorTotal+ ingresoss[i].totalPagado;
         }

     }

     printf("\n\tEl monto recaudado por la marca Alpha_Romeo hasta el momento es $%d\n ", acumulador1);
     printf("\n\tEl monto recaudado por la marca Ferrari  hasta el momento es $%d\n ", acumulador2);
     printf("\n\tEl monto recaudado por la marca Audio hasta el momento es $%d\n \n", acumulador3);
     printf("\n\tEl monto recaudado por la marca Otro hasta el momento es $%d\n \n", acumulador4);
     printf("\n\tEl monto TOTAL recaudado hasta el momento es $%d\n \n", acumuladorTotal);


 }


void buscarPropySusPatentes (ePropietario propieta [] , eIngresoyEgreso ingresos [] ,int CantPropietarios,int CantLugares, int flag)
{
    int i;
    int j;
    int auxProp;
    int flag2=0;

    listadoDePropietario(propieta, CantPropietarios, flag );
    printf("\n Ingrese el numero de id del propietario que desea ver las patentes");
    scanf("%d", &auxProp);

     for (i=0; i < CantPropietarios; i++)
     {

         if (propieta[i].idPropietario  ==auxProp)
         {
             flag2=1;
             for (j=0; j<CantLugares; j++)
                {
                    if (ingresos[j].idPropietario== propieta[i].idPropietario)
                    {
                        printf("\n la patente del propietario es %s", ingresos[j].patente);

                    }
                }//fin for J
         } //ir propieda.idprop

     }
                if (flag2==0)
                    {

                    printf("\n\n=====================================\n");
                    printf("PROPIETARIO NO EXISTE");
                    printf("\n=====================================\n");

                     }


}

void buscarAudi (ePropietario propieta [] , eIngresoyEgreso ingresos [] ,int CantPropietarios,int CantLugares)
{
    int i;
    int j;

    for (i=0; i <CantLugares; i++)
     {
         if (ingresos[i].marca == 3 && ingresos[i].status==1)
        {
            printf("\nSe registro un AUDI en el ingreso nro %d:" , ingresos[i].idIngresoEgreso);

             for (j=0; j<CantPropietarios; j++)
                {
                    if (ingresos[i].idPropietario== propieta[j].idPropietario && propieta[j].status==1)
                    {
                    showOneClient(propieta[j]);
                    printf("\n");
                    printf("\n");
                    }
                }//fin for J
         } //ir propieda.idprop

     }



}


void autosPorPatente(ePropietario propieta [] , eIngresoyEgreso ingresos [] ,int CantPropietarios,int CantLugares)
{
    int i;
    int j;
    eIngresoyEgreso auxIngreso[CantLugares];
        eIngresoyEgreso aux;


    for (i=0; i <CantLugares-1; i++)
     {
         auxIngreso[i]=ingresos[i];
     }



    for (i=0; i <CantLugares-1; i++)
     {
            for (j=i+1; j<CantLugares; j++)
            {
               if(stricmp(auxIngreso[i].patente, auxIngreso[j].patente)>0)
               {
                   aux= auxIngreso[i];
                   auxIngreso[i]=auxIngreso[j];
                   auxIngreso[j]=aux;
               } //if
            }//for j
     }// for i

    for (i=0; i <CantLugares; i++)
     {
         if (auxIngreso[i].status==1)
            {
            printf("\nDominio: %s",auxIngreso[i].patente);
            for (j=0; j<CantPropietarios; j++)
            {
               if(auxIngreso[i].idPropietario==propieta[j].idPropietario && auxIngreso[i].status==1 && propieta[j].status==1)
               {
                  showOneClient(propieta[j]);
                  printf("\n");
               } //if
            }//for j
            }
     }// for i



}


/** \brief DAR DE BAJA UN USUARIO PASANDO A 2 SU STATUS
 *
 * \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return
 *
 */

void bajaCliente(eIngresoyEgreso ingresoss [], ePropietario users[], int tamanio,int CantLugares, int flag)
{
int flagDelete;
int i;
int j;
int m;
char auxProp[20];
int idAux;
int confirm;

     if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY PROPIETARIOS CARGADOS\n======================\n");
            }
        else
            {
                listadoDePropietario(users, tamanio, flag);
                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id del propietario que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                flagDelete=0;
                        for (i=0; i<tamanio;i++)
                            {
                                if (users[i].idPropietario== idAux&& users [i].status==1)
                                    {
                                     confirm =preguntarSiNo("Seguro que desea borrar el socio:\t");
                                     flagDelete=1;
                                      if (confirm == 's')
                                        {
                                        users[i].status=0;
/////////////////////////////////////////////////
                                       for (j=0; j<CantLugares; j++) // recorro los clientes
                                        {
                                       if (users[i].idPropietario==ingresoss[j].idPropietario && ingresoss[j].status==1) // si el cliente es igual al que busco
                                            {
                                            strcpy(auxProp,users[i].nombreyApellido);
                                            ingresoss[j].status=2;
                                            ingresoss[j].tiempoTranscurrido =devolverHorasEstadia();
                                            switch (ingresoss[j].marca)
                                            {
                                            case 1:
                                                ingresoss[j].totalPagado =ingresoss[j].tiempoTranscurrido*150;
                                                break;
                                            case 2:
                                                ingresoss[j].totalPagado=ingresoss[j].tiempoTranscurrido*175;
                                                break;
                                            case 3:
                                                ingresoss[j].totalPagado=ingresoss[j].tiempoTranscurrido*200;
                                                break;
                                            case 4:
                                                ingresoss[j].totalPagado=ingresoss[j].tiempoTranscurrido*250;
                                                break;
                                            }


                                            printf("\n\n\n-- TICKET PENDIENTE DE PAGO--\n");
                                            mostraringreso(ingresoss[j]);
                                            printf("\nTiempo transcurrido:%6d Hrs", ingresoss[j].tiempoTranscurrido);
                                            printf("\nEl Monto a abonar :$%8d", ingresoss[j].totalPagado);
                                            printf("\n---------------------------");
                                            }
                                        } //fin for j


////////////////////////////////////////////////////////////////////
                                        printf("\n\n======================================\n");
                                        printf("Usuario borrado: %s , con el Id  Nro: %d", users[i].nombreyApellido, users[i].idPropietario);
                                        printf("\n======================================\n");
                                        flagDelete=1;
                                        break;
                                        } //fin if si
                                        else
                                        {
                                        printf("\n\n==========================================\n");
                                        printf("Operacion Cancelada");
                                        printf("\n==========================================\n");
                                        break;
                                        } //if no
                                     }

                                    } //fin for I


                        }    // fin else =!0

                if (flagDelete==0)
                         {
                             fflush(stdin);

                            printf("\n\n=====================================\n");
                            printf("PROPIETARIO NO EXISTE");
                            printf("\n=====================================\n");

                         }


}





