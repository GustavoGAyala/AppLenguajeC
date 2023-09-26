#ifndef DECLARACIONES_H
#define DECLARACIONES_H

/*Bibliotecas del Sistema*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <unistd.h>

/*Declaracion de funciones locales*/
#include "estructuras.h"
#include "materias.h"
#include "estudiantes.h"
#include "carreras.h"
#include "interface.h"
#include "anotados.h"
#include "lista_carreras.h"
#include "lista_estudiantes.h"
#include "lista_materias.h"
#include "test.h"
#include "lector.h"

/*Constantes*/
#define MINIMO 1024
#define MAXIMO 4086

//relacionado a Login
#define LOGIN_LONGITUD_MAXIMA 100
#define INTENTOS 5
#define ALMACEN_USUARIOS "data/usuarios.csv"

//relacionado a Visualizacion
#define ANCHO_PANTALLA 120
#define ALTO_PANTALLA 30
#define COLOR_TEXTO 0x30



#endif