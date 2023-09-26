#ifndef INTERFACE_H
#define INTERFACE_H

#include "declaraciones.h"

void limpiar_pantalla();
int menu_inicio_sesion_logica(char *username,char *password);
void cambiar_apariencia();

/*impresiones de Menu*/
bool menu_inicio_sesion();
void ejecutar_menu();
void menu_gestionar_estudiante();
Estudiante* menu_buscar_estudiante();
int menu_alta_estudiante();
void menu_imprimir_lista_estudiantes();
void imprimir_lista_estudiantes(Lista_Estudiantes* lista);
void menu_gestionar_carrera ();
void menu_buscar_carrera();
void menu_alta_carrera();
void imprimir_lista_carreras(Lista_Carreras* lista);
void menu_gestionar_materias (Carrera* una_carrera);
void imprimir_lista_materias (Lista_Materias* lista);
Carrera* buscar_carrera(Lista_Carreras* lista);
Materia* buscar_materia(Carrera* carrera);
void menu_agregar_materia(Carrera* una_carrera);
Carrera* carrera_estudiante(char* nombre);
Estudiante*  buscar_estudiante_por_nombre();
Estudiante*  buscar_estudiante_por_edad();
Materia* materia_anotado (Estudiante* estudiante);
void menu_gestion_estudiante();

/*utilidades*/
void imprimir_encabezado(char *encabezado);
void imprimir_separador();
void opcion_invalida ();
void salir();
void pausa();


#endif