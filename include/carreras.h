#ifndef CARRERAS_H
#define CARRERAS_H

#include "declaraciones.h"

Carrera* nueva_carrera();
void set_carrera_nombre(Carrera* carrera, char* nombre);
char* get_carrera_nombre(Carrera *carrera);
void set_carrera_lista_materias(Carrera* carrera, Lista_Materias* lista);
Lista_Materias* get_carrera_lista_materias(Carrera* carrera);

#endif