#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct Estudiantes{
    char *nombre;
    char *apellido;
    int edad;
    char *carrera;
    struct Anotados* sig_mat;
} Estudiante;

typedef struct Materias{
    char *nombre_materia;
    char *carrera;
    struct Lista_Estudiantes* sig_est;
} Materia;

typedef struct Carerras{
    char *nombre_carrera;
    struct Lista_Materias *sig_mat;
} Carrera;

typedef struct Anotados{
    int nota;
    Materia* materia;
    struct Anotados* sig_mat;
} Anotado;

typedef struct Lista_Estudiantes{
    Estudiante* estudiante;
    struct Lista_Estudiantes* sig_est;
} Lista_Estudiantes;

typedef struct Lista_Carreras{
    Carrera* carrera;
    struct Lista_Carreras* sig_car;
} Lista_Carreras;

typedef struct Lista_Materias{
    Materia* materia;
    struct Lista_Materias* sig_mat;
} Lista_Materias;

#endif