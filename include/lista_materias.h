#ifndef LISTA_MATERIAS_H
#define LISTA_MATERIAS_H

#include "declaraciones.h"

Lista_Materias* nueva_lista_materias();
void add_materia_lista_materias(Lista_Materias** lista, Materia* nuevo);
Materia* get_materia_lista_materias(Lista_Materias* lista, char* nombre);
void delete_materia_lista_materias(Lista_Materias* lista, char* nombre);

#endif