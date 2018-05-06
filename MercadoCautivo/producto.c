#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "producto.h"

#define CantUsuario 100
#define CantProduct 1000



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void menuProducto (eProducto product[], int tamanio, int *flag)
{
    int i;
    int opcion;
    int productParaHard;
    int auxflag=0;

    do{
      cleanScreen();
       printf( "\n \n \t--Menu de Productos--\n"
              "\t 1- Alta  \n\t 2- Baja \n"
              "\t 3- Modificacion \n"
              "\t 4- Hard X Productos\n"
              "\t 5- Mostrar Productos\n"
              "\t 7- Mostrar productos,dado de baja\n"
              "\t 8- Borrar definitivamente los productos dados de baja\n\n"
              "\t 0- Salir\tSeleccione la opcion: \t ");
              scanf("%d", &opcion);
        switch (opcion)
                    {
                    case 1:
                        *flag=auxflag;
                        altaProducto(product, tamanio, &auxflag);
                        break;
                    case 2:
                        *flag=auxflag;
                        bajaProducto(product, tamanio, &auxflag);
                        break;
                  case 3:
                      *flag=auxflag;
                      modificarProducto(product, tamanio, &auxflag);
                        break;
                    case 4:
                        *flag=auxflag;
                        printf("\t Ingrese cuantos productos desea harcodear: \t");
                        scanf("%d", &productParaHard);
                        if (productParaHard>CantProduct)
                        {
                            printf("\t Ingrese un numero inferior a %d: \t",CantProduct);
                            scanf("%d", &productParaHard);
                        }
                        hardProducto(product, productParaHard, &auxflag);
                       break;
                    case 5:
                    *flag=auxflag;
                    mostrarProducto(product, tamanio, &auxflag);
                        break;
                   case 7:
                    mostrarProductoDadoBaja(product, tamanio, &auxflag);
                        break;
                  case 8:
                      ////////////////////HACER
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
cleanScreen();
}
/** \brief Establece los status a cero
 *
 * \param
 * \param
 * \return
 *
 */
void indiceProducto (eProducto producttt[], int tamanio)
{

    int i;
    for (i=0 ; i<tamanio;i++)
    {
    producttt[i].status=0;
    }

}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void hardProducto (eProducto losProductos[], int tamanio, int *flag)
{
    int i;
    int contaHard=0;
    int contarUnos=0;
    int contarCero=0;
    for(i=0;i<tamanio;i++)
    {
        if (losProductos[i].status==0)
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
        if (losProductos[i].status==0)
        {
        losProductos[i].idProducto=i+301;
        strcpy(losProductos[i].nombre,"hard producto");
        losProductos[i].status=1;
        losProductos[i].precio =i*5;
        losProductos[i].stock=i+i;

        *flag=1;
        contaHard++;
        }
    }


    printf(" \n-----------------------------");
    printf(" %d Hards Cargados", contaHard);
    printf(" -----------------------------");
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void showOneProduct(eProducto proodu)
{
 printf("\nIdProducto %d \t    Nombre: %s        Precio:%.2f --stock : %d" , proodu.idProducto,proodu.nombre,proodu.precio, proodu.stock);
}


int searchIndexProducto ( eProducto status[], int tamanio)
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


void  altaProducto (eProducto productos[], int tamanio, int *flag)
{
    int seguir='s';
    int index;
    while (seguir == 's')
        {
            index=searchIndexProducto(productos, tamanio);
            if (index != -1)
                {
              //  printf("\n\n---PRUEBA DE INDEX %d \t STATUS %d\n",index, productos[index].status);

                productos[index].idProducto=index+101;
                printf("\n \nel ID de la Producto es %d \n", productos[index].idProducto);

                printf("Ingrese el nombre del usuario:\t");
                fflush(stdin);
                gets(productos[index].nombre);

                printf("Ingrese el Precio\t");
                scanf("%f", &productos[index].precio);

                printf("Ingrese el Stock Inicial\t");
                scanf("%f", &productos[index].stock);

                *flag=1;
                productos[index].status=1;

                printf("\t \t Cargar otro producto? S-N\t");
                fflush(stdin);
                seguir= getche();
                seguir = ValidacionSiNo(seguir,"\n Respuesta Incorrecta - Cargar otro producto? S-N");

                }
            else
                {
                printf("\n\n\n===========================\n CUPO DE PRODUCTOS LLENO\n===========================\n");
                break;
                }
        }
        cleanScreen();
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarProducto (eProducto productoo[], int tamanio, int *flag)
{
    int i;
    if(*flag==0)
            {
                printf("\n\n\n======================\n NO HAY PRODUCTOS CARGADOS\n======================\n");
            }
            else
            {  printf("\n\n\n========================\n PRODUCTOS CARGADOS\n========================\n");
                for (i=0; i<tamanio; i++)
                {

                    if(productoo[i].status==1)
                    {
                    showOneProduct(productoo[i]);
                        if ((i+1)%25==0 && i!=0)
                        {  {
                            printf("\n");
                            system ("pause");
                            }
                        }
                    }

                }
                printf("\n========================================================================\n");
            }
        cleanScreen();

}


/** \brief DAR DE BAJA UN USUARIO PASANDO A 2 SU STATUS
 *
 * \param
 * \param
 * \return
 *
 */

void bajaProducto (eProducto producto[], int tamanio, int *flag)
{
int flagDelete;
int i;
int idAux;
int confirm;

     if(*flag==0)
            {
                printf("\n\n\n======================\n NO HAY PRODUCTOS CARGADOS\n======================\n");
            }
        else
            {
              // listadoDep(users, tamanio);
                printf("\n========================================================================\n");

                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id del producto que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                        for (i=0; i<tamanio;i++)
                            {
                                if (producto[i].idProducto== idAux)
                                    {
                                    printf(" \nSeguro que desea borrar la IdUser %s ? S/N\t", producto[i].nombre);
                                    fflush(stdin);
                                    confirm= tolower(getche());
                                   confirm =ValidacionSiNo(confirm," Respuesta incorrecta - Seguro que desea borrar el producto %d:\t", producto[i].nombre);
                                    break;
                                    }
                            }
               if (confirm == 's')
               {
                   flagDelete=0;
                   for (i=0; i<tamanio;i++)
                    {
                        if (producto[i].idProducto== idAux)
                            {
                            producto[i].status=2;
                            printf("\n\n======================================================\n");
                            printf("Producto borrado: %s, con el Id  Nro: %d", producto[i].nombre, producto[i].idProducto);
                            printf("\n======================================================\n");
                            flagDelete=1;
                            break;
                            }
                    }
                if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("El producto que desea borrar no existe");
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
        cleanScreen();
}


/** \brief MOSTRAR USUARIOS DADOS DE BAJA
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarProductoDadoBaja(eProducto producto[], int tamanio, int *flag)
{
    int i;
    if(*flag==0)
            {
                printf("\n\n\n======================\n NO HAY USUARIOS CARGADOS\n======================\n");
            }
            else
            {  printf("\n\n\n========================\n USUARIOS DADO DE BAJA\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if(producto[i].status==2)
                    {
                    showOneProduct(producto[i]);
                    }

                }
                printf("\n----------------------------------------------------------------\n");
            }
        cleanScreen();

}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


 void modificarProducto (eProducto producto[], int tamanio, int *flag)
 {
     int i;
     int idAux;
     int confirm;
     int flagchange=0;
     int opcion;
     float auxPrecio;

              if(*flag==0)
                    {
                printf("\n\n=====================================\n");
                printf("NO HAY PRODUCTOS CARGADOS");
                printf("\n=====================================\n");
                    }
            else
            {
               listadoDeProductos(producto, tamanio);
               printf("\n===================================================================================\n");
               printf("\n\n Ingrese el Id del Producto que desea Modificar:\t");
               scanf("%d", &idAux);

               for (i=0; i<tamanio;i++)
                            {
                                if (producto[i].idProducto== idAux)
                                    {
                                    printf(" \nSeguro que desea modificar el Usuario %s ? S/N\t", producto[i].nombre);
                                    fflush(stdin);
                                    confirm= tolower(getche());
                                    confirm =ValidacionSiNo(confirm," Respuesta incorrecta - Seguro que desea modificar el usuario %d:\t", producto[i].nombre);
                                    break;
                                    }
                            }

                flagchange=0;

                for (i=0; i<tamanio;i++)
                {
                    if (producto[i].idProducto == idAux)
                        {
                        printf("\n \nEl usuario a modificar es");
                        showOneProduct(producto[i]);

                        printf("\n=========================\nOPCIONES \n 1- Nombre \n 2- Precio \n \t \t Que dato desea modificar?\t");
                        scanf ("%d", &opcion);
                        switch(opcion)
                                {
                                case 1:
                                     printf("\n Ingrese el nuevo nombre\t");
                                     fflush(stdin);
                                     gets(producto[i].nombre);
                                     break;
                                case 2:
                                      printf("\n Ingrese nuevo precio\t");
                                      scanf("%f", &producto[i].precio);
                                     break;
                                }

                        printf("\n\n\n======================\n Serie modificada\n======================\n");
                        flagchange=1;
                        showOneProduct(producto[i]);
                        break;
                        }
                }
            }
        cleanScreen();

 }

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void listadoDeProductos (eProducto produ[], int tamanio)
 {
      int i;
      printf("\n\n\n========================\n PRODUCTO CARGADOS\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (produ[i].status==1)
                    {
                        showOneProduct(produ[i]);
                    }

                }
 }

