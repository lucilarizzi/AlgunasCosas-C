
#ifndef PROPIETARIOS_H
#define PROPIETARIOS_H

typedef struct
{
    int idPropietario;
    char nombreyApellido [40];
    char direccion [40];
    int status;
    char tarjetaCredito [20];

} ePropietario;


/** \brief ALTA DE CLIENTE
 *
 * \param array de estrcutrad de socio
 * \param tama�o del array
 * \return numero de index
 *
 */
int  altaCliente (ePropietario [], int );


/** \brief buscar el primer index vacion en la usuarios/cliente/socio
 *
 * \param array de estrcutrad de socio
 * \param tama�o del array
 * \return numero de index
 *
 */
int searchIndexUsers ( ePropietario [], int );

/** \brief lleva a CERO todo el indice de status de  la estrcutura usuario/cliente/socio
 *
 * \param estructura de usuarios/cliente/socio
 * \param tamanio total del array de usuarios/cliente/socio
 * \return
 *
 */
void indicePropietario(ePropietario[], int );


/** \brief Carga de Datos Inicial para poder operar
 *
 * \param estructura de usuarios/cliente/socio
 * \param tamanio total del array de usuarios/cliente/socio
 * \return
 *
 */
void cargarSocios(ePropietario [], int );


/** \brief mostrar listado de usuario/socio/cliente
 *
 * \param  array estrcutura de usuario/socio/cliente
 * \param  cantidad maxima de usuario/socio/cliente
 * \return
 *
 */
void listadoDePropietario (ePropietario [], int, int );

/** \brief mostrar 1 datos de 1 usuario/socio/cliente
 *
 * \param  un punto de la estrcutura de usuario/socio/cliente
 * \return
 *
 */
void showOneClient (ePropietario);



/** \brief DAR DE BAJA UN USUARIO PASANDO A 2 SU STATUS
 *
 * \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return
 *
 */
void bajaCliente(ePropietario [], int, int );


/** \brief modificacion de usuario/socio/cliente
 *
 * \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return
 * \return
 *
 */
 void modificarPropietario (ePropietario [], int, int );

 /** \brief Carga de Datos Inicial para poder operar
 *
 * \param estructura de usuarios/cliente/socio
 * \param tamanio total del array de usuarios/cliente/socio
 * \return
 *
 */
int cargarPropietario(ePropietario propietarios[], int tamanio);




#endif
