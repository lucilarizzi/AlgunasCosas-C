///////////// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funciones.h"
#include "propietarios.h"
#include "ingresoEgresos.h"

#define Alpha_Romeo 1
#define Ferrari 2
#define Audio 3
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
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    for (i=0 ; i<tamanio;i++)
    {
    ingresos [i].idPropietario=propietario[i];
    strcpy(ingresos [i].patente,patente[i]);
    ingresos [i].marca=marca[i];
    ingresos[i].idIngresoEgreso=id[i];
    ingresos[i].hora=devolverHorasEstadia();
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
     int k;
     int l;
     int m;
     int n;
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
                ingreso[i].hora=devolverHorasEstadia();

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
                printf("\n 3- Audio");
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
    else
    {
    printf("\n\n=========== AUTO INGRESADO ==============");
    }



 }


 /** \brief FINALIZAR ingreso
 *
 * \param ARRAY ESTRUCTURA de ingresos
 * \param ARRAY ESTRUCTURA de propiestarioss
 * \param CANT DE ingresos
 * \param CANT DE propiestarios
 * \return
 *
 */
 void finzalarIngreso(eIngresoyEgreso ingreso [], ePropietario propiestarios[],int CantLugares, int CantPropietarios)
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

    flag=egresarAuto(ingreso, propiestarios,CantLugares, CantPropietarios);
    if (flag==0)
         {
             printf("\n\n=========== No existe la ingreso ==============\n");
         }
    else
         {


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
int egresarAuto(eIngresoyEgreso ingresoss[], ePropietario cliente[],int CantLugares, int CantPropietarios)
  {
      int i;
      int j;
       int m;
      int precioFinal;
      int idClienteAux;
      int auxTiempo;
      int flag=0;
      int tiempoTotal;
      int auxProp [20];

   auxTiempo=devolverHorasEstadia();

    listaringreso(ingresoss, CantLugares);

    printf("\n\nIngrese el id de INGRESO que desea dar de baja :");
    scanf("%d", &idClienteAux);

       for (j=0; j<CantLugares; j++) // recorro los clientes
        {
           if (idClienteAux==ingresoss[j].idIngresoEgreso) // si el cliente es igual al que busco
                {
                flag=1;
                ingresoss[j].status=2;

                //EMITIR TICKET
                tiempoTotal= auxTiempo-ingresoss[j].hora;
                switch (ingresoss[j].marca)
                {
                case 1:
                    precioFinal=tiempoTotal*150;
                    break;
                case 2:
                    precioFinal=tiempoTotal*175;
                    break;
                case 3:
                    precioFinal=tiempoTotal*200;
                    break;
                case 4:
                    precioFinal=tiempoTotal*250;
                    break;
                }
                ingresoss[j].totalPagado=precioFinal;

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
                printf("\nEl propietario es %s",auxProp);
                printf("\nLa cantidad de tiempo transcurrido es %d", tiempoTotal);
                printf("\nEl Monto a abonar %d", precioFinal);
                printf("\n---------------------------");


                printf("\n\n=========== EGRESO FINALIZADO ==============\n");
                break;
                }




          }
          return flag;
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
         strcpy(auxMarca, "Alpha_Romeo");
         break;
         case 2:
         strcpy(auxMarca, "Ferrari");
         break;
         case 3:
         strcpy(auxMarca, "Audi");
         break;
         case 4:
         strcpy(auxMarca, "Audi");
         break;
     }

     printf("\nIngreso: %d\ Propietario: %d Marca: %s Hr Ingreso:%d  Estado %d " ,ingreso.idIngresoEgreso , ingreso.idPropietario, auxMarca ,ingreso.hora, ingreso.status);
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


void menuConsulta(eIngresoyEgreso ingresoss[], ePropietario cliente[],int CantLugares, int CantPropietarios)
{

     int opcion =-1;

        do
        {
        printf("\n===== BIENVENIDO Al Menu de Consultas =======\n\n");
        printf ("\n 1- Recaudacacion Total");
        printf ("\n 2- Recaudacion Total Por Marca");
        printf ("\n 3- Buscar Propietario por ID y sus Patentes estacionadas");
        printf ("\n 4- Todos los datos de los propietarios cuyos autos estacionados sean de la marca AUDI");
        printf ("\n 5- Listado de autos estacionados con sus propietarios, ordenado por patente");
        printf ("\n 0- Salir");
        printf ("\n\n\t Ingrese la opcion deseada:  ");
        scanf("%d", &opcion);

    switch (opcion)
        {
        case 1:
            printf("\n \t============ Recaudacacion Total ================ \n");

            cleanScreen();
            break;
        case 2 :
            printf("\n ============ Recaudacion Total Por Marca ================ \n");

            cleanScreen();
            break;
         case 3:
            printf("\n ============ Buscar Propietario por ID y sus Patentes estacionadas ================ \n");

            cleanScreen();
            break;
        case 4:
            printf("\n \t============ Todos los datos de los propietarios cuyos autos estacionados sean de la marca AUDI ================ \n");

            cleanScreen();
            break;
        case 5:
            printf("\n \t============ Listado de autos estacionados con sus propietarios, ordenado por patente ================ \n");

            cleanScreen();
            break
         case 0:
            printf("\n ============ Usted ha salido ================ \n");
            break;
         default:
            printf("no ha ingresado una opcion valida");
            printf("\n");
            system ("cls");
            break;
    }
}
