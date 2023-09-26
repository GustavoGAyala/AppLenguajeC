#include "../include/declaraciones.h"

void cargar_programa(Lista_Carreras** lista_carreras){
    bool estado = true;
    FILE* archivo = fopen("carreras_materias.txt", "r");//checkear el path
    if(archivo == NULL){
        printf("ERROR AL LEER EL ARCHIVO");
        //return 1;
    }
    size_t incremento = MINIMO;
    size_t memoria_asignada = incremento;
    char* caracteres = malloc(memoria_asignada);
    size_t total = 0;
    while(!feof(archivo) && !ferror(archivo)){
        if(caracteres == NULL){
            printf("ERROR AL REASIGNAR CON REALLOC");
            //return 1;
        }
        caracteres[total] = fgetc(archivo);
        total++;
        if(total >= memoria_asignada){
            if(incremento >= MAXIMO){
                incremento = MAXIMO;
            }
            memoria_asignada += incremento;
            caracteres = realloc(caracteres, memoria_asignada);
            incremento *= 2;
        }
        //aca tendria que ir el manejo del llamado a crear entidades
        if(caracteres[total - 1] == '\n'){
            caracteres[total - 1] = '\0';
            caracteres = realloc(caracteres, total);
            //este ignora la primera linea
            if(estado == true){
                estado = false;
            }else{
                Carrera* carrera_nueva = nueva_carrera();
                char* nombre_carrera = strtok(caracteres, ";");
                set_carrera_nombre(carrera_nueva, nombre_carrera);
                Lista_Materias* lista_materias = nueva_lista_materias();
                Materia* materia_nueva = NULL;
                char* nombre_materia = strtok(NULL, ";");
                while(nombre_materia != NULL){
                    materia_nueva = nueva_materia();
                    set_materia_nombre_carrera(materia_nueva, nombre_carrera);
                    set_materia_nombre(materia_nueva, nombre_materia);
                    add_materia_lista_materias(&lista_materias, materia_nueva);
                    nombre_materia = strtok(NULL, ";");
                }
                set_carrera_lista_materias(carrera_nueva, lista_materias);
                add_carrera_lista_carreras(lista_carreras, carrera_nueva);
            }
            total = 0;
            memoria_asignada = MINIMO;
            caracteres = NULL;
            caracteres = malloc(memoria_asignada);
        }
    }
    if(ferror(archivo)){
        printf("ERROR AL LEER");
        //return 1;
    } 
    fclose(archivo);
}