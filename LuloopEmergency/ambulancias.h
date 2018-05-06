#ifndef AMBULANCIAS_H
#define AMBULANCIAS_H

typedef struct
{
    int idAmbu;
    int tiempo;
    int status;

} eAmbu;

void cargarAmbus(eAmbu equipos[], int tamanio);
void indiceAmbus(eAmbu equipos[], int tamanio);
void showOneAmbu(eAmbu equipos);
int searchIndexAmbul( eAmbu status[], int tamanio);
void listadoDeAmbus (eAmbu ambulan [], int tamanio);
void mostrarAmbulancias (eAmbu ambulan [], int tamanio, int flag);
void bajaAmbulancia (eAmbu ambulan[], int tamanio, int flag);
int altaAmbu (eAmbu ambulan[], int tamanio, int flag);

#endif
