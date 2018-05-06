/** \brief Menu ABM de Personas
 *
 * \param Estrucura de Usuario
 * \param Cantidad de Usuario
 * \return Flag con puntero de Menu Principal
 *
 */


void  menuCliente(eClientes [], int , int *); //usuarios

void  menuCliente(eClientes usuarioss[], int tamanio, int *flag )
{
    int i;
    int opcion;
    int usuariosParaHard;
    int auxflag=0;
do{

    printf( "\n\n\t 1- Alta\n"
            "\t 2- Baja \n"
            "\t 3- Modificacion \n"
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


/** \brief MENU COSAS
 *
 * \param
 * \param
 * \return
 *
 */
 void  menuEquipos (eEquipo[], int, int *); //objetos

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

/** \brief MENU RELACIONES
 *
 * \param
 * \param
 * \return
 *
 */
 void  menuAlquileres(eAlquiler [], eClientes [],eEmpleados [] ,eEquipo[],int,int,int,int);

 void  menuAlquileres(eAlquiler alquiler[],eClientes clientes [],eEmpleados operadores [] ,eEquipo equiposs[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos)
  {
    int opcion;
    int auxflag=0;

do{
    printf( "\n\n\t 1- Alquilar Equipo\n"
            "\t 2- Devolucion de Equipo"
            "\n\t 3- Consulta Nombre y Apellido del asociados con mas alquileres"
             "\n\t 4- Consulta los equipos mas alquilados"
             "\n\t 5- Tiempo Promedio real de alquiler"
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
                case 3:
                      consultaMejorCliente(alquiler, clientes,operadores,equiposs,CantAlquileres, CantClientes, CantOperadores,CantEquipos);
                      cleanScreen();
                      break;
                   case 4:
                       consultaEquipoMasAlquilado (alquiler, equiposs, CantAlquileres, CantEquipos);
                        cleanScreen();
                        break;
                  case 5:
                        promedioTiempoAlquiler(alquiler, equiposs, CantAlquileres, CantEquipos) ;
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




