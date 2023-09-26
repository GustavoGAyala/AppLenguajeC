#include "../include/declaraciones.h"

Lista_Materias* nueva_lista_materias(){
    Lista_Materias* nueva = malloc(sizeof(Lista_Materias));
    if(nueva == NULL){
        printf("ERROR AL RESERVAR MEMORIA PARA LISTA DE MATERIAS\n");
    }
    nueva->materia = NULL;
    nueva->sig_mat = NULL;
    return nueva;
}
//revisar los if, por ahi se puede mejorar
//estos metodos permiten repetidos
void add_materia_lista_materias(Lista_Materias** lista, Materia* nuevo){
    if(nuevo != NULL){
        if((*lista) == NULL || (*lista)->materia != NULL){
            Lista_Materias* nueva = nueva_lista_materias();
            nueva->materia = nuevo;
            nueva->sig_mat = *lista;
            *lista = nueva;
        }else{
            (*lista)->materia = nuevo;
        }
    }
}

Materia* get_materia_lista_materias(Lista_Materias* lista, char* nombre){
    Materia* materia = NULL;
    if(lista != NULL && nombre != NULL){
        char* nombre_materia = lista->materia->nombre_materia;
        if(strcmp(nombre, nombre_materia) == 0){
            materia = lista->materia;
        }else{  
            Lista_Materias* cursor = lista;
            while(cursor != NULL){
                nombre_materia = cursor->sig_mat->materia->nombre_materia;
                if(strcmp(nombre_materia, nombre) == 0){
                    materia = cursor->sig_mat->materia;
                    break;
                }
                cursor = cursor->sig_mat;
            }
        }
    }else{
        if((lista != NULL) && (nombre == NULL)){
            materia = lista->materia;
        }
    }
    return materia;
}
//sin testear
void delete_materia_lista_materias(Lista_Materias* lista, char* nombre){
    if((lista != NULL) && (nombre != NULL)){
        if((strcmp(lista->materia->nombre_materia, nombre)) == 0){
            Lista_Materias* temp = lista;
            lista = lista->sig_mat;
            free(temp);
        }else{
            char* nombre_mat;
            Lista_Materias* cursor = lista;
            while(cursor != NULL){
                nombre_mat = cursor->sig_mat->materia->nombre_materia;
                if(strcmp(nombre_mat, nombre) == 0){
                    Lista_Materias* temp = cursor->sig_mat;
                    cursor = cursor->sig_mat->sig_mat;
                    free(temp);
                    break;
                }
                cursor = cursor->sig_mat;
            }
        }
    }
}