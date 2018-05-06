#ifndef ALQUILERES_H
#define  ALQUILERES_H

#include "clientes.h"
#include "empleados.h"
#include"equipo.h"

typedef struct
{
int idAlquiler;
int idCliente;
int idEquipo;
int idOperador;
int tiempoAlquiler;
char status [10];

}eAlquiler;

void indiceAlquiler(eAlquiler alquiler[], int tamanio);
void alquilarEquipo(eAlquiler alquiler[], eClientes cliente[],eEmpleados operador[] ,eEquipo equipo[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos);
void devolucionEquipo(eAlquiler alquiler[], eClientes cliente[],eEmpleados operador[] ,eEquipo equipo[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos);

#endif
