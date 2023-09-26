#include "../include/declaraciones.h"

Anotado* nuevo_anotado(){
    Anotado* nuevo = malloc(sizeof(Anotado));
    if(nuevo == NULL){
        printf("ERROR AL RESERVAR MEMORIA PARA ANOTADO\n");
    }
    nuevo->materia = NULL;
    nuevo->nota = 0;
    nuevo->sig_mat = NULL;
    return nuevo;
}

void set_anotado_nota(Anotado* anotado, int nota, char* nombre){
    if((anotado != NULL) && ((nota > 0) && (nota < 11)) && (nombre != NULL)){
        Anotado* temp = find_anotado_materia(anotado, nombre);
        if(temp != NULL){
            temp->nota = nota;
        }
        //free(temp);
    }
}

int get_anotado_nota(Anotado* anotado, char* nombre){
    int nota = 0;
    if(anotado != NULL && nombre != NULL){
        Anotado* temp = find_anotado_materia(anotado, nombre);
        nota = temp->nota;
        //free(temp)
    }
    return nota;
}

void set_anotado_materia(Anotado* anotado, Materia* materia){
    if((anotado != NULL) && (materia != NULL)){
        if(anotado->materia == NULL){
            anotado->materia = materia;
        }else{
            Anotado* nuevo = nuevo_anotado();
            nuevo->materia = materia;
            add_anotado(&anotado, &nuevo);
        }
    }
}

Materia* get_anotado_materia(Anotado* anotado, char* nombre){//este necesita el nombre de la materia
    Materia* materia = NULL;
    Anotado* temp = find_anotado_materia(anotado, nombre);
    if(temp != NULL){
        materia = temp->materia;
    }
    return materia;
}

void add_anotado(Anotado** actual, Anotado** entrante){//supuestamente esta bien pero no le tengo fe
    if((*actual != NULL) && (*entrante != NULL)){
        (*entrante)->sig_mat = *actual;
        *actual = *entrante;
    }
}

Anotado* find_anotado_materia(Anotado* anotado, char* nombre){
    Anotado* encontrado = NULL;
    if(anotado != NULL && nombre != NULL && anotado->materia != NULL && anotado->materia->nombre_materia != NULL){//mm
        char* nombre_materia = anotado->materia->nombre_materia;
        if(strcmp(nombre_materia, nombre) == 0){
            encontrado = anotado;
        }else{
            Anotado* cursor = anotado;
            while(cursor != NULL && cursor->materia != NULL && cursor->materia->nombre_materia != NULL){
                nombre_materia = cursor->materia->nombre_materia;
                if(strcmp(nombre, nombre_materia) == 0){
                    encontrado = cursor;
                    break;
                }else{
                    cursor = cursor->sig_mat;
                }
            }
        }
    }
    return encontrado;
}