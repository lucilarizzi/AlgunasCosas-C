#ifndef USUARIOS_H
#define USUARIOS_H


typedef struct
{
    char nombre [30];
    char password [12];
    int idUsuario;
    int status;
    float promCalif;
    int edad;
    int fechaNacimiento[3];
    char sexo;

} eUsuario;

typedef struct
{
    int dia;
    int mes;
    int anio;

} eNacimiento;


void menuUsuario (eUsuario users[], int tamanio, int *flag);
void indiceUsuarios (eUsuario [], int);
int hardUsuario (eUsuario [], int, int);
int searchIndexUsers ( eUsuario status[], int tamanio);
int altaUsuario (eUsuario users[], int tamanio, int flag);
void mostrarUsuarios (eUsuario users[], int tamanio, int );
void mostrarUsuariosDadoBaja(eUsuario users[], int tamanio, int *flag);
void listadoDeUsuarios (eUsuario users [], int tamanio);
void bajaUsuario (eUsuario users[], int tamanio, int flag);
 void modificarUsuario (eUsuario users[], int tamanio, int flag);


#endif
