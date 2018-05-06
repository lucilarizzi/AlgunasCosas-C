#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct{
    int idUsuario;
    char nombre[50];
}eUsuario;

void CrearListadoDeTresUsuarios(eUsuario MisUsuarios[]);
void showOneUser (eUsuario lolo);
void listarUsuario (eUsuario[], int);

#endif // USUARIO_H_INCLUDED
