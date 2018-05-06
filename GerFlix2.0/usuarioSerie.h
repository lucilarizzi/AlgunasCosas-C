#include "usuario.h"
#include "serie.h"
#ifndef USUARIOSERIE_H_INCLUDED
#define USUARIOSERIE_H_INCLUDED


typedef struct
{
    int idUsuario;
    int idSerie;

}eUsuarioSerie;

void CrearListadoUsuariosYSeries(eUsuarioSerie []);
int displayMenuABM (char texto[]);
void contarUsuariosPorSerie(eUsuarioSerie relaciones [], eUsuario usuarios [], eSerie series []);
void allSerieForUser (eUsuarioSerie [], eUsuario [], eSerie []);
void contarUsuariosPorSerie(eUsuarioSerie relaciones [], eUsuario usuarios [], eSerie series []);
void top3series(eUsuarioSerie relaciones [], eUsuario usuarios [], eSerie series []);
void cleanScreen (void);

#endif // USUARIOSERIE_H_INCLUDED
