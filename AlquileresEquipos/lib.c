#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "lib.h"
#include "clientes.h"

/** \brief AMB DE CLIENTES
 *
 * \param ESTRUCTURA
 * \param CANT DE CLEINTES
 * \return SITUACION DE LA BASE
 *
 */
void  menuCliente(eClientes usuarioss[], int tamanio, int *flag )
{
    int i;
    int opcion;
    int usuariosParaHard;
    int auxflag=0;
do{

    printf( "\n\n\t 1- Alta\n"
            "\t 2- Baja \n\t 3- Modificacion \n"
            "\t 4- Hard X Clientes\n"
            "\t 5- Mostrar Clientes\n"
            "\t 0- Salir\tSeleccione la opcion: \t ");

    scanf("%d", &opcion);
    switch (opcion)
                {
                    case 1:
                        auxflag =altaCliente(usuarioss, tamanio, flag);
                        *flag=auxflag;
                        cleanScreen();
                        break;
                   case 2:
                        auxflag=*flag;
                        bajaCliente(usuarioss, tamanio,auxflag);
                        cleanScreen();
                        break;
                    case 3:
                        auxflag=*flag;
                        modificarCliente(usuarioss, tamanio, auxflag);
                        cleanScreen();
                        break;
                   case 4:
                        printf("\t Ingrese cuantos clientes desea harcodear: \t");
                        scanf("%d", &usuariosParaHard);
                          if (usuariosParaHard>tamanio)
                        {
                            printf("\t Ingrese un numero inferior a %d: \t",tamanio);
                            scanf("%d", &usuariosParaHard);
                        }
                        *flag=hardClientes(usuarioss, usuariosParaHard,tamanio, flag);
                        cleanScreen();
                        break;
                    case 5:
                        auxflag=*flag;
                        mostrarCliente(usuarioss, tamanio, auxflag);
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


/** \brief AMB DE EMPLEADOS
 *
 * \param ESTRUCTURA
 * \param CANT DE OPERADORES
 *
 *
 */

void  menuEmpleados(eEmpleados usuarioss[], int tamanio, int *flag )
{
    int i;
    int opcion;
    int usuariosParaHard;
    int auxflag=0;
do{

    printf( "\n\n\t 1- Alta\n"
            "\t 2- Baja \n\t 3- Modificacion \n"
            "\t 4- Hard X Operadores\n"
            "\t 5- Mostrar Clientes\n"
            "\t 0- Salir\tSeleccione la opcion: \t ");

    scanf("%d", &opcion);
    switch (opcion)
                {
                    case 1:
                        auxflag =altaEmpleado(usuarioss, tamanio, flag);
                        *flag=auxflag;
                        cleanScreen();
                        break;
                   case 2:
                        auxflag=*flag;
                        bajaEmpleado(usuarioss, tamanio,auxflag);
                        cleanScreen();
                        break;
                    case 3:
                        auxflag=*flag;
                        modificarEmpleado(usuarioss, tamanio, auxflag);
                        cleanScreen();
                        break;
                   case 4:
                        printf("\t Ingrese cuantos Operadores desea harcodear: \t");
                        scanf("%d", &usuariosParaHard);
                          if (usuariosParaHard>tamanio)
                        {
                            printf("\t Ingrese un numero inferior a %d: \t",tamanio);
                            scanf("%d", &usuariosParaHard);
                        }
                        *flag=hardEmpleados(usuarioss, usuariosParaHard,tamanio, flag);
                        cleanScreen();
                        break;
                    case 5:
                        auxflag=*flag;
                        mostrarEmpleados(usuarioss, tamanio, auxflag);
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
/** \brief MENU DE EQUIPOS
 *
 * \param
 * \param
 * \return
 *
 */

void  menuEquipos(eEquipo equiposs[], int tamanio, int *flag )
{
    int i;
    int opcion;
    int usuariosParaHard;
    int auxflag=0;
do{

    printf( "\n\n\t 1- Ingresar equipos nuevos\n"
            "\t 2- Dar de baja equipos \n\t 3- Modificacion Equipos \n"
            "\t 4- Hard X Equipos\n"
            "\t 5- Mostrar Equipamiento\n"
            "\t 0- Salir\tSeleccione la opcion: \t ");

    scanf("%d", &opcion);
    switch (opcion)
                {
                    case 1:
                        auxflag =altaEquipo(equiposs, tamanio, flag);
                        *flag=auxflag;
                        cleanScreen();
                        break;
                   case 2:
                        auxflag=*flag;
                        bajaEquipo(equiposs, tamanio,auxflag);
                        cleanScreen();
                        break;
                    case 3:
                        auxflag=*flag;
                        modificarEquipo(equiposs, tamanio, auxflag);
                        cleanScreen();
                        break;
                   case 4:
                        printf("\t Ingrese cuantos Operadores desea harcodear: \t");
                        scanf("%d", &usuariosParaHard);
                          if (usuariosParaHard>tamanio)
                        {
                            printf("\t Ingrese un numero inferior a %d: \t",tamanio);
                            scanf("%d", &usuariosParaHard);
                        }
                        *flag=hardEquipo(equiposs, usuariosParaHard,tamanio, flag);
                        cleanScreen();
                        break;
                    case 5:
                        auxflag=*flag;
                        mostrarEquipos(equiposs, tamanio, auxflag);
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

/** \brief MENU ALQUILERES
 *
 * \param
 * \param
 * \return
 *
 */
 void  menuAlquileres(eAlquiler alquiler[],eClientes clientes [],eEmpleados operadores [] ,eEquipo equiposs[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos)
  {
    int opcion;
    int auxflag=0;

do{
    printf( "\n\n\t 1- Alquilar Equipo\n"
            "\t 2- Devolucion de Equipo"
            "\n\t 3- Consultas \n"
            "\t 0- Salir\tSeleccione la opcion: \t ");

    scanf("%d", &opcion);
    switch (opcion)
                {
                    case 1:
                        alquilarEquipo(alquiler, clientes,operadores,equiposs,CantAlquileres, CantClientes, CantOperadores,CantEquipos);
                        cleanScreen();
                  break;
                 case 2:
                        devolucionEquipo(alquiler, clientes,operadores,equiposs,CantAlquileres, CantClientes, CantOperadores,CantEquipos);
                        cleanScreen();
                        break;
                /*    case 3:
                        auxflag=*flag;
                        modificarEquipo(equiposs, tamanio, auxflag);
                        cleanScreen();
                        break;
                   case 4:
                        printf("\t Ingrese cuantos Operadores desea harcodear: \t");
                        scanf("%d", &usuariosParaHard);
                          if (usuariosParaHard>tamanio)
                        {
                            printf("\t Ingrese un numero inferior a %d: \t",tamanio);
                            scanf("%d", &usuariosParaHard);
                        }
                        *flag=hardEquipo(equiposs, usuariosParaHard,tamanio, flag);
                        cleanScreen();
                        break;
                    case 5:
                        mostrarEquipos(equiposs, tamanio, auxflag);
                        cleanScreen();
                        break;
                        */

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



/** \brief LIMPIAR PANATALLA
 *
 * \param
 * \param
 * \return
 *
 */
void cleanScreen (void)
{
            printf("\n");
            system ("pause");
            system ("cls");
}

/** \brief Validacion S o N
 *
 * \param
 * \param
 * \return
 *
 */
 char ValidacionSiNo (char respuesta , char texto [])
{
    while (respuesta != 's' && respuesta !='n')
        {
        printf(" \n %s\t",texto);
        fflush(stdin);
        respuesta= tolower(getche());
        }

  return respuesta;
}

/** \brief VALIDAR DNI
 *
 * \param DNI
 * \return DNI VALIDADO
 *
 */
 int validarDNI (int dni)
 {
   while (dni<1000000||dni>100000000)
   {
   printf("Error! Ingrese una DNI valido entre 1.000.000 y 100.000.000:\t");
   scanf("%d", &dni);
   }
   return dni;
 }


 /** \brief VALIDAR EDAD
 *
 * \param EDAD
 * \return EDAD VALIDADO
 *
 */
 int validarEdad (int edad)
 {
    while (edad<0 || edad>100)
        {
        printf("Error! Ingrese una edad valida entre 1 y 99:\t");
        scanf("%d", &edad);
        }
         return edad;
 }
