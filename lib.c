///////////// LIBRERIAS PERSONALIZADAS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

///////////// LIBRERIAS PERSONALIZADAS
 #include "lib.h"
 #include "usuarios.h"
 #include "producto.h"


/** \brief Funcion para Loggueo con Usuario y Password, permite carga de usuario y salir del sistema
 *
 * \param Array de estructura de usuario
 * \param Cantidad de Usuarios totales del sistema
 * \return Un numero entero de Respuesta al menu de opciones que entra al switch en el main
 *
 */

int logIn (eUsuario users[] , int CantUsuario)
{
 int i;
 int j;
 int auxId;
 char auxPas [12];
 int flag=0;


   printf ("\n \n\n SI NO TIENE USUARIO INGRESE 5555");
   printf ("\n \n\n PARA SALIR INGRESE USUARIO 9999");
   printf("\n Ingrese su user id :\t");
   scanf("%d", &auxId);

    if (auxId== 9999)
        {
           flag=2;
           printf("\n ============ Usted ha salido ================ \n");
          }

   else if (auxId==5555)
        {
           flag=3;
           printf("\n ============ Area alta de usuarios ================ \n");
        }

  else
    {
       printf ("\n Ingrese su clave :\t");
       fflush(stdin);
       gets(auxPas);


        for (i=0; i <CantUsuario;i++)
        {

         if (users[i].idUsuario == auxId && strncmp(users[i].password, auxPas, 12)==0)//&& users[i].password == auxPas)
            {
                 flag=1;
                 printf("\n ============ WELCOME ================ \n");
               break;
            }


          }

      }

      return flag;
    }

/** \brief MENU GENERAL
 *
 * \param
 * \param
 * \return
 *
 */

 int menuGeneral (eUsuario users [], eProducto productos []; int cantUsuarios, int cantProducto)
 {
     int flagProducto=0;
     int opcion;

 while (opcion !=0)
    {
    printf( "\n--- Menu General---\n\n"
              " 1-  Menu de Usuario "
            "\n 2-  Menu de Productos"
            "\n 3-  Comprar producto"
            "\n 4-  Listar Publicaciones de Usuario "
            "\n 5-  Listar Publicaciones "
            "\n 6-  Listar usuarios\n \n 0-  SALIR!"
            "\t \t Ingrese la opcion deseaba:\t");
            scanf("%d", &opcion);

            switch (opcion)
                {
                case 1:
                    menuUsuario(users, cantUsuario, &flagUsuarios);
                    cleanScreen();
                    break;
                case 2:
                    menuProducto(productos, cantProduct, &flagProducto);
                    cleanScreen();
                    break;
                case 3:
                    comprarProducto (productos, users,relaciones, cantProduct, cantUsuario, &flagProducto, &flagUsuarios);
                    cleanScreen();
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
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
    }
    cleanScreen();

    return flagUsuario;
 }



void indiceRelaciones (eRelaciones relaciones[], int tamanio)
{

    int i;
    for (i=0 ; i<tamanio;i++)
    {
    relaciones[i].status=0;
     }

}




/** \LIMPIA LA PANTALLA
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
        printf(" \n %s :\t",texto);
        fflush(stdin);
        respuesta= tolower(getche());
        }

  return respuesta;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void comprarProducto (eProducto productos [], eUsuario usuarios[] , eRelaciones compras[], int CantProduct, int CantUsuario, int *flagPro, int *flagUs)

  {
      int i;
      int auxUS;
      int auxProd;
       int j;
       int flagss=0;
       int h;


 if (*flagUs!=0)
    {
    listadoDeUsuarios(usuarios, CantUsuario);
    printf("\n \tIngrese el su ID de Usuario :\t");
    scanf("%d", &auxUS);

      for (i=0; i<CantUsuario; i++)
      {
            if (usuarios[i].idUsuario==auxUS /*&& productos[i].stock!=0*/)
            {
                for (j=0; j<(CantProduct*CantUsuario);j++)
                   {
                       if (compras[j].status==0)
                        {
                       break;
                        }
                    }
            break;
            }
      }


            if (*flagPro==1)
                 {
                 listadoDeProductos(productos, CantProduct);
                 printf("\n \tIngrese el ID del Producto que quiere comprar :\t");
                 scanf("%d", &auxProd);

                 for (h=0; h<CantProduct; h++)
                 {
                   if (productos[h].idProducto==auxProd && productos[h].stock>0)
                   {
                        compras[j].idProducto=productos[i].idProducto;
                        compras[j].idUsuario=usuarios[i].idUsuario;
                        productos[i].stock--;
                        flagss=1;
                        break;
                    }
                 }
                if (flagss==0)
                {
                printf("\n NO HAY STOCK DEL PRODUCTO QUE DESEA COMPRAR \n");
                printf("-----------------------------------------------\n");
                }
                else
                {
                printf("eL Usuario %d  Compro el Producto %d -- (p) Stock %d -- NOMBRE %s", compras[j].idUsuario, compras[j].idProducto, productos[h].stock, productos[h].nombre);
                }

                 }
        else
                 {
        printf(" \n-----------------------------------------------------" );
        printf("\n         No hay Productos Disponibles\n");
        printf(" \n     *** NO SE PUEDEN REALIZAR COMPRAR ***\n" );
        printf("----------------------------------------------------- \n" );
            }



}
else
{

    printf(" \n-----------------------------------------------------" );
    printf("\n           No hay Usuarios cargados \n");
     printf(" \n     *** NO SE PUEDEN REALIZAR COMPRAR ***\n" );
     printf("----------------------------------------------------- \n" );
}





    }





