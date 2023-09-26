#include "../include/declaraciones.h"

int verificar_datos(Estudiante *estudiante){
    return (estudiante->nombre /*&& estudiante->apellido && (estudiante->año_nacimiento > 17 && estudiante->año_nacimiento < 61) && estudiante->carrera*/) ? 1 : 0;
}

Estudiante *nuevo_estudiante(){
    Estudiante *estudiante = malloc(sizeof(Estudiante));
    estudiante->nombre = NULL;
    estudiante->apellido = NULL;
    estudiante->edad = 0;
    estudiante->carrera = NULL;
    estudiante->sig_mat = NULL;
    return estudiante;
}

void set_estudiante_nombre(Estudiante *estudiante, char *nombre){
    estudiante->nombre = ((estudiante != NULL) && (nombre != NULL)) ? nombre : NULL;
}

char* get_estudiante_nombre(Estudiante *estudiante){
    return (estudiante != NULL) ? estudiante->nombre : NULL;
}

void set_estudiante_apellido(Estudiante *estudiante, char *apellido){
    estudiante->apellido = ((estudiante != NULL) && (apellido != NULL)) ? apellido : NULL;
}

char* get_estudiante_apellido(Estudiante *estudiante){
    return (estudiante != NULL) ? estudiante->apellido : NULL;
}

void set_estudiante_edad(Estudiante *estudiante, int edad){
    estudiante->edad = ((estudiante != NULL) && (edad > 17)) ? edad : 0;
}

int get_estudiante_edad(Estudiante *estudiante){
    return (estudiante != NULL) ? estudiante->edad : 0;
}

void set_estudiante_nombre_carrera(Estudiante *estudiante, char *nombre){
    estudiante->carrera = ((estudiante != NULL) && (nombre != NULL)) ? nombre : NULL;
}

char* get_estudiante_nombre_carrera(Estudiante *estudiante){
    return (estudiante != NULL) ? estudiante->carrera : NULL;
}

void anotarse(Estudiante *estudiante, Materia *materia) {
    if((estudiante != NULL) && (materia != NULL)){

        Anotado* nuevo = nuevo_anotado();
        set_anotado_materia(nuevo, materia);

        if(estudiante->sig_mat == NULL){
            estudiante->sig_mat = nuevo;
        }else{
            add_anotado(&estudiante->sig_mat, &nuevo);
        }

        Lista_Estudiantes* lista = get_materia_lista_estudiantes(materia);
        if(lista == NULL){
            lista = nueva_lista_estudiantes();
            set_materia_lista_estudiantes(materia, lista);
        }
        add_estudiante_lista_estudiantes(&lista, estudiante);
    }
}

void rendir(Materia *materia, Estudiante *estudiante, int nota){
    if((materia != NULL) && (estudiante != NULL) && ((nota > 0) && (nota < 11)) && (estudiante->nombre != NULL)){

        Anotado* anotado = estudiante->sig_mat;

        if(nota > 3){
            Lista_Estudiantes* lista = get_materia_lista_estudiantes(materia);
            if(lista != NULL){
                delete_estudiante(lista, get_estudiante_nombre(estudiante));
            }
            //free(lista);
        }

        set_anotado_nota(anotado, nota, materia->nombre_materia);
        //free(anotado);
    }
}

void set_estudiante_anotado(Estudiante* estudiante, Anotado* anotado){
    estudiante->sig_mat = ((estudiante != NULL) && (anotado != NULL)) ? anotado : NULL;
}

Anotado* get_estudiante_anotado(Estudiante* estudiante){
    return (estudiante != NULL) ? estudiante->sig_mat : NULL;
}