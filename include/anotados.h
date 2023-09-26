#ifndef ANOTADOS_H
#define ANOTADOS_H

#include "declaraciones.h"

Anotado* nuevo_anotado();
Anotado* find_anotado_materia(Anotado* anotado, char* nombre);
void set_anotado_nota(Anotado* anotado, int nota, char* nombre);
int get_anotado_nota(Anotado* anotado, char* nombre);
void set_anotado_materia(Anotado* anotado, Materia* materia);
Materia* get_anotado_materia(Anotado* anotado, char* nombre);
void add_anotado(Anotado** actual, Anotado** entrante);

#endif