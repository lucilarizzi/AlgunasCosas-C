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

void menuCliente (eSocio[], int , int *);
int  altaCliente (eSocio users[], int tamanio, int flag);
int searchIndexUsers ( eSocio status[], int tamanio);
void indiceSocio(eSocio usuarios[], int tamanio);
void listadoDeSocio (eSocio users [], int tamanio);
void showOneClient (eSocio usuarios);
void mostrarCliente (eSocio users[], int tamanio, int flag);
int hardClientes(eSocio [], int,int, int );



#endif
