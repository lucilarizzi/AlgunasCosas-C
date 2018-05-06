#ifndef LIB_H
#define LIB_H

#include "ambulancias.h"
#include "socio.h"
#include "llamados.h"


 /** \brief PEDIR DNI
 *
 * \param DNI
 * \return DNI VALIDADO
 *
 */
int pedirDNI (void);

/** \brief Pregunta S o N
 * *
 * \param texto de la pregunta
 * \return respuesta
 *
 */
 char preguntarSiNo ( char texto []);


/** \brief LIMPIAR PANATALLA
 *
 */
void cleanScreen (void);


/** \brief AMB DE SOCIOS
 *
 * \param ESTRUCTURA
 * \param CANT DE CLEINTES
 * \return SITUACION DE LA BASE
 *
 */
void  menuCliente(eSocio socioss[], int tamanio, int *flag );

void  menuAmbulancias(eAmbu [], int , int * );

void  menuLlamadas(eLlamados llama[],eSocio soci [],eAmbu ambulan[],int CantLlamadas, int CantSocios,int CantAmbulancias);

#endif
