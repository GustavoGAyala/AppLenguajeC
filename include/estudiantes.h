#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#include "declaraciones.h"

int verificar_datos(Estudiante *estudiante);
Estudiante* nuevo_estudiante();
void set_estudiante_nombre(Estudiante *estudiante, char *nombre);
char* get_estudiante_nombre(Estudiante *estudiante);
void set_estudiante_apellido(Estudiante *estudiante, char *apellido);
char* get_estudiante_apellido(Estudiante *estudiante);
void set_estudiante_edad(Estudiante *estudiante, int edad);
int get_estudiante_edad(Estudiante *estudiante);
void set_estudiante_nombre_carrera(Estudiante *estudiante, char *nombre);
char* get_estudiante_nombre_carrera(Estudiante *estudiante);
void anotarse(Estudiante *estudiante, Materia *materia);
void rendir(Materia *materia, Estudiante *estudiante, int nota);
void set_estudiante_anotado(Estudiante* estudiante, Anotado* anotado);
Anotado* get_estudiante_anotado(Estudiante* estudiante);

#endif