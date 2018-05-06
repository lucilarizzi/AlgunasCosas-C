#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

/** \brief AMB DE SOCIOS
 *
 * \param ESTRUCTURA
 * \param CANT DE CLEINTES
 * \return SITUACION DE LA BASE
 *
 */
void  menuCliente(eSocio socioss[], int tamanio, int *flag )
{
    int i;
    int opcion;
    int paraHard;
    int auxflag=0;
do{

    printf( "\n\n\t 1- Alta\n"
            "\t 2- Baja \n\t 3- Modificacion \n"
            "\t 4- Hard X Socios\n"
            "\t 5- Mostrar Socios\n"
            "\t 0- Salir\tSeleccione la opcion: \t ");
            scanf("%d", &opcion);
    switch (opcion)
                {
                    case 1:
                        auxflag =altaCliente(socioss, tamanio, flag);
                        *flag=auxflag;
                        cleanScreen();
                        break;
                   case 2:
                        auxflag=*flag;
                        bajaCliente(socioss, tamanio,auxflag);
                        cleanScreen();
                        break;
                    case 3:
                        auxflag=*flag;
                        modificarCliente(socioss, tamanio, auxflag);
                        cleanScreen();
                        break;
                   case 4:
                        printf("\t Ingrese cuantos socios desea harcodear: \t");
                        scanf("%d", &paraHard);
                          if (paraHard>tamanio)
                        {
                            printf("\t Ingrese un numero inferior a %d: \t",tamanio);
                            scanf("%d", &paraHard);
                        }
                        *flag=hardClientes(socioss, paraHard,tamanio, flag);
                        cleanScreen();
                        break;
                    case 5:
                        auxflag=*flag;
                        mostrarCliente(socioss, tamanio, auxflag);
                        cleanScreen();
                        break;
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

/** \brief MENU DE ambulancias
 *
 * \param
 * \param
 * \return
 *
 */

void  menuAmbulancias(eAmbu ambuss[], int tamanio, int *flag )
{
    int i;
    int opcion;
    int paraHard;
    int auxflag=0;
do{

    printf( "\n\n\t 1- Ingresar equipos nuevos\n"
            "\t 2- Dar de baja Ambulancia \n"
            "\t3- Mostrar Ambulancias\n"
            "\t 0- Salir\tSeleccione la opcion: \t ");

    scanf("%d", &opcion);
    switch (opcion)
                {
                    case 1:
                        auxflag =altaAmbu(ambuss, tamanio, flag);
                        *flag=auxflag;
                        cleanScreen();
                        break;
                   case 2:
                        auxflag=*flag;
                        bajaAmbulancia(ambuss, tamanio,auxflag);
                        cleanScreen();
                        break;
                    case 3:
                        auxflag=*flag;
                        mostrarAmbulancias(ambuss, tamanio, auxflag);
                        cleanScreen();
                        break;
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


 /** \brief PEDIR DNI
 *
 * \param DNI
 * \return DNI VALIDADO
 *
 */
int pedirDNI (void)
 {
    int dni;
    printf("Ingrese una DNI\t");
   scanf("%d", &dni);

   while (dni<1000000||dni>100000000)
   {
   printf("Error! Ingrese una DNI valido entre 1.000.000 y 100.000.000:\t");
   scanf("%d", &dni);
   }
   return dni;
 }

 /** \brief Pregunta S o N
 * *
 * \param texto de la pregunta
 * \return respuesta
 *
 */
 char preguntarSiNo ( char texto [])
 {
     char respuesta;

     printf("%s S o N:", texto);
     fflush(stdin);
     respuesta= tolower(getche());

    while (respuesta != 's' && respuesta !='n')
        {
        printf(" \nRespuesta Incorrecta-%s\t",texto);
        fflush(stdin);
        respuesta= tolower(getche());
        }

  return respuesta;
}



/** \brief LIMPIAR PANATALLA
 *
 */

void cleanScreen (void)
{
            printf("\n");
            system ("pause");
            system ("cls");
}


/** \brief MENU LLAMADAS
 *
 * \param
 * \param
 * \return
 *
 */
void  menuLlamadas(eLlamados llama[],eSocio soci [],eAmbu ambulan[],int CantLlamadas, int CantSocios,int CantAmbulancias)
  {
    int opcion;
    int auxflag=0;

do{
    printf( "\n\n\t 1- Recibir Llamado\n"
            "\t 2- Finzalizar LLamados"
            "\n\t 3- Consulta Nombre y Apellido del asociados con mas LLAmados"
             "\n\t 4- Consulta los motivos mas frecuentes"
             "\n\t 5- Que motivo mas demora "
             "\n\t 6- MOdificar llamada"

            "\t 0- Salir\tSeleccione la opcion: \t ");

    scanf("%d", &opcion);
    switch (opcion)
                {
                    case 1:
                        recibirLlamado(llama, soci,ambulan,CantLlamadas, CantSocios,CantAmbulancias);
                        cleanScreen();
                        break;
                 case 2:
                        finzalarLlamada(llama, soci,ambulan,CantLlamadas, CantSocios,CantAmbulancias);
                        cleanScreen();
                        break;/*
                case 3:
                      consultaMejorCliente(llama, soci,operadores,ambulan,CantLlamadas, CantSocios, CantOperadores,CantAmbulancias);
                      cleanScreen();
                      break;
                   case 4:
                       consultaEquipoMasAlquilado (llama, ambulan, CantLlamadas, CantAmbulancias);
                        cleanScreen();
                        break;
                  case 5:
                        promedioTiempoAlquiler(llama, ambulan, CantLlamadas, CantAmbulancias) ;
                        cleanScreen();
                        break;

*/
                    case 6:
                        modificarLlamada(llama, soci,ambulan,CantLlamadas, CantSocios,CantAmbulancias);
                        cleanScreen();
                        break;
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

