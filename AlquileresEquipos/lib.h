#ifndef LIB_H
#define LIB_H

#include "clientes.h"
#include "empleados.h"
#include"equipo.h"
#include"alquileres.h"

char ValidacionSiNo (char, char[]);
void cleanScreen (void);
int validarEdad (int);
int validarDNI (int);
void  menuCliente(eClientes [], int , int *);
void  menuEmpleados(eEmpleados [], int, int *);
void  menuEquipos (eEquipo[], int, int *);
void  menuAlquileres(eAlquiler [], eClientes [],eEmpleados [] ,eEquipo[],int,int,int,int);


#endif
