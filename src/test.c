#include "../include/declaraciones.h"

void TEST(int resultado, char* nombre);
void reset_anotado(Anotado* anotado);
void reset_carrera(Carrera* carrera);
void reset_materia(Materia* materia);
void reset_estudiante(Estudiante* estudiante);
void reset_lista_carreras(Lista_Carreras* lista_carreras);
void reset_lista_materias(Lista_Materias* lista_materias);
void reset_lista_estudiantes(Lista_Estudiantes* lista_estudiantes);
void red();
void green();
void reset();

void tst_anotado_elementoNoNull_campoNULL(Anotado* a);
void tst_anotado_nota0(Anotado* a);
void tst_anotado_materiaNULL(Anotado* a);
void tst_anotado_materiaNoNULL(Anotado* a,Materia* m);
void tst_anotado_siguienteNull(Anotado* a);
void tst_anotado_nota_valida(Anotado* a,Materia* m);
void tst_anotado_nota_invalida_negativa(Anotado* a, Materia* m);
void tst_anotado_nota_invalida_mayor(Anotado* a, Materia* m);
void tst_anotado_get_materia_valida(Anotado* a, Materia* m);
void tst_anotado_get_materia_invalida(Anotado* a, Materia* m);//
void tst_anotado_find_anatado_materia(Anotado* a, Materia* m);
void tst_estudiante_anotarse(Anotado* a, Materia* m, Estudiante* ee);
void tst_estudiante_rendir( Anotado* a, Materia* m, Estudiante* ee);
void tst_anotado_agregar_al_incicio(Anotado* a, Anotado* b, Anotado* pa, Anotado* pb);
void tst_anotado_agregar_anotados_despues_de_agregar(Anotado* a, Anotado* b, Anotado* c, Anotado* pa, Anotado* pb);
void tst_carrera_camposNULL(Carrera* ca);
void tst_carrera_nombreNULL(Carrera* ca);
void tst_carrera_cambiar_nombre(Carrera* ca);
void tst_carrera_get_LmateriaNULL(Carrera* ca);
void tst_carrera_get_LmateriaNONULL(Carrera* ca, Lista_Materias* lm);
void tst_materia_camposNULL(Materia* ma);
void tst_materia_nombreNULL(Materia* ma);
void tst_materia_nombreNONULL(Materia* ma);
void tst_carrera_nombreNULL(Carrera* ca);
void tst_materia_get_LestudiantesNULL(Materia* ma);
void tst_materia_get_LestudiantesNONULL(Materia* ma);
void tst_materia_get_carrera_nombreNULL(Materia* ma);
void tst_materia_get_carrera_nombreNONULL(Materia* ma);
    
void tst_estudiante_camposNULL(Estudiante* es);
void tst_estudiante_nombreNULL(Estudiante* es);
void tst_estudiante_nombreNONULL(Estudiante* es, char* nombre_es );
void tst_estudiante_apellidoNULL(Estudiante* es);
void tst_estudiante_apellidoNONULL(Estudiante* es, char* ape_es);
void tst_estudiante_get_edadCero(Estudiante* es);
void tst_estudiante_edad_negativa(Estudiante* es);
void tst_estudiante_set_edad18 (Estudiante* es);
void tst_estudiante_set_edad0 (Estudiante* es);
void tst_estudiante_get_carrera_nombreNULL(Estudiante* es);
void tst_estudiante_get_carrera_nombreNONULL(Estudiante* es, char* carr_es );
void tst_estudiante_get_anotadoNULL(Estudiante* es);
void tst_estudiante_set_anotadoNONULL(Estudiante* es, Anotado* a_es);

void tst_Lcarrera_camposNULL(Lista_Carreras* lc);
void tst_Lcarrera_get_carrera_SbusquedaNULL(Lista_Carreras* lc);
void tst_Lcarrera_get_carrera_SbusqedaNONULL(Lista_Carreras* lc, Carrera* c_lc);
void tst_Lcarera_get_carrera_CbusquedaNONULL(Carrera* c_lc, Lista_Carreras* lc_o);
void tst_Lcarrera_get_carrera_primeroUltimo_segundoPrimero(Carrera* c_lc, Carrera* c_lc2, Lista_Carreras* lc);
void tst_Lcarrera_get_carreras(Carrera* c_lc, Carrera* c_lc2, Carrera* c_lc3, Lista_Carreras* lc, Carrera* cb);

void tst_Lmateria_camposNULL(Lista_Materias* lmat);
void tst_Lmateria_nombreNULL(Lista_Materias* lmat);
void tst_Lmateria_get_materiaNONULL(Lista_Materias* lmat, Materia* mat);
void tst_Lmateria_listaNULL_despuesNONULL(Lista_Materias* lmn, Lista_Materias* lmat, Materia* mat);
void tst_Lmateria_addMateria_cambio_direccion(Lista_Materias* lmat, Lista_Materias* lmats, Materia* mat);

void tst_Lestudiantes_campoNULL(Lista_Estudiantes* l_e);
void tst_Lestudiante_get_estudianteNULL(Lista_Estudiantes* l_e);
void tst_Lestudiate_get_sig_estudianteNULL(Lista_Estudiantes* l_e);
void tst_Lestudiante_addAntes_sigActual(Lista_Estudiantes* l_e, Lista_Estudiantes* pl_e, Lista_Estudiantes* l_e2);
void tst_Lestudiante_Add_DespuesDe(Lista_Estudiantes* l_e, Lista_Estudiantes* l_e3);
void tst_Lestudiante_addElemento_listaNULL(Lista_Estudiantes* l_e, Estudiante* est);
void tst_Lestudiante_addElemento_listaNONULL(Lista_Estudiantes* l_e, Estudiante* est);
void tst_Lestudiante_AddEstudianteNONULL_listaNONULL(Lista_Estudiantes* l_e, Estudiante* est);    
void tst_Lestudiante_addEdad_listaNULL(Estudiante* a1, Lista_Estudiantes* l_e);
void tst_Lestudiante_addEdad_mayor_listaNONULL(Estudiante* a1, Estudiante* a2, Lista_Estudiantes* l_e);
void tst_Lestudiante_addEdad_menor_listaNONULL(Estudiante* a1, Estudiante* a2, Lista_Estudiantes* l_e);
void tst_Lestudiante_addEdad_listaNONULL_varios(Lista_Estudiantes* l_e, Estudiante* a1, Estudiante* a2, Estudiante*a3, Estudiante* a4);
void tst_Lestudiante_addNombre_listaNULL(Lista_Estudiantes* l_e, Estudiante* a1);
void tst_Lestudiante_addNombre_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1);
void tst_Lestudiante_addNombre_varios_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1, Estudiante* a2);
void tst_Lestudiante_addNombre_variosInvertidos_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1, Estudiante* a2);
void tst_Lestudiantes_addNombre_todos_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1, Estudiante* a2, Estudiante* a3, Estudiante* a4);
void tst_Lestudiantes_addNombre_todosInvertido_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1, Estudiante* a2, Estudiante* a3, Estudiante* a4);    

char* nombre;
bool resultado;

int tests(){

    Anotado* a = nuevo_anotado();
    Anotado* b = nuevo_anotado();
    Anotado* c = nuevo_anotado();
    Anotado* pa = nuevo_anotado();
    Anotado* pb = nuevo_anotado();
    Anotado* an_es = nuevo_anotado();
    Anotado* a_es = nuevo_anotado();

    Lista_Materias* lm = nueva_lista_materias();
    Materia* ma = nueva_materia();
    Materia* m = nueva_materia();
    Materia* mat = nueva_materia();
    Lista_Materias* lmat = nueva_lista_materias();
    Lista_Materias* lmn = nueva_lista_materias();
    Lista_Materias* lmats = nueva_lista_materias();

    Carrera* ca = nueva_carrera();
    Carrera* cb =nueva_carrera();
    Lista_Carreras* lc = nueva_lista_carreras();
    Carrera* c_lc = nueva_carrera();
    Lista_Carreras* lc_o = nueva_lista_carreras();
    Carrera* c_lc3 = nueva_carrera();
    Carrera* c_lc2 = nueva_carrera();

    Estudiante* es = nuevo_estudiante();
    Estudiante* est = nuevo_estudiante();
    Estudiante* ee = nuevo_estudiante();
    Estudiante* a1 = nuevo_estudiante();
    Estudiante* a2 = nuevo_estudiante();
    Estudiante* a3 = nuevo_estudiante();
    Estudiante* a4 = nuevo_estudiante();
    Lista_Estudiantes* l_e = nueva_lista_estudiantes();
    Lista_Estudiantes* l_e2 = nueva_lista_estudiantes();
    Lista_Estudiantes* pl_e =nueva_lista_estudiantes();;
    Lista_Estudiantes* l_e3 = nueva_lista_estudiantes();

    char* nombre_es = "jose";
    char* ape_es = "casa";
    char* carr_es = "ing";
    int ed_es = 18;
    

    tst_anotado_elementoNoNull_campoNULL(a);
    tst_anotado_nota0(a);
    tst_anotado_materiaNULL(a);
    tst_anotado_materiaNoNULL(a,m);
    tst_anotado_siguienteNull(a);
    tst_anotado_nota_valida(a,m);
    tst_anotado_nota_invalida_negativa(a, m);
    tst_anotado_nota_invalida_mayor(a, m);
    tst_anotado_get_materia_valida(a, m);
    tst_anotado_get_materia_invalida(a, m);
    tst_anotado_find_anatado_materia(a, m);
    tst_estudiante_anotarse(a, m, ee);
    tst_estudiante_rendir( a, m, ee);
    tst_anotado_agregar_al_incicio(a, b, pa, pb);
    //tst_anotado_agregar_anotados_despues_de_agregar(a, b, c, pa, pb);//corregir
    tst_carrera_camposNULL(ca);
    tst_carrera_nombreNULL(ca);
    tst_carrera_cambiar_nombre(ca);
    tst_carrera_get_LmateriaNULL(ca);
    tst_carrera_get_LmateriaNONULL(ca, lm);
    tst_materia_camposNULL(ma);
    tst_materia_nombreNULL(ma);
    tst_materia_nombreNONULL(ma);
    tst_carrera_nombreNULL(ca);   
    tst_materia_get_LestudiantesNULL(ma);
    tst_materia_get_LestudiantesNONULL(ma);
    tst_materia_get_carrera_nombreNULL(ma);
    tst_materia_get_carrera_nombreNONULL(ma);
   
    tst_estudiante_camposNULL(es);
    tst_estudiante_nombreNULL(es);
    tst_estudiante_nombreNONULL(es,nombre_es );
    tst_estudiante_apellidoNULL(es);
    tst_estudiante_apellidoNONULL(es, ape_es);
    tst_estudiante_get_edadCero(es);
    tst_estudiante_edad_negativa(es);
    tst_estudiante_set_edad18 (es);
    tst_estudiante_set_edad0 (es);
    tst_estudiante_get_carrera_nombreNULL(es);
    tst_estudiante_get_carrera_nombreNONULL(es,carr_es);
    tst_estudiante_get_anotadoNULL(es);
    tst_estudiante_set_anotadoNONULL(es, a_es);
    
    tst_Lcarrera_camposNULL(lc);
    tst_Lcarrera_get_carrera_SbusquedaNULL(lc);
    tst_Lcarrera_get_carrera_SbusqedaNONULL(lc, c_lc);
    tst_Lcarera_get_carrera_CbusquedaNONULL(c_lc, lc_o);
    tst_Lcarrera_get_carrera_primeroUltimo_segundoPrimero(c_lc, c_lc2, lc);
    tst_Lcarrera_get_carreras(c_lc, c_lc2, c_lc3, lc, cb);

    tst_Lmateria_camposNULL(lmat);
    tst_Lmateria_nombreNULL(lmat);
    tst_Lmateria_get_materiaNONULL(lmat, mat);
    tst_Lmateria_listaNULL_despuesNONULL(lmn, lmat, mat);
    tst_Lmateria_addMateria_cambio_direccion(lmat, lmats, mat);
    
    tst_Lestudiantes_campoNULL(l_e);
    tst_Lestudiante_get_estudianteNULL(l_e);
    tst_Lestudiate_get_sig_estudianteNULL(l_e);
    tst_Lestudiante_addAntes_sigActual(l_e, pl_e, l_e2);
    tst_Lestudiante_Add_DespuesDe(l_e, l_e3);
    tst_Lestudiante_addElemento_listaNULL(l_e, est);
    tst_Lestudiante_addElemento_listaNONULL(l_e, est);
    tst_Lestudiante_AddEstudianteNONULL_listaNONULL(l_e, est);    
    tst_Lestudiante_addEdad_listaNULL(a1, l_e);
    tst_Lestudiante_addEdad_mayor_listaNONULL(a1, a2, l_e);
    tst_Lestudiante_addEdad_menor_listaNONULL(a1, a2, l_e);
    tst_Lestudiante_addEdad_listaNONULL_varios(l_e, a1, a2, a3, a4);
    tst_Lestudiante_addNombre_listaNULL(l_e, a1);
    tst_Lestudiante_addNombre_listaNONULL(l_e, a1);
    tst_Lestudiante_addNombre_varios_listaNONULL(l_e, a1, a2);
    tst_Lestudiante_addNombre_variosInvertidos_listaNONULL(l_e, a1, a2);
    tst_Lestudiantes_addNombre_todos_listaNONULL(l_e, a1, a2, a3, a4);
    tst_Lestudiantes_addNombre_todosInvertido_listaNONULL(l_e, a1, a2, a3, a4);    

    
    //TODO: interface, lector, frees en listas
    printf("TERMINADO");

    return 0;
}

void tst_anotado_elementoNoNull_campoNULL(Anotado* a) {
    nombre = "ANOTADO nuevo elemento no nulo y campos nulos";
    resultado = ((a != NULL) && (a->nota == 0) && (a->materia == NULL) && (a->sig_mat == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a);
}

void tst_anotado_nota0(Anotado* a){
    nombre = "ANOTADO nuevo elemento nota 0";
    resultado = (a->nota == 0) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a); 
}
void tst_anotado_materiaNULL(Anotado* a){
    nombre = "ANOTADO nuevo elemento materia null";
    resultado = (a->materia == NULL) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a);
}
void tst_anotado_materiaNoNULL(Anotado* a, Materia* m){
    set_materia_nombre(m, "m");
    set_anotado_materia(a, m);
    nombre = "ANOTADO nuevo elemento materia no nula";
    resultado = (get_anotado_materia(a,"m") == m) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a);
}

void tst_anotado_siguienteNull(Anotado* a){
    nombre = "ANOTADO nuevo elemento siguiente null";
    resultado = (a->sig_mat == NULL) ? true : false;

    TEST(resultado, nombre);
    reset_anotado(a);
}

void tst_anotado_nota_valida(Anotado* a, Materia* m){
    set_anotado_materia(a, m);
    set_anotado_nota(a, 1, "m");
    nombre = "ANOTADO nuevo elemento nota valida";
    resultado = (get_anotado_nota(a, "m") == 1) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a); 
}

void tst_anotado_nota_invalida_negativa(Anotado* a, Materia* m){
    set_anotado_materia(a, m);
    set_anotado_nota(a, -1, "m");
    nombre = "ANOTADO nuevo elemento nota invalida negativa";
    resultado = (get_anotado_nota(a, "m") == 0) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a);
}

void tst_anotado_nota_invalida_mayor(Anotado* a, Materia* m){
    set_anotado_materia(a, m);
    set_anotado_nota(a, 11, "m");
    nombre = "ANOTADO nuevo elemento nota invalida mayor a diez";
    resultado = (get_anotado_nota(a, "m") == 0) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a);
} 
void tst_anotado_get_materia_valida(Anotado* a, Materia* m){
    set_anotado_materia(a, m);
    nombre = "ANOTADO nuevo elemento get materia valida";
    resultado = (get_anotado_materia(a, "m") == m) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a);
}

void tst_anotado_get_materia_invalida(Anotado* a, Materia* m){
    set_anotado_materia(a, m);
    nombre = "ANOTADO nuevo elemento get materia invalida";
    resultado = (get_anotado_materia(a, "n") == NULL) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a);
}

void tst_anotado_find_anatado_materia(Anotado* a, Materia* m){
    set_anotado_materia(a, m);
    Materia* mm = nueva_materia();
    set_materia_nombre(mm, "mm");
    Materia* mmm = nueva_materia();
    set_materia_nombre(mmm, "mmm");
    Anotado* aa = nuevo_anotado();
    set_anotado_materia(aa, mm);
    Anotado* aaa = nuevo_anotado();
    set_anotado_materia(aaa, mmm);
    add_anotado(&a, &aa);
    add_anotado(&a, &aaa);
    nombre = "ANOTADO nuevo elemento find anotado materia";
    resultado = (get_anotado_materia(a, "m") == m) ? true : false;
    TEST(resultado, nombre);

    nombre = "ANOTADO nuevo elemento find anotado materia";
    resultado = (get_anotado_materia(a, "mm") == mm) ? true : false;
    TEST(resultado, nombre);

    nombre = "ANOTADO nuevo elemento find anotado materia";
    resultado = (get_anotado_materia(a, "mmm") == mmm) ? true : false;
    TEST(resultado, nombre);

    reset_anotado(aaa);
    reset_anotado(aa);
    reset_anotado(a);

}
    

//nuevos tests de estudiantes
    
void tst_estudiante_anotarse(Anotado* a, Materia* m, Estudiante* ee){
    set_materia_nombre(m, "m");
    set_estudiante_nombre(ee, "nicolas");
    set_anotado_materia(a, m);
    anotarse(ee, m);
    anotarse(ee, m);
    Lista_Estudiantes* l_m = get_materia_lista_estudiantes(m);

    nombre = "ESTUDIANTE anotarse";
    resultado = ((ee != NULL && m != NULL && a != NULL && l_m != NULL)
        && get_lista_estudiantes_estudiante(l_m, "nicolas") == ee
        && ee->sig_mat->materia == m
        && a->materia == m
        && ee->sig_mat->sig_mat->materia == m) ? true : false;
    TEST(resultado, nombre);
    reset_anotado(a);
    reset_estudiante(ee);
    reset_materia(m);
    reset_lista_estudiantes(l_m);
}

void tst_estudiante_rendir(Anotado* a, Materia* m, Estudiante* ee){
    ee = nuevo_estudiante();
    set_materia_nombre(m, "m");
    set_estudiante_nombre(ee, "nicolas");
    set_anotado_materia(a, m);
    anotarse(ee, m);
    rendir(m, ee, 1);
    nombre = "ESTUDIANTE rendir";
    resultado = (ee->sig_mat->materia == m, m->sig_est->estudiante == ee && ee->sig_mat->nota == 1);
    TEST(resultado, nombre);

    rendir(m, ee, 4);
    nombre = "ESTUDIANTE rendir";
    resultado = (ee->sig_mat->materia == m, m->sig_est->estudiante == NULL && ee->sig_mat->nota == 4);
    TEST(resultado, nombre);
}

    

void tst_anotado_agregar_al_incicio(Anotado* a, Anotado* b, Anotado* pa, Anotado* pb){
    pa = a;
    pb = b;
    add_anotado(&a, &b);
    nombre = "ANOTADO nuevo elemento add b en a, sig_mat = a, y a = b";
    resultado = ((pa == a->sig_mat) && (pb == a)) ? true : false;

    //clarificacion, el puntero a se transforma en siguiente y b en la raiz insercion al inicio
    TEST(resultado, nombre);
    reset_anotado(a);
    reset_anotado(b);
}
void tst_anotado_agregar_anotados_despues_de_agregar(Anotado* a, Anotado* b, Anotado* c, Anotado* pa, Anotado* pb){    
    pa = a;
    pb = b;
    Anotado* pc = c;
    add_anotado(&a,&b);
    add_anotado(&a,&c);
    nombre = "ANOTADO nuevo elemento add b despues add c en a, a = c, a->sig = b, a->sig->sig = a";
    resultado = ((pc == a) && (pb == a->sig_mat) && (pa == pa->sig_mat->sig_mat)) ? true : false;

    TEST(resultado, nombre);
    reset_anotado(a);
    reset_anotado(b);
    reset_anotado(c);
}

void tst_carrera_camposNULL(Carrera* ca){
    
    nombre = "CARRERA nuevo elemento con campos nulos";
    resultado = ((ca != NULL) && (get_carrera_nombre(ca) == NULL) && (ca->sig_mat == NULL)) ? true : false;

    TEST(resultado, nombre);
    reset_carrera(ca);
}

    
void tst_carrera_cambiar_nombre(Carrera* ca){
    char* name = "ing compu";
    set_carrera_nombre(ca, name);
    nombre = "CARRERA nuevo elemento cambio nombre no nulo";
    resultado = (strcmp(get_carrera_nombre(ca), name) == 0) ? true : false;

    TEST(resultado, nombre);
    reset_carrera(ca);
}
    
void tst_carrera_get_LmateriaNULL (Carrera* ca){
    nombre = "CARRERA nuevo elemento get lista materias nulo";
    resultado = (get_carrera_lista_materias(ca) == NULL) ? true : false;

    TEST(resultado, nombre);
    reset_carrera(ca);
}
/*
void tst_add_Carrera(){
     //esto se testea en otro lado
    set_carrera_lista_materias(ca, lm);
    nombre = "CARRERA nuevo elemento add lista materias";
    resultado = ((lm != NULL) && (get_carrera_lista_materias(ca) != NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_carrera(ca);
}
*/    

    
void tst_carrera_get_LmateriaNONULL(Carrera* ca, Lista_Materias* lm){
    nombre = "CARRERA nuevo elemento get lista materias no nulo";
    set_carrera_lista_materias(ca, lm);
    resultado = ((lm != NULL) && (get_carrera_lista_materias(ca) != NULL) && (ca->sig_mat == lm)) ? true : false;

    TEST(resultado, nombre);
    reset_carrera(ca);
}
   

    
void tst_materia_camposNULL(Materia* ma){
    nombre = "MATERIA nuevo elemento con campos nulos";
    resultado = ((ma != NULL) && (get_materia_nombre(ma) == NULL) && (get_materia_nombre_carrera(ma) == NULL) && (get_materia_lista_estudiantes(ma) == NULL)) ? true : false;

    TEST(resultado, nombre);
    reset_materia(ma);
}
    
void tst_materia_nombreNULL(Materia* ma){
    nombre = "MATERIA nuevo elemento get nombre nulo";
    resultado = ((ma != NULL) && (get_materia_nombre(ma) == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_materia(ma);
}
   
void tst_materia_nombreNONULL(Materia* ma){
    nombre = "MATERIA nuevo elemento set nombre no nulo";
    char* nombre_ma = "mate";
    set_materia_nombre(ma, nombre_ma);
    resultado = ((ma != NULL) && (get_materia_nombre(ma) == nombre_ma)) ? true : false;
    TEST(resultado, nombre);
    reset_materia(ma);
}

void tst_carrera_nombreNULL(Carrera* ca){
    nombre = "CARRERA nuevo elemento nombre nulo";
    resultado = (get_carrera_nombre(ca) == NULL) ? true : false;
    TEST(resultado, nombre);
    reset_carrera(ca);
}

void tst_materia_get_LestudiantesNULL(Materia* ma){
    nombre = "MATERIA nuevo elemento get lista estudiantes null";
    resultado = ((ma != NULL) && (get_materia_lista_estudiantes(ma) == NULL)) ? true : false;

    TEST(resultado, nombre);
    reset_materia(ma);
}
    
void tst_materia_get_LestudiantesNONULL(Materia* ma){
    nombre = "MATERIA nuevo elemento get lista estudiantes no nulo";
    Lista_Estudiantes* le = nueva_lista_estudiantes();
    set_materia_lista_estudiantes(ma, le);
    resultado = ((ma != NULL) && (get_materia_lista_estudiantes(ma) == le)) ? true : false;

    TEST(resultado, nombre);
    reset_materia(ma);
}
    
void tst_materia_get_carrera_nombreNULL(Materia* ma){
    nombre = "MATERIA nuevo elemento get nombre carrera null";
    resultado = ((ma != NULL) && (get_materia_nombre_carrera(ma) == NULL)) ? true : false;
    
    TEST(resultado, nombre);
    reset_materia(ma);
}
    
void tst_materia_get_carrera_nombreNONULL(Materia* ma){
    nombre = "MATERIA nuevo elemento get nombre carrera no nulo";
    char* nombre_ma = "ing compu";
    set_materia_nombre_carrera(ma, nombre_ma);
    resultado = ((ma != NULL) && (get_materia_nombre_carrera(ma) == nombre_ma)) ? true : false;
    TEST(resultado, nombre);
    reset_materia(ma);

}

void tst_estudiante_camposNULL(Estudiante* es){
    nombre = "ESTUDIANTE nuevo elemento con campos nulos";
    resultado = ((es != NULL) && (get_estudiante_nombre(es) == NULL) && (get_estudiante_apellido(es) == NULL) && (get_estudiante_edad(es) == 0) && (get_estudiante_nombre_carrera(es) == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}
    
void tst_estudiante_nombreNULL(Estudiante* es){
    nombre = "ESTUDIANTE nuevo elemento get name nulo";
    resultado = ((es != NULL) && (get_estudiante_nombre(es) == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}
    
void tst_estudiante_nombreNONULL(Estudiante* es,char* nombre_es){
    nombre = "ESTUDIANTE nuevo elemento get name no nulo";
    set_estudiante_nombre(es, nombre_es);
    resultado = ((es != NULL) && (get_estudiante_nombre(es) == nombre_es)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}

void tst_estudiante_apellidoNULL(Estudiante* es){
    nombre = "ESTUDIANTE nuevo elemento get apellido nulo";
    resultado = ((es != NULL) && (get_estudiante_apellido(es) == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}
    

    
void tst_estudiante_apellidoNONULL (Estudiante* es,char* ape_es){
    nombre = "ESTUDIANTE nuevo elemento get apellido no nulo";
    set_estudiante_apellido(es, ape_es);
    resultado = ((es != NULL) && (get_estudiante_apellido(es) == ape_es)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}
    
void tst_estudiante_get_edadCero(Estudiante* es){
    nombre = "ESTUDIANTE nuevo elemento get edad 0";
    resultado = ((es != NULL) && (get_estudiante_edad(es) == 0)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}

void tst_estudiante_edad_negativa(Estudiante* es){
    nombre = "ESTUDIANTE nuevo elemento set edad negativo da 0";
    set_estudiante_edad(es, -1);
    resultado = ((es != NULL) && (get_estudiante_edad(es) == 0)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);

}

void tst_estudiante_set_edad18 (Estudiante* es){
    nombre = "ESTUDIANTE nuevo elemento set edad 18 da 18";
    set_estudiante_edad(es, 18);
    resultado = ((es != NULL) && (get_estudiante_edad(es) == 18)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}

void tst_estudiante_set_edad0 (Estudiante* es){
    nombre = "ESTUDIANTE nuevo elemento set edad 11 da 0";
    set_estudiante_edad(es, 11);
    resultado = ((es != NULL) && (get_estudiante_edad(es) == 0)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}
    
void tst_estudiante_get_carrera_nombreNULL(Estudiante* es){
    nombre = "ESTUDIANTE nuevo elemento get nombre carrera nulo";
    resultado = ((es != NULL) && (get_estudiante_nombre_carrera(es) == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}
    
void tst_estudiante_get_carrera_nombreNONULL(Estudiante* es, char* carr_es ){
    nombre = "ESTUDIANTE nuevo elemento get apellido no nulo";
    set_estudiante_nombre_carrera(es, carr_es);
    resultado = ((es != NULL) && (get_estudiante_nombre_carrera(es) == carr_es)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}
    

    
void tst_estudiante_get_anotadoNULL(Estudiante* es){
    nombre = "ESTUDIANTE nuevo elemento get anotado nulo";
    resultado = ((es != NULL) && (get_estudiante_anotado(es) == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es); 
}
    
void tst_estudiante_set_anotadoNONULL(Estudiante* es, Anotado* a_es ){
    nombre = "ESTUDIANTE nuevo elemento set anotado no nulo";
    set_estudiante_anotado(es, a_es);
    resultado = ((es != NULL) && (a_es != NULL) && (get_estudiante_anotado(es) == a_es)) ? true : false;
    TEST(resultado, nombre);
    reset_estudiante(es);
}
     
    
void tst_Lcarrera_camposNULL(Lista_Carreras* lc){
    nombre = "LISTA CARRERA nuevo elemento con campos nulos";
    resultado = ((lc != NULL) && (get_carrera_lista_carreras(lc, NULL) == NULL) && (lc->sig_car == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_carreras(lc);
}
    
void tst_Lcarrera_get_carrera_SbusquedaNULL(Lista_Carreras* lc){
    nombre = "LISTA CARRERA nuevo elemento get carrera sin busqueda nulo";
    resultado = ((lc != NULL) && (get_carrera_lista_carreras(lc, NULL) == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_carreras(lc);
}
    
void tst_Lcarrera_get_carrera_SbusqedaNONULL(Lista_Carreras* lc, Carrera* c_lc){
    nombre = "LISTA CARRERA nuevo elemento get carrera sin busqueda no nulo";
    add_carrera_lista_carreras(&lc, c_lc);
    resultado = ((lc != NULL) && (c_lc != NULL) && (get_carrera_lista_carreras(lc, NULL) == c_lc)) ? true : false;
    
    TEST(resultado, nombre);
    reset_lista_carreras(lc);
}
void tst_Lcarera_get_carrera_CbusquedaNONULL(Carrera* c_lc,Lista_Carreras* lc_o ){
    nombre = "LISTA CARRERA nuevo elemento get carrera con busqueda no nulo y lista nula";
    add_carrera_lista_carreras(&lc_o, c_lc);
    resultado = ((lc_o != NULL) && (c_lc != NULL) && (get_carrera_lista_carreras(lc_o, NULL) == c_lc)) ? true : false;
      
    TEST(resultado, nombre);
    reset_lista_carreras(lc_o);
    }
    
void tst_Lcarrera_get_carrera_primeroUltimo_segundoPrimero(Carrera* c_lc, Carrera* c_lc2, Lista_Carreras* lc){

    //Lista_Carreras* lc = nueva_lista_carreras();
    nombre = "LISTA CARRERA nuevo elemento get carrera primer valor ultimo add segundo valor primer add";
    add_carrera_lista_carreras(&lc, c_lc);
    add_carrera_lista_carreras(&lc, c_lc2);
    resultado = ((lc != NULL) && (c_lc != NULL) && (c_lc2 != NULL) && (lc->carrera == c_lc2) && (lc->sig_car->carrera == c_lc)) ? true : false;

    TEST(resultado, nombre);
    reset_lista_carreras(lc);
}    
    
    

void tst_Lcarrera_get_carreras(Carrera* c_lc, Carrera* c_lc2, Carrera* c_lc3,Lista_Carreras* lc,Carrera* cb){
    nombre = "LISTA CARRERA nuevo elemento get carrera sonido primera carrera en lista";
    set_carrera_nombre(c_lc, "ing compu");
    set_carrera_nombre(c_lc2, "ing amb");
    set_carrera_nombre(c_lc3, "ing sonido");
    add_carrera_lista_carreras(&lc, c_lc);
    add_carrera_lista_carreras(&lc, c_lc2);
    add_carrera_lista_carreras(&lc, c_lc3);
    cb = get_carrera_lista_carreras(lc, "ing sonido");
    resultado = ((cb != NULL) && (strcmp(get_carrera_nombre(cb), "ing sonido") == 0)) ? true : false;
    TEST(resultado, nombre);

    nombre = "LISTA CARRERA nuevo elemento get carrera amb segunda carrera en lista";
    cb = get_carrera_lista_carreras(lc, "ing amb");
    resultado = ((cb != NULL) && (strcmp(get_carrera_nombre(cb), "ing amb") == 0)) ? true : false;
    TEST(resultado, nombre);

    nombre = "LISTA CARRERA nuevo elemento get carrera compu tercera carrera en lista";
    cb = get_carrera_lista_carreras(lc, "ing compu");
    resultado = ((cb != NULL) && (strcmp(get_carrera_nombre(cb), "ing compu") == 0)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_carreras(lc);
}

    

void tst_Lmateria_camposNULL(Lista_Materias* lmat){
    nombre = "LISTA MATERIA nuevo elemento con campos nulos";
    resultado = (lmat != NULL && lmat->materia == NULL && lmat->sig_mat == NULL) ? true : false;
    TEST(resultado, nombre);
    reset_lista_materias(lmat);

}

void tst_Lmateria_nombreNULL(Lista_Materias* lmat){
    nombre = "LISTA MATERIA nuevo elemento get materia nulo sin nombre";
    resultado = ((lmat != NULL) && (get_materia_lista_materias(lmat, NULL) == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_materias(lmat);
}
    

    
void tst_Lmateria_get_materiaNONULL(Lista_Materias* lmat, Materia* mat){
    set_materia_nombre(mat, "mate");
    add_materia_lista_materias(&lmat, mat);
    nombre = "LISTA MATERIA nuevo elemento get materia nueva despues de add no nulo";
    resultado = ((lmat != NULL) && (get_materia_lista_materias(lmat, "mate") == mat)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_materias(lmat);

}
void tst_Lmateria_listaNULL_despuesNONULL(Lista_Materias* lmn, Lista_Materias* lmat, Materia* mat){//
    
    add_materia_lista_materias(&lmn, mat);
    nombre = "LISTA MATERIA lista nula get materia nueva despues de add no nulo";
    resultado = ((lmat != NULL) && (get_materia_lista_materias(lmn, "mate") == mat)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_materias(lmn);
} 
    
void tst_Lmateria_addMateria_cambio_direccion(Lista_Materias* lmat, Lista_Materias* lmats, Materia* mat){
    lmats = lmat;
    add_materia_lista_materias(&lmat, mat);
    add_materia_lista_materias(&lmat, mat);
    nombre = "LISTA MATERIA nuevo elemento add materia cambia dire al agregar otro nodo";
    resultado = ((lmat != lmats)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_materias(lmat);
}
    //falta delete por ahi mas casos?
void tst_Lestudiantes_campoNULL(Lista_Estudiantes* l_e){
    nombre = "LISTA ESTUDIANTES nuevo elemento con campos nulos";
    resultado = ((l_e != NULL) && (l_e->estudiante == NULL) && (l_e->sig_est == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);

}

void tst_Lestudiante_get_estudianteNULL(Lista_Estudiantes* l_e){
    nombre = "LISTA ESTUDIANTES nuevo elemento get estudiante nulo";
    resultado = ((l_e != NULL) && (get_lista_estudiantes_estudiante(l_e, NULL) == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
}

void tst_Lestudiate_get_sig_estudianteNULL(Lista_Estudiantes* l_e){
    nombre = "LISTA ESTUDIANTES nuevo elemento get sig estudiante nulo";
    resultado = ((l_e != NULL) && (l_e->sig_est == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
}
void tst_Lestudiante_addAntes_sigActual(Lista_Estudiantes* l_e, Lista_Estudiantes* pl_e, Lista_Estudiantes* l_e2){
    pl_e = l_e;
    antes_de(&l_e, l_e2);
    nombre = "LISTA ESTUDIANTES nuevo elemento antes de sig actual";
    resultado = ((l_e != NULL) && (l_e2 != NULL) && (l_e == l_e2) && (l_e->sig_est == pl_e)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
    reset_lista_estudiantes(l_e2);
}

void tst_Lestudiante_Add_DespuesDe(Lista_Estudiantes* l_e,Lista_Estudiantes* l_e3){
    despues_de(l_e, l_e3);
    nombre = "LISTA ESTUDIANTES nuevo elemento despues_de sig es nuevo";
    resultado = ((l_e != NULL) && (l_e3 != NULL) && (l_e->sig_est == l_e3) && (l_e3->sig_est == NULL)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
    reset_lista_estudiantes(l_e3);
}
void tst_Lestudiante_addElemento_listaNULL(Lista_Estudiantes* l_e, Estudiante* est  ){
    l_e = NULL;
    add_estudiante_lista_estudiantes(&l_e, est);
    nombre = "LISTA ESTUDIANTES add elemento a lista nula";
    resultado = ((l_e != NULL) && (l_e->estudiante == est)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
}

void tst_Lestudiante_addElemento_listaNONULL(Lista_Estudiantes* l_e, Estudiante* est ){
    add_estudiante_lista_estudiantes(&l_e, est);
    nombre = "LISTA ESTUDIANTES add elemento a lista no nula";
    resultado = ((l_e != NULL) && (l_e->estudiante == est)) ? true : false;
    
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
}

void tst_Lestudiante_AddEstudianteNONULL_listaNONULL(Lista_Estudiantes* l_e,  Estudiante* est){
    add_estudiante_lista_estudiantes(&l_e, est);
    add_estudiante_lista_estudiantes(&l_e, est);
    nombre = "LISTA ESTUDIANTES add elemento a lista no nula y estudiante no nulo";
    resultado = ((l_e != NULL) && (l_e->estudiante == est) && (l_e->estudiante == est)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
}
void tst_Lestudiante_addEdad_listaNULL(Estudiante* a1,Lista_Estudiantes* l_e){
    a1->nombre = "alejandro";
    a1->edad = 17;
    l_e = NULL;
    add_estudiante_lista_estudiantes_edad(&l_e, a1);
    nombre = "LISTA ESTUDIANTES add edad a lista nula";
    resultado = ((l_e != NULL) && (l_e->estudiante == a1)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
}

void tst_Lestudiante_addEdad_mayor_listaNONULL(Estudiante* a1, Estudiante* a2, Lista_Estudiantes* l_e){
    a2->nombre = "nicolas";
    a2->edad = 22;

    l_e = nueva_lista_estudiantes();
    add_estudiante_lista_estudiantes_edad(&l_e, a1);
    add_estudiante_lista_estudiantes_edad(&l_e, a2);
    nombre = "LISTA ESTUDIANTES add edad a lista no nula con estudiante de mayor edad";//a1->edad < a2->edad
    resultado = ((l_e != NULL) && (l_e->estudiante == a1) && (l_e->sig_est->estudiante == a2)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
}

void tst_Lestudiante_addEdad_menor_listaNONULL(Estudiante* a1, Estudiante* a2 ,Lista_Estudiantes* l_e){

    a1->nombre = "alejandro";
    a1->edad = 17;

    a2->nombre = "nicolas";
    a2->edad = 22;
    l_e = nueva_lista_estudiantes();

    add_estudiante_lista_estudiantes_edad(&l_e, a2);
    add_estudiante_lista_estudiantes_edad(&l_e, a1);
    nombre = "LISTA ESTUDIANTES add edad a lista no nula con estudiante de menor edad";//a1->edad < a2->edad
    resultado = ((l_e != NULL) && (l_e->estudiante == a1) && (l_e->sig_est->estudiante == a2)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
    
}

void tst_Lestudiante_addEdad_listaNONULL_varios(Lista_Estudiantes* l_e, Estudiante* a1,Estudiante* a2,Estudiante* a3, Estudiante* a4){
    a3->nombre = "osvaldo";
    a3->edad = 31;
    
    a4->nombre = "pablo";
    a4->edad = 22;
    
    /*a1->nombre = "alejandro";
    a1->edad = 17;

    a2->nombre = "nicolas";
    a2->edad = 22;*/

    l_e = nueva_lista_estudiantes();

    add_estudiante_lista_estudiantes_edad(&l_e, a2);
    add_estudiante_lista_estudiantes_edad(&l_e, a1);
    add_estudiante_lista_estudiantes_edad(&l_e, a3);
    add_estudiante_lista_estudiantes_edad(&l_e, a4);
    nombre = "LISTA ESTUDIANTES add edad a lista no nula varios";//17/22ale/22pablo/31
    resultado = ((l_e != NULL) && (l_e->estudiante == a1) && (l_e->sig_est->estudiante == a2) && (l_e->sig_est->sig_est->estudiante == a4) && (l_e->sig_est->sig_est->sig_est->estudiante == a3)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
}

void tst_Lestudiante_addNombre_listaNULL(Lista_Estudiantes* l_e, Estudiante* a1){
    nombre = "LISTA ESTUDIANTES add nombre a lista nula";
    l_e = NULL;
    add_estudiante_lista_estudiantes_nombre(&l_e, a1);
    resultado = ((l_e != NULL) && (strcmp(l_e->estudiante->nombre, a1->nombre) == 0) && (l_e->estudiante == a1)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);

}

void tst_Lestudiante_addNombre_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1){
    nombre = "LISTA ESTUDIANTES add nombre a lista no nula";
    l_e = nueva_lista_estudiantes();
    add_estudiante_lista_estudiantes_nombre(&l_e, a1);
    resultado = ((l_e != NULL) && (strcmp(l_e->estudiante->nombre, a1->nombre) == 0) && (l_e->estudiante == a1)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);

}

void tst_Lestudiante_addNombre_varios_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1,  Estudiante* a2){
    l_e = nueva_lista_estudiantes();
    nombre = "LISTA ESTUDIANTES add nombre a lista no nula ale nico";
    add_estudiante_lista_estudiantes_nombre(&l_e, a1);
    add_estudiante_lista_estudiantes_nombre(&l_e, a2);
    resultado = ((l_e != NULL) && (strcmp(l_e->estudiante->nombre, a1->nombre) == 0) && (l_e->estudiante == a1) && (l_e->sig_est->estudiante == a2) && (strcmp(l_e->sig_est->estudiante->nombre, a2->nombre) == 0)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);

}

void tst_Lestudiante_addNombre_variosInvertidos_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1,  Estudiante* a2){
    l_e = nueva_lista_estudiantes();
    nombre = "LISTA ESTUDIANTES add nombre a lista no nula nico ale";
    add_estudiante_lista_estudiantes_nombre(&l_e, a2);
    add_estudiante_lista_estudiantes_nombre(&l_e, a1);
    resultado = ((l_e != NULL) && (strcmp(l_e->estudiante->nombre, a1->nombre) == 0) && (l_e->estudiante == a1) && (l_e->sig_est->estudiante == a2) && (strcmp(l_e->sig_est->estudiante->nombre, a2->nombre) == 0)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);

}

void tst_Lestudiantes_addNombre_todos_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1, Estudiante* a2, Estudiante* a3,Estudiante* a4){
    l_e = nueva_lista_estudiantes();
    nombre = "LISTA ESTUDIANTES add nombre a lista no nula ale nico osvaldo pablo";
    add_estudiante_lista_estudiantes_nombre(&l_e, a1);
    add_estudiante_lista_estudiantes_nombre(&l_e, a2);
    add_estudiante_lista_estudiantes_nombre(&l_e, a3);
    add_estudiante_lista_estudiantes_nombre(&l_e, a4);
    resultado = ((l_e != NULL) && (strcmp(l_e->estudiante->nombre, a1->nombre) == 0) && (l_e->estudiante == a1) && (l_e->sig_est->estudiante == a2) && (strcmp(l_e->sig_est->estudiante->nombre, a2->nombre) == 0) && (l_e->sig_est->sig_est->estudiante == a3) && (strcmp(l_e->sig_est->sig_est->estudiante->nombre, a3->nombre) == 0) && (l_e->sig_est->sig_est->sig_est->estudiante == a4) && (strcmp(l_e->sig_est->sig_est->sig_est->estudiante->nombre, a4->nombre) == 0)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);

}

void tst_Lestudiantes_addNombre_todosInvertido_listaNONULL(Lista_Estudiantes* l_e, Estudiante* a1, Estudiante* a2, Estudiante* a3,Estudiante* a4){
    l_e = nueva_lista_estudiantes();
    nombre = "LISTA ESTUDIANTES add nombre a lista no nula pablo osvaldo nico ale";
    add_estudiante_lista_estudiantes_nombre(&l_e, a4);
    add_estudiante_lista_estudiantes_nombre(&l_e, a3);
    add_estudiante_lista_estudiantes_nombre(&l_e, a2);
    add_estudiante_lista_estudiantes_nombre(&l_e, a1);
    resultado = ((l_e != NULL) && (strcmp(l_e->estudiante->nombre, a1->nombre) == 0) && (l_e->estudiante == a1) && (l_e->sig_est->estudiante == a2) && (strcmp(l_e->sig_est->estudiante->nombre, a2->nombre) == 0) && (l_e->sig_est->sig_est->estudiante == a3) && (strcmp(l_e->sig_est->sig_est->estudiante->nombre, a3->nombre) == 0) && (l_e->sig_est->sig_est->sig_est->estudiante == a4) && (strcmp(l_e->sig_est->sig_est->sig_est->estudiante->nombre, a4->nombre) == 0)) ? true : false;
    TEST(resultado, nombre);
    reset_lista_estudiantes(l_e);
   }    

void TEST(int resultado,char* nombre) {
    usleep(10000);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (resultado) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("EXITO ");
    } else {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("FALLO ");
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    printf("%s\n", nombre);
}
/* No funciona en cmd el formato de color
void TEST(int resultado, char* nombre){
    if(resultado == true){
        green();
        printf("EXITO ");
    }else{
        red();
        printf("FALLO ");
    }
    reset();
    printf("%s\n", nombre);
}
*/

void reset_anotado(Anotado* anotado){
    anotado->materia = NULL;
    anotado->nota = 0;
    anotado->sig_mat = NULL;
}

void reset_carrera(Carrera* carrera){
    carrera->nombre_carrera = NULL;
    carrera->sig_mat = NULL;
}

void reset_materia(Materia* materia){
    materia->carrera = NULL;
    materia->nombre_materia = NULL;
    materia->sig_est = NULL;
}

void reset_estudiante(Estudiante* estudiante){
    estudiante->apellido = NULL;
    estudiante->carrera = NULL;
    estudiante->edad = 0;
    estudiante->nombre = NULL;
    estudiante->sig_mat = NULL;
}

void reset_lista_carreras(Lista_Carreras* lista_carreras){
    lista_carreras->carrera = NULL;
    lista_carreras->sig_car = NULL;
}

void reset_lista_materias(Lista_Materias* lista_materias){
    lista_materias->materia = NULL;
    lista_materias->sig_mat = NULL;
}

void reset_lista_estudiantes(Lista_Estudiantes* lista_estudiantes){
    lista_estudiantes->estudiante = NULL;
    lista_estudiantes->sig_est = NULL;
}
/* Formato de color, funciona solo en Linux/Unix
void red() {
    printf("\033[1;31m");
}

void green(){
    printf("\033[1;32m");
}

void reset(){
    printf("\033[0m");
}
*/