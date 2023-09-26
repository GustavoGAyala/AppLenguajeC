#ifndef MATERIAS_H
#define MATERIAS_H

#include "declaraciones.h"

Materia *nueva_materia();
void set_materia_nombre(Materia *materia, char *nombre);
char *get_materia_nombre(Materia *materia);
void set_materia_nombre_carrera(Materia *materia, char *nombre);
char *get_materia_nombre_carrera(Materia *materia);
void set_materia_lista_estudiantes(Materia* materia, Lista_Estudiantes* lista);
Lista_Estudiantes* get_materia_lista_estudiantes(Materia* materia);

#endif