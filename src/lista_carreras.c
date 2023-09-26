#include "../include/declaraciones.h"

Lista_Carreras* nueva_lista_carreras(){
    Lista_Carreras* lista = malloc(sizeof(Lista_Carreras));
    if(lista == NULL){
        printf("ERROR AL RESERVAR MEMORIA PARA LISTA DE CARRERAS\n");
    }
    lista->carrera = NULL;
    lista->sig_car = NULL;
    return lista;
}

void add_carrera_lista_carreras(Lista_Carreras** lista, Carrera* nuevo){
    if(nuevo != NULL){
        if((*lista == NULL) || (*lista)->carrera != NULL){
            Lista_Carreras* nueva = nueva_lista_carreras();
            nueva->carrera = nuevo;
            nueva->sig_car = *lista;
            *lista = nueva;
        }else{
            (*lista)->carrera = nuevo;
        }
    }
}

Carrera* get_carrera_lista_carreras(Lista_Carreras* lista, char* nombre){
    Carrera* carrera = NULL;
    if((lista != NULL) && (nombre != NULL)){
        char* nombre_carrera = lista->carrera->nombre_carrera;
        if(strcmp(nombre_carrera, nombre) == 0){
            carrera = lista->carrera;
        }else{
            Lista_Carreras* cursor = lista;
            while(cursor != NULL){
                nombre_carrera = cursor->sig_car->carrera->nombre_carrera;
                if(strcmp(nombre_carrera, nombre) == 0){
                    carrera = cursor->sig_car->carrera;
                    break;
                }
                cursor = cursor->sig_car;
            }
        }
    }else{
        if((lista != NULL) && (nombre == NULL)){
            carrera = lista->carrera;
        }
    }
    return carrera;
}

void delete_carrera_lista_carreras(Lista_Carreras* lista, char* nombre){
    if((lista != NULL) && (nombre != NULL)){
        char* nombre_carrera = lista->carrera->nombre_carrera;
        if(strcmp(nombre_carrera, nombre) == 0){
            Lista_Carreras* temp = lista;
            lista = lista->sig_car;
            free(temp);
        }else{
            Lista_Carreras* cursor = lista;
            while(cursor != NULL){
                nombre_carrera = cursor->sig_car->carrera->nombre_carrera;
                if(strcmp(nombre_carrera, nombre) == 0){
                    Lista_Carreras* temp = cursor->sig_car->sig_car;
                    free(cursor->sig_car);
                    cursor->sig_car = temp;
                    break;
                }
                cursor = cursor->sig_car;
            }
        }
    }
}