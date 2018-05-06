

/** \brief LIMPIAR PANATALLA
 *
 */
void cleanScreen (void);

void cleanScreen (void)
{
            printf("\n");
            system ("pause");
            system ("cls");
}

/** \brief Validacion S o N
 *
 * \param respuesta recibida
 * \param texto de la validacion
 * \return respuesta
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

 /** \brief VALIDAR DNI
 *
 * \param DNI
 * \return DNI VALIDADO
 *
 */
 int validarDNI (int);

 int validarDNI (int dni)
 {
   while (dni<1000000||dni>100000000)
   {
   printf("Error! Ingrese una DNI valido entre 1.000.000 y 100.000.000:\t");
   scanf("%d", &dni);
   }
   return dni;
 }

  /** \brief PEDIR DNI
 *
 * \param DNI
 * \return DNI VALIDADO
 *
 */
 int pedirDNI (void);

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

  /** \brief PEDIR EDAD
 *
 * \return EDAD VALIDADO
 *
 */
 int pedirEdad (void)
 {
     int edad;
        printf("Ingrese una edad:\t");
        scanf("%d", &edad);
        while (edad<0 || edad>100)
            {
            printf("Error! Ingrese una edad valida entre 1 y 99:\t");
            scanf("%d", &edad);
            }
         return edad;
 }


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void indiceHArdAlquiler(eAlquiler alquiler[], int tamanio)
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
