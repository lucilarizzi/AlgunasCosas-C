#ifndef LLAMADOS_H
#define LLAMADOS_H

#include "socio.h"
#include"ambulancias.h"

#define motivo1 "INFARTO"
#define motivo2 "ACV"
#define motivo3 "GRIPE"
#define estado1 "PENDIENTE"
#define estado2 "CUMPLIDO"

typedef struct
{
int idLlamado;
int idSocios;
int idAmbulancia;
char motivo [20];
float tiempoAsignacion;
float tiempoDevolucion;
float promedioTiempo;
char status [10];

} eLlamados;


/** \brief niicializa los estados a cero
 *
 * \param array de estrcutura
 * \param  tamanio del arrau
 * \return
 *
 */

void indiceLlamados(eLlamados [], int tamanio);

/** \brief carga inicial de llamados para poder operar
 *
 * \param array de estrcutura
 * \param  tamanio del arrau
 * \return
 *
 */
void cargarLlamados(eLlamados llamadas [], int tamanio);

/** \brief recibir llamado
 *
 * \param ARRAY ESTRUCTURA de llamadas
 * \param ARRAY ESTRUCTURA de socios
 * \param ARRAY ESTRUCTURA de ambulancias
 * \param CANT DE llamadas
 * \param CANT DE socio
 * \param CANT DE ambulancias
 * \return
 *
 */
void recibirLlamado(eLlamados [], eSocio [],eAmbu[],int , int ,int );

 /** \brief FINALIZAR LLAMADO
 *
 * \param ARRAY ESTRUCTURA de llamadas
 * \param ARRAY ESTRUCTURA de socios
 * \param ARRAY ESTRUCTURA de ambulancias
 * \param CANT DE llamadas
 * \param CANT DE socio
 * \param CANT DE ambulancias
 * \return
 *
 */
void finzalarLlamada(eLlamados [], eSocio [],eAmbu[],int , int ,int );

/** \brief recorre SOCIO, busca LA LLAMADA , LA DA POR FINALIZADA
 *
 * \param ARRAY ESTRUCTURA de llamadas
 * \param ARRAY ESTRUCTURA de socios
 * \param ARRAY ESTRUCTURA de ambulancias
 * \param CANT DE llamadas
 * \param CANT DE socio
 * \param CANT DE ambulancias
 * \return
 *
 **/
   int buscarLlamado(eLlamados llamadass[], eSocio cliente[],eAmbu equipo[],int CantLlamadas, int CantSocios,int CantAmbulancias);

   /** \brief MOSTRAR 1 LLAMADO
 *
 * \param ESTRUCTURA DE LLAMADA
 * \param
 * \return
 *
 */
 void mostrarLlamado (eLlamados llamado);


 /** \brief LISTADO DE LLAMADAS
 *
 * \param array de estrcutura DE LLAMADA
 * \param  tamanio del arraY
 * \return
 *
 */
 void listarLlamado (eLlamados llamado [], int tamanio);


 /** \brief MODIFICAR LOS DATOS DE UNA LLAMADA
 *
 * \param ARRAY ESTRUCTURA de llamadas
 * \param ARRAY ESTRUCTURA de socios
 * \param ARRAY ESTRUCTURA de ambulancias
 * \param CANT DE llamadas
 * \param CANT DE socio
 * \param CANT DE ambulancias
 * \return
 *
 */
 void modificarLlamada(eLlamados llamada[], eSocio socio[],eAmbu ambu[],int CantLlamadas, int CantSocios,int CantAmbulancia);


 /** \brief ACCESORIA A MODIFICAR LLAMADA, PARA MODIFICAR EL MOTIVO
*
*/
void ingresarMotivo (eLlamados llamada);

#endif
