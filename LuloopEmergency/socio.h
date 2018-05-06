#ifndef SOCIO_H
#define SOCIO_H

typedef struct
{
    char nombre [20];
    char apellido [15];
    int idSocio;
    int status;
    int dni;
    int edad;

} eSocio;

/** \brief ALTA DE CLIENTE
 *
 * \param array de estrcutrad de socio
 * \param tamaño del array
 * \return numero de index
 *
 */
int  altaCliente (eSocio users[], int tamanio);


/** \brief buscar el primer index vacion en la usuarios/cliente/socio
 *
 * \param array de estrcutrad de socio
 * \param tamaño del array
 * \return numero de index
 *
 */
int searchIndexUsers ( eSocio status[], int tamanio);

/** \brief lleva a CERO todo el indice de status de  la estrcutura usuario/cliente/socio
 *
 * \param estructura de usuarios/cliente/socio
 * \param tamanio total del array de usuarios/cliente/socio
 * \return
 *
 */
void indiceSocio(eSocio usuarios[], int tamanio);


/** \brief Carga de Datos Inicial para poder operar
 *
 * \param estructura de usuarios/cliente/socio
 * \param tamanio total del array de usuarios/cliente/socio
 * \return
 *
 */
void cargarSocios(eSocio usuarios[], int tamanio)


/** \brief mostrar listado de usuario/socio/cliente
 *
 * \param  array estrcutura de usuario/socio/cliente
 * \param  cantidad maxima de usuario/socio/cliente
 * \return
 *
 */
void listadoDeSocio (eSocio users [], int tamanio);

/** \brief mostrar 1 datos de 1 usuario/socio/cliente
 *
 * \param  un punto de la estrcutura de usuario/socio/cliente
 * \return
 *
 */
void showOneClient (eSocio usuarios);


 /** \brief mostrar listado de usuario/socio/cliente
 *
 * \param  array estrcutura de usuario/socio/cliente
 * \param  cantidad maxima de usuario/socio/cliente
  * \param  flag general de carga de usuarios;
 * \return
 *
 */
void mostrarCliente (eSocio users[], int tamanio, int flag);


/** \brief DAR DE BAJA UN USUARIO PASANDO A 2 SU STATUS
 *
 * \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return
 *
 */
void bajaCliente(eSocio users[], int tamanio, int flag);

/** \brief modificacion de usuario/socio/cliente
 *
 * \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return
 * \return
 *
 */
 void modificarCliente (eSocio users[], int tamanio, int flag);


/** \brief HARD USUARIOS
*
* \param array estructura de usuario/socio/cliente
* \param tamanio de usuario/socio/cliente
* \param Cantidad de hards a realziar
* \param flag de prexistencia de carga de usuario/socio/cliente
* \return flag;
*
*/
 int hardClientes(eSocio MisUsuarios[], int tamanio, int CantCli, int flag);


#endif
