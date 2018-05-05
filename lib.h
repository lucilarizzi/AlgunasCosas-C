#include "usuarios.h"
#include "producto.h"




typedef struct
{
    int idUsuario;
    int idProducto;
    int calificacion;
    int status;

}eRelaciones;



int displayMenuABM (char texto[]);
void cleanScreen (void);
char ValidacionSiNo (char , char []);
void comprarProducto (eProducto  [], eUsuario [] , eRelaciones [],int, int, int * , int *);
void indiceRelaciones (eRelaciones [], int tamanio);
int logIn (eUsuario users[] , int CantUsuario);
