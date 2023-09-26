#include "../include/declaraciones.h"

Materia *nueva_materia(){
    Materia* nueva = malloc(sizeof(Materia));
    if(nueva == NULL){
        printf("ERROR AL RESERVAR MEMORIA PARA MATERIA\n");
    }
    nueva->carrera = NULL;
    nueva->nombre_materia = NULL;
    nueva->sig_est = NULL;
    return nueva;
}

void set_materia_nombre(Materia *materia, char *nombre){
    materia->nombre_materia = ((materia != NULL) && (nombre != NULL)) ? nombre : NULL;
}

char *get_materia_nombre(Materia *materia){
    return (materia != NULL) ? materia->nombre_materia : NULL;
}

void set_materia_nombre_carrera(Materia *materia, char *nombre){
    materia->carrera = ((materia != NULL) && (nombre != NULL)) ? nombre : NULL;
}

char *get_materia_nombre_carrera(Materia *materia){
    return (materia != NULL) ? materia->carrera : NULL;
}

void set_materia_lista_estudiantes(Materia* materia, Lista_Estudiantes* lista){
    materia->sig_est = ((materia != NULL) && (lista != NULL)) ? lista : NULL;
}

Lista_Estudiantes* get_materia_lista_estudiantes(Materia* materia){
    return (materia != NULL) ? materia->sig_est : NULL;
}