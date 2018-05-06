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
void  menuCliente(eSocio[], int, int *);

/** \brief MENU DE ambulancias
 *
 * \param ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
 * \return SITUACION DE LA BASE
 *
 */
void  menuAmbulancias(eAmbu[], int , int * );

/** \brief MENU LLAMADAS
 *
 * \param ESTRUCTURA de llamadas
 * \param ESTRUCTURA de socios
 * \param ESTRUCTURA de ambulancias
 * \param CANT DE llamadas
 * \param CANT DE socio
 * \param CANT DE ambulancias
 * \return
 *
 */
void  menuLlamadas(eLlamados[], eSocio[], eAmbu[],int , int ,int );

#endif
