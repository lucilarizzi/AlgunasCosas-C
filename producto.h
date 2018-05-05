#ifndef PRODUCTO_H
#define PRODUCTO_H

typedef struct
{
    char nombre [30];
    float precio;
    int idProducto;
    int stock;
    int ventas;
    int status;

}eProducto;



void menuProducto (eProducto product[], int tamanio, int *flag);
void indiceProducto (eProducto prod[], int tamanio);
void bajaProducto (eProducto producto[], int tamanio, int *flag);
void hardProducto (eProducto losProductos[], int tamanio, int *flag);
void showOneProduct(eProducto proodu);
int searchIndexProducto ( eProducto status[], int tamanio);
void  altaProducto (eProducto productos[], int tamanio, int *flag);
void mostrarProducto (eProducto productoo[], int tamanio, int *flag);
void mostrarProductoDadoBaja(eProducto producto[], int tamanio, int *flag);

 #endif
