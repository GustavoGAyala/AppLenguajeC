#ifndef LISTA_CARRERAS_H
#define LISTA_CARRERAS_H

#include "declaraciones.h"

Lista_Carreras* nueva_lista_carreras();
void add_carrera_lista_carreras(Lista_Carreras** lista, Carrera* nuevo);
Carrera* get_carrera_lista_carreras(Lista_Carreras* lista, char* nombre);
void delete_carrera_lista_carreras(Lista_Carreras* lista, char* nombre);

#endif