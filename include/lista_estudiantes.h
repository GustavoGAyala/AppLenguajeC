#ifndef LISTA_ESTUDIANTES_H
#define LISTA_ESTUDIANTES_H

#include "declaraciones.h"

Lista_Estudiantes* nueva_lista_estudiantes();
void antes_de(Lista_Estudiantes** lista, Lista_Estudiantes* nuevo);
void despues_de(Lista_Estudiantes* lista, Lista_Estudiantes* nuevo);
void add_estudiante_lista_estudiantes(Lista_Estudiantes** lista, Estudiante* nuevo);
void add_estudiante_lista_estudiantes_edad(Lista_Estudiantes** lista, Estudiante* nuevo);
void add_estudiante_lista_estudiantes_nombre(Lista_Estudiantes** lista, Estudiante* nuevo);
Estudiante* get_lista_estudiantes_estudiante(Lista_Estudiantes* lista, char* nombre);
void delete_estudiante(Lista_Estudiantes* lista, char* nombre);

#endif