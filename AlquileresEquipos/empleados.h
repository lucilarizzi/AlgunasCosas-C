#ifndef EMPLEADOS_H
#define EMPLEADOS_H

typedef struct
{
    char nombre [15];
    char apellido [15];
    int idEmpleado;
    int status;

} eEmpleados;
int  altaEmpleado (eEmpleados users[], int tamanio, int flag);
int searchIndexEmploye ( eEmpleados status[], int tamanio);
void indiceEmpleados(eEmpleados usuarios[], int tamanio);
  void showOneEmploye (eEmpleados usuarios);
    void showOneEmploye (eEmpleados usuarios);
    void mostrarEmpleados (eEmpleados users[], int tamanio, int flag);
    void mostrarEmpleados (eEmpleados users[], int tamanio, int flag);
    void modificarEmpleado (eEmpleados users[], int tamanio, int flag);
     int hardEmpleados(eEmpleados MisUsuarios[], int tamanio, int CantCli, int flag);




#endif
