#ifndef AMBULANCIAS_H
#define AMBULANCIAS_H

typedef struct
{
    int idAmbu;
    int tiempo;
    int status;

} eAmbu;
/** \brief Alta Ambulancia
 *
 * \param Array ESTRUCTURA de llamadas
 * \param CANT DE llamadas
 * \param flag
 * \return flag
 *
 */
int altaAmbu (eAmbu [], int , int );

/** \brief buscar index
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
 * \return primer index disponible
 *
 */
int searchIndexAmbul( eAmbu status[], int tamanio);

/** \brief LLeva a todos los estatus a cero de ambulancias
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
 * \return
 *
 */
void indiceAmbus(eAmbu equipos[], int tamanio);

/** \brief precarga de informacion de ambulancias
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
 * \return
 *
 */
void cargarAmbus(eAmbu equipos[], int tamanio);

/** \brief mostrar 1 datos de 1 ambulancia
 *
 * \param ESTRUCTURA de ambulancias
 * \return
 *
 */
void showOneAmbu(eAmbu equipos);


/** \brief listado de ambulancias
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
 * \return
 *
 */
void listadoDeAmbus (eAmbu ambulan [], int tamanio);


/** \brief mostrar ambulancias
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
  * \param flag
 * \return
 *
 */
void mostrarAmbulancias (eAmbu ambulan [], int tamanio, int flag);

/** \brief Baja de ambulancia
 *
 * \param array ESTRUCTURA de ambulancias
 * \param CANT DE ambulancias
  * \param flag
 * \return
 *
 */
void bajaAmbulancia (eAmbu ambulan[], int tamanio, int flag);


#endif
