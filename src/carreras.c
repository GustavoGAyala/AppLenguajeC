#include "../include/declaraciones.h"

Carrera* nueva_carrera(){
    Carrera* nueva = malloc(sizeof(Carrera));
    if(nueva == NULL){
        printf("ERROR AL RESERVAR MEMORIA PARA CARRERA\n");
    }
    nueva->nombre_carrera = NULL;
    nueva->sig_mat = NULL;
    return nueva;
}

void set_carrera_nombre(Carrera* carrera, char* nombre){
    carrera->nombre_carrera = ((carrera != NULL) && (nombre != NULL)) ? nombre : NULL;
}

char* get_carrera_nombre(Carrera *carrera){
    return (carrera != NULL) ? carrera->nombre_carrera : NULL;
}

void set_carrera_lista_materias(Carrera* carrera, Lista_Materias* lista){
    carrera->sig_mat = ((carrera != NULL) && (lista != NULL)) ? lista : NULL;
}

Lista_Materias* get_carrera_lista_materias(Carrera* carrera){
    return (carrera != NULL) ? carrera->sig_mat : NULL;
}
