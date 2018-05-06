
#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct
{
    char nombre [15];
    char apellido [15];
    int idCliente;
    int status;
    int dni;

} eClientes;

void menuCliente (eClientes[], int , int *);
int  altaCliente (eClientes users[], int tamanio, int flag);
int searchIndexUsers ( eClientes status[], int tamanio);
void indiceClientes(eClientes usuarios[], int tamanio);
void listadoDeClientes (eClientes users [], int tamanio);
void showOneClient (eClientes usuarios);
void mostrarCliente (eClientes users[], int tamanio, int flag);
int hardClientes(eClientes [], int,int, int );









#endif
