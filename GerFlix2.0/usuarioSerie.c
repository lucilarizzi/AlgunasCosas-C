#include "usuarioSerie.h"
#include "serie.h"
#include "usuario.h"

void CrearListadoUsuariosYSeries(eUsuarioSerie misRelaciones[])
{
    int i;

    int usuario[9]={100,100,100,100,101,101,101,102,102};
    int serie[9]={1,2,3,4,1,2,3,1,4};


    for(i=0;i<9;i++)
    {
       misRelaciones[i].idSerie=serie[i];
       misRelaciones[i].idUsuario=usuario[i];
    }
}


int displayMenuABM (char texto[])
{
    int opcion;

    printf("%s", texto);
    scanf("%d", &opcion);

    switch (opcion)
    {
        case 1:
            opcion=1;
            break;
        case 2:
            opcion=2;
            break;
        case 3:
            opcion=3;
            break;
        case 4:
            opcion=4;
            break;
        case 5:
            opcion=5;
            break;
        case 6:
            opcion =6;
            break;
        case 9:
            opcion=9;
            printf("\n");
            system ("cls");
            break;
        default:
            printf("no ha ingresado una opcion valida");
            printf("\n");
            system ("cls");
            break;

    }

    return opcion;
}


////////////////////////

void contarUsuariosPorSerie(eUsuarioSerie relaciones [], eUsuario usuarios [], eSerie series [])
{   int i;
    int j;
    int h;
    int contadorUser[5]={0};
    int auxContador;
    eSerie AuxSeries;

for (i=0; i<5;i++) // recorro las series
        {
            for (j=0;j<9;j++) // recorro las relaciones
                {
                if (relaciones[j].idSerie==series[i].idSerie )
                    {if (series[i].idSerie==series[i+1].idSerie || i== 0 )
                    {
         }
                     for (h=0; h<3; h++) // recorre los usuarios
                     {
                     if (relaciones[j].idUsuario == usuarios[h].idUsuario)
                     {
                     contadorUser[i]++;
                     break;
                                }
                            }
                        }
                    }
             }
 printf(" \n \nEl orden de las series menos vista\n");
       for (i=0; i<4;i++)
        {
           for (j=i+1; j<5;j++)
            {
                if (contadorUser[i]>contadorUser[j])
                {
                    auxContador=contadorUser[i];
                    AuxSeries=series[i];
                    contadorUser[i]=contadorUser[j];
                    series [i]=series[j];
                    contadorUser[j]=auxContador;
                    series [j]=AuxSeries;
                }
            }
        }
      for (i=0; i<5;i++)
        {
         if (i==0)
         {
              printf("  la serie %s tienen %d usuarios que la ven \n", series [i].nombre,contadorUser[i] );
         }
         if (series[0].idSerie==series[i].idSerie && i!=0)
         {
              printf(" la serie %s tienen %d usuarios que la ven \n", series [i].nombre,contadorUser[i] );
         }
        }
        printf("---------------------------------------------");
}

///////////////////////////


///////////////////////////////////// FUNCIONES
void allSerieForUser (eUsuarioSerie relaciones [], eUsuario usuarios [], eSerie series [])
{
    int i;
    int j;
    int h;

for (i=0; i<9;i++) // recorro las relaciones
        {
            for (j=0;j<3;j++) // recorre el usuario y se fija si el primer usuario es igual y lo imprime
            {
                if (relaciones[i].idUsuario==usuarios[j].idUsuario )
                    {
                            for (h=0; h<5; h++) // recorre las series y se fija si la primera es igual al id
                            {
                            if (relaciones[i].idSerie== series[h].idSerie)
                                {
                                if (h==0)
                                {
                                printf("\n Usuario: %s \t \n" , usuarios[j].nombre);
                                }
                                printf("  Serie: %s \n" , series[h].nombre);
                                break;
                                }
                            }

                         break;
                        }
                    }


             }

             }




////////////

void allUserforSeries(eUsuarioSerie relaciones [], eUsuario usuarios [], eSerie series [])
{
    int i;
    int j;
    int h;

for (i=0; i<5;i++) // recorro las series
        {
            for (j=0;j<9;j++) // recorro las relaciones
            {
                if (relaciones[j].idSerie==series[i].idSerie )
                            for (h=0; h<3; h++) // recorre los usuarios
                            {
                            if (relaciones[j].idUsuario== usuarios[h].idUsuario)
                                {
                                if (h==0)
                                {
                                printf("\n Serie: %s \t \n" , series[i].nombre);
                                }
                                printf(" Usuario: %s \n" , usuarios[h].nombre);
                                break;

                                }

                            }

            }
        }

}



void top3series(eUsuarioSerie relaciones [], eUsuario usuarios [], eSerie series [])
{

    int i;
    int j;
    int h;
    int contadorUser[5]={0};
    int auxContador;
    eSerie AuxSeries;

for (i=0; i<5;i++) // recorro las series
        {
            for (j=0;j<9;j++) // recorro las relaciones
            {
                if (relaciones[j].idSerie==series[i].idSerie )
                    {
                            for (h=0; h<3; h++) // recorre los usuarios
                            {
                            if (relaciones[j].idUsuario== usuarios[h].idUsuario)
                                {
                                contadorUser[i]++;
                                break;

                                }

                            }

                        }
                    }

             }


 printf(" \n \nEL TOP 3 ES :\n");

       for (i=0; i<4;i++)
        {
           for (j=i+1; j<5;j++)
        {
            if (contadorUser[i]<=contadorUser[j])
            {
                auxContador=contadorUser[i];
                AuxSeries=series[i];
                contadorUser[i]=contadorUser[j];
                series [i]=series[j];
                contadorUser[j]=auxContador;
                series [j]=AuxSeries;

            }
        }

        }

      for (i=0; i<3;i++)
        {

            printf(" El nro %d del top es %s y tiene %d usuarios que la ven \n",(i+1) , series[i].nombre, contadorUser[i]);
        }


        printf("---------------------------------------------");




}
////////////////////////
void  searchUser (eUsuarioSerie relaciones [], eUsuario usuarios [], eSerie series [])
{
    int i;
    int j;
    int h;
    int auxUser;

    printf(" Listado de Usuarios\n");
    for (i=0; i<3;i++)
    {
        showOneUser(usuarios[i]);
    }

    printf("\n \n \tVer series del nro de usuario:\t");
    scanf("%d", &auxUser);
    printf("\n");

    for (i=0; i<9;i++) // recorro las series
        {
            if (relaciones [i].idUsuario==auxUser)
            {
            for (j=0;j<5;j++) // recorro las relaciones
            {
               if (relaciones[i].idSerie== series[j].idSerie)
                    {
                        showOneSerie(series [j] );
                         break;
                    }

                            }

                        }
                    }
 printf("\n-----------------------------------------------------\n");
}

/////////////////////////////

void  searchSerie (eUsuarioSerie relaciones [], eUsuario usuarios [], eSerie series [])
{
    int i;
    int j;
    int h;
    int aux;

    printf(" Listado de Series\n");
    for (i=0; i<5;i++)
    {
        showOneSerie(series[i]);
    }

    printf("\n \n \tIngrese el nro de series  que desea ver los usuarios \t");
    scanf("%d", &aux);
    printf("\n");


    for (i=0; i<9;i++) // recorro las series
        {
            if (relaciones[i].idSerie==aux)
            {
                for (j=0;j<3;j++) // recorro las relaciones
                {
                   if (relaciones[i].idUsuario== usuarios[j].idUsuario)
                        {
                            showOneUser(usuarios[j] );
                             break;
                        }

                }

            }
        }
         printf("\n");

}

//////////////////////////////////
void cleanScreen (void)
{
            printf("\n");
            system ("pause");
            system ("cls");
}

