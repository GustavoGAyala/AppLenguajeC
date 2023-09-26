#include "../include/declaraciones.h"

Lista_Estudiantes* nueva_lista_estudiantes(){
    Lista_Estudiantes* nueva = malloc(sizeof(Lista_Estudiantes));
    if(nueva == NULL){
        printf("ERROR AL RESERVAR MEMORIA PARA LISTA DE ESTUDIANTES");
    }
    nueva->estudiante = NULL;
    nueva->sig_est = NULL;
    return nueva;
}

void antes_de(Lista_Estudiantes** lista, Lista_Estudiantes* nuevo){
    if (*lista == NULL) {
        *lista = nuevo;
    } else {
        nuevo->sig_est = *lista;
        *lista = nuevo;
    }
}

void despues_de(Lista_Estudiantes* lista, Lista_Estudiantes* nuevo){
    nuevo->sig_est = lista->sig_est;
    lista->sig_est = nuevo;
}
//usar este patron para el add en listas
void add_estudiante_lista_estudiantes(Lista_Estudiantes** lista, Estudiante* nuevo){
    if(nuevo != NULL){
        if((*lista) == NULL || (*lista)->estudiante != NULL){
            Lista_Estudiantes* nueva = nueva_lista_estudiantes();
            nueva->estudiante = nuevo;
            antes_de(lista, nueva);
        }else{
            (*lista)->estudiante = nuevo;
        }
    } 
}

void add_estudiante_lista_estudiantes_edad(Lista_Estudiantes** lista, Estudiante* nuevo){
    if (nuevo != NULL){
        Lista_Estudiantes* nueva = nueva_lista_estudiantes();
        nueva->estudiante = nuevo;

        if(*lista == NULL || (*lista)->estudiante == NULL){
            antes_de(lista, nueva);
        }else{
            int edad_est = nuevo->edad;
            Lista_Estudiantes* cursor = *lista;
            Lista_Estudiantes* previo = NULL;
            
            while((cursor != NULL) && (cursor->estudiante != NULL) && (cursor->estudiante->edad <= edad_est)){
                previo = cursor;
                cursor = cursor->sig_est;
            }
            
            nueva->sig_est = cursor;

            if(previo == NULL){
                antes_de(lista, nueva);
            }else{
                previo->sig_est = nueva;
            }
        }
    }
}
//habria que checkear que los nombres o las edades no sean nulas
void add_estudiante_lista_estudiantes_nombre(Lista_Estudiantes** lista, Estudiante* nuevo){
    if(nuevo != NULL){
        Lista_Estudiantes* nueva = nueva_lista_estudiantes();
        nueva->estudiante = nuevo;
        if(*lista == NULL || (*lista)->estudiante == NULL){
            antes_de(lista, nueva);
        }else{
            char* nombre_est = nuevo->nombre;
            Lista_Estudiantes* cursor = *lista;
            Lista_Estudiantes* previo = NULL;

            while((cursor != NULL) 
            && (cursor->estudiante != NULL) 
            && (strcmp(cursor->estudiante->nombre, nombre_est) <= 0)){
                previo = cursor;
                cursor = cursor->sig_est;
            }
            
            nueva->sig_est = cursor;

            if(previo == NULL){
                antes_de(lista, nueva);
            }else{
                previo->sig_est = nueva;
            }
        }
    }
}
//este no se si es necesario
Estudiante* get_lista_estudiantes_estudiante(Lista_Estudiantes* lista, char* nombre){
    Estudiante* encontrado = NULL;
    if((lista != NULL) && (nombre == NULL)){
        encontrado = lista->estudiante;
    }else{
        char* nombre_estudiante = NULL;
        if(lista != NULL && nombre != NULL){
            nombre_estudiante = lista->estudiante->nombre;
            if(strcmp(nombre_estudiante, nombre) == 0){
                encontrado = lista->estudiante;
            }else{
                Lista_Estudiantes* cursor = lista;
                while(cursor != NULL){
                    nombre_estudiante = cursor->estudiante->nombre;
                    if(strcmp(nombre_estudiante, nombre) == 0){
                        encontrado = cursor->estudiante;
                        break;
                    }
                    cursor = cursor->sig_est;
                }
            }
        }
    }
    return encontrado;
}
//sin testear
void delete_estudiante(Lista_Estudiantes* lista, char* nombre){
    if((lista != NULL) && (nombre != NULL)){
        char* nombre_est = NULL;
        Lista_Estudiantes* cursor = lista;
        int resultado = -1;
        while(cursor != NULL){
            nombre_est = cursor->estudiante->nombre;
            resultado = strcmp(nombre_est, nombre);
            if(resultado == 0){
                Lista_Estudiantes* temp = cursor;
                cursor = cursor->sig_est;
                temp->estudiante = NULL;
                //free(temp);
                break;
            }else{
                cursor = cursor->sig_est;
            }
        }
        
    }
}