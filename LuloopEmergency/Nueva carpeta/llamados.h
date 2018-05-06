#ifndef LLAMADOS_H
#define LLAMADOS_H

#include "socio.h"
#include"ambulancias.h"
#include"lib.h"


#define motivo1 "INFARTO"
#define motivo2 "ACV"
#define motivo3 "GRIPE"
#define estado1 "PENDIENTE"
#define estado2 "CUMPLIDO"


typedef struct
{
int idLlamado;
int idSocios;
char motivo [10];
int tiempoAsignacion;
float promedioTiempo;
char status [10];

}eLlamados;

void indiceLlamados(eLlamados [], int tamanio);
void alquilarEquipo(eLlamados [], eSocio [],eAmbu[],int , int ,int ,int );
void devolucionEquipo(eLlamados [], eSocio[],eAmbu [],int , int ,int ,int );
void consultaMejorCliente(eLlamados [], eSocio [],eAmbu [],int , int ,int ,int );
int clienteLlamadosPeoducto(eLlamados[], eSocio [],eAmbu [],int , int ,int ,int );
void consultaEquipoMasAlquilado (eLlamados [] ,eAmbu e[] , int ,  int  );
void promedioTiempoAlquiler (eLlamados [] ,eAmbu[] , int ,  int  );


#endif
