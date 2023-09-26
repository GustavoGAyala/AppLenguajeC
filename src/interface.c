#include "../include/declaraciones.h"


bool menu_inicio_sesion() {

    char username[LOGIN_LONGITUD_MAXIMA];
    char password[LOGIN_LONGITUD_MAXIMA];
    int intentos = INTENTOS;
    bool inicioSesionExitoso = false;

    
    while (intentos > 0 && !inicioSesionExitoso) {
    
        imprimir_encabezado("== Menu de Inicio de Sesion ==");

        printf("\tNombre de usuario: ");
        scanf(" %[^\n]", username);
        printf("\tContrasena: ");
        scanf(" %[^\n]", password);

        if (menu_inicio_sesion_logica(username, password) == 1) {
            inicioSesionExitoso = true;
            printf("\tInicio de sesion exitoso. Bienvenido, %s\n\n\n", username);

            printf("        /\\_/\\\n");
            printf("       ( ^_^ )\n");
            printf("       (\")__(\")\n");
            sleep(3);
        } else {
            intentos--;
            printf("\tCredenciales incorrectas. Quedan %d intento(s).\n\n\n", intentos);
            printf("        /\\_/\\\n");
            printf("       ( o_o )\n");
            printf("       (\")__(\")\n");
            sleep(3);
        }
    }
    return inicioSesionExitoso;
}

Lista_Estudiantes* lista_estudiantes;
Lista_Estudiantes* lista_estudiantes_nombre;
Lista_Estudiantes* lista_estudiantes_edad;
Lista_Carreras* lista_carreras;

void ejecutar_menu(){

    lista_carreras = nueva_lista_carreras();
    cargar_programa(&lista_carreras);

    int opcion;

      do {

        imprimir_encabezado("== Menu Principal ==");

        printf("\t1.- Gestionar Estudiante\n");
        printf("\t2.- Gestionar Carrera\n");
        printf("\t0.- Salir\n");
        printf("\tIndica la opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: 
                menu_gestionar_estudiante();
                break;
            case 2: 
                menu_gestionar_carrera();
                break;
            case 0: 
                salir();
                break;
            default:
                opcion_invalida();
                break;
        }
    } while (opcion != 0);
}

void menu_gestionar_estudiante() {

    int opcion_estudiante;

    do {

        imprimir_encabezado("== Gestion de Estudiantes ==");
        
        printf("\t1.- Mostrar lista de Estudiantes\n");
        printf("\t2.- Gestionar un Estudiante\n");
        printf("\t3.- Dar de alta un nuevo Estudiante\n");
        printf("\t0.- Regresar al menu anterior\n");
        printf("\tIndica la opcion: ");
        scanf("%d", &opcion_estudiante);

        switch (opcion_estudiante) {
            case 1:
                menu_imprimir_lista_estudiantes();
                break;
            case 2:
                menu_gestion_estudiante();
                break;
            case 3:
                menu_alta_estudiante();
                break;
            case 0:
                break;
            default:
                opcion_invalida();
                break;
        }
    } while (opcion_estudiante != 0);
}

void menu_gestion_estudiante(){

    Estudiante* estudiante_seleccionado;

    estudiante_seleccionado = menu_buscar_estudiante();
    char* carrera_estudiante_seleccionado = get_estudiante_nombre_carrera(estudiante_seleccionado);

    int opcion_estudiante;
    do {
        imprimir_encabezado("== Anotarce o Rendir ==");

        printf("\n\t1.- Anotarse\n");
        printf("\t2.- Rendir\n");
        printf("\t0.- Regresar al menu anterior\n");
        printf("\tIndica la opcion: ");
        scanf("%d", &opcion_estudiante);

        switch (opcion_estudiante) {
            case 1:
            Carrera* carrera_p = carrera_estudiante(carrera_estudiante_seleccionado);
            Materia* materia = buscar_materia(carrera_p);
                
                anotarse(estudiante_seleccionado,materia);
                printf("anotado");
                sleep(2);
                break;
            case 2:
                Materia* materia_por_rendir = materia_anotado(estudiante_seleccionado);

                int nota = -1;
                do {
                printf("Ingrese la nota entre 0 y 10: ");
                scanf("%d", &nota);
                if (nota < 0 || nota > 10){
                    
                }
                }while(nota < 0 || nota > 10);
                
                rendir(materia_por_rendir,estudiante_seleccionado,nota);
                if(nota >= 4){
                    printf("Aprobado con: %d\n",nota);
                }else{
                    printf("Desaprobado con: %d\n",nota);
                }
                printf("\n");
                pausa();
                break;
            case 0:
                break;
            default:
                opcion_invalida();
        }
    }while(opcion_estudiante != 0);
}

Materia* materia_anotado (Estudiante* estudiante) {
       Anotado* puntero = get_estudiante_anotado(estudiante);
    int elementos = 20;
    
    Materia* pagina[elementos];
    int i = 0;
    
    while (puntero != NULL) {
        
        imprimir_encabezado(get_estudiante_nombre(estudiante));
        printf("%-5s %-100s %-15s\n","ID","Materia","Nota");

        while (i < elementos && puntero != NULL) {
            Materia* materia_actual = puntero->materia;
            pagina[i] = materia_actual;
            char* nombre_materia = get_materia_nombre(pagina[i]);
            int nota = get_anotado_nota(puntero, nombre_materia);
            printf("%-5d %-100s %-15d\r", i,nombre_materia,nota);
            
            puntero = puntero->sig_mat;
            i++;
        }
        int seleccion;
        printf("\n\tLa Materia que buscas se encuentra en la lista?\n\t -1. Si      \t -0. No\n");
        scanf("%1d", &seleccion);
        if (seleccion == 1) {
            int id_materia;
            printf("\nIntroduce el ID de la Materia a rendir: ");
            scanf("%d", &id_materia);
        
                if (id_materia >= 0 && id_materia < i) {
                    return pagina[id_materia];
                } else {
                    printf("\nID de Materia invalido.\n");
                }
        } else {
        i = 0;
        }
    }
}


Estudiante* menu_buscar_estudiante() {

    Estudiante* resultado; // = NULL;
    int opcion_buscar_estudiante;

    do {

        imprimir_encabezado("== Buscar Estudiantes ==");
        
        printf("\t1.- Buscar por Nombre\n");
        printf("\t2.- Buscar por rango de edad\n");
        printf("\t0.- Regresar al menu anterior\n");
        printf("\tIndica la opcion: ");
        scanf("%d", &opcion_buscar_estudiante);

        switch (opcion_buscar_estudiante) {
            case 1:
                resultado = buscar_estudiante_por_nombre();
                return resultado;
                break;
            case 2:
                resultado = buscar_estudiante_por_edad();
                return resultado;
                break;
            case 0:
                break;
            default:
                opcion_invalida();
                break;
        }
    } while (opcion_buscar_estudiante != 0);
    //aca no se retorna nada
}

Estudiante* buscar_estudiante_por_nombre(){

    int i = 0;
    int elementos = 20;
    Estudiante* pagina[elementos];

    Lista_Estudiantes* puntero = lista_estudiantes_nombre;
    char* palabra = (char*)malloc(21 * sizeof(char));

    printf("\tBuscar:\n\t");
    scanf(" %[^\n]",palabra);

    palabra = (char*)realloc(palabra, (strlen(palabra) + 1) * sizeof(char));
    palabra[strlen(palabra)] = '\0';

    printf("%-5s %-20s %-20s %-5s %-70s\n",
               "ID","Nombre", "Apellido", "Edad", "Carrera");

    while(puntero != NULL ){

        Estudiante* estudiante_actual = puntero->estudiante;
        if((strstr(get_estudiante_nombre(estudiante_actual), palabra)!= NULL)||
            (strstr(get_estudiante_apellido(estudiante_actual), palabra) != NULL)){

            printf("%-5d %-20s %-20s %-5d %-70s\n",
                i,
                get_estudiante_nombre(estudiante_actual),
                get_estudiante_apellido(estudiante_actual),
                get_estudiante_edad(estudiante_actual),
                get_estudiante_nombre_carrera(estudiante_actual));
                pagina[i] = estudiante_actual;
                i ++;
            }
        puntero = puntero->sig_est;
    }
    if (i == 0) {
        printf("%-5s %-20s %-20s %-5s %-70s\n",
               " ","NULL", "NULL", "NULL", "NULL");
        printf("\nNo se encontro el estudiante");
        sleep(1);
        return NULL;
    } else {
    int id;
    printf("\nIntroduce el ID del estudiante: ");
    scanf("%d", &id);
        if (id >= 0 && id < i) {
                return pagina[id];
        } else {
                printf("\nID invalido.\n");
        }
    free(palabra);
    }
}

Estudiante* buscar_estudiante_por_edad() {

    int i = 0;
    int elementos = 20;
    Estudiante* pagina[elementos];

    Lista_Estudiantes* puntero = lista_estudiantes_edad;
    int edad_min = -1;
    int edad_max = -2;

        while (edad_min > edad_max){
            printf("\n\tEdad Minima:\n\t");
            scanf("%d",&edad_min);
            printf("\n\tEdad Maxima:\n\t");
            scanf("%d",&edad_max);
        }

    printf("%-5s %-20s %-20s %-5s %-70s\n",
        "ID","Nombre", "Apellido", "Edad", "Carrera");

    while(puntero != NULL ){

        Estudiante* estudiante_actual = puntero->estudiante;
        int edad_estudiante_actual = get_estudiante_edad(estudiante_actual);
        if((edad_estudiante_actual >= edad_min) &&
            (edad_estudiante_actual <= edad_max)){

            printf("%-5d %-20s %-20s %-5d %-70s\n",
                i,
                get_estudiante_nombre(estudiante_actual),
                get_estudiante_apellido(estudiante_actual),
                get_estudiante_edad(estudiante_actual),
                get_estudiante_nombre_carrera(estudiante_actual));
                pagina[i] = estudiante_actual;
                i ++;
            
        }
        puntero = puntero->sig_est;
    }
        if (i == 0) {
        printf("%-5s %-20s %-20s %-5s %-70s\n",
               " ","NULL", "NULL", "NULL", "NULL");
        printf("\nNo se encontro el estudiante");
        sleep(1);
        return NULL;
    } else {
    int id;

    printf("\nIntroduce el ID del estudiante: ");
    scanf("%d", &id);
    if (id >= 0 && id < i) {
                return pagina[id];
            } else {
                printf("\nID invalido.\n");
            }
    }
}

int menu_alta_estudiante() {

    Estudiante* nuevo  = nuevo_estudiante();
    char* nombre = (char*)malloc(21 * sizeof(char));
    char* apellido = (char*)malloc(21 * sizeof(char));
    int edad;
    Carrera* elegida;
    char* carrera;

    imprimir_encabezado("== Alta de Estudiante ==");

    printf("\n\tNombre:");
    scanf(" %[^\n]",nombre);

    printf("\n\tApellido:");
    scanf(" %[^\n]",apellido);
    
    do {
        printf("\n\tEdad:");
        scanf("%d", &edad);

        if (edad <= 0) {
            printf("La edad ingresada, no es válida.\n");
        }
    } while (edad < 0);

    printf("A continuacion, elige la Carrera:", nombre);
    sleep(1);
    elegida = buscar_carrera(lista_carreras);
    carrera = elegida->nombre_carrera;

    nombre = (char*)realloc(nombre, (strlen(nombre) + 1) * sizeof(char));
    nombre[strlen(nombre)] = '\0';
    apellido = (char*)realloc(apellido, (strlen(apellido) + 1) * sizeof(char));
    apellido[strlen(apellido)] = '\0';

    set_estudiante_nombre(nuevo,nombre);
    set_estudiante_apellido(nuevo,apellido);
    set_estudiante_edad(nuevo,edad);
    set_estudiante_nombre_carrera(nuevo,carrera);

    add_estudiante_lista_estudiantes(&lista_estudiantes,nuevo);
    add_estudiante_lista_estudiantes_edad(&lista_estudiantes_edad,nuevo);
    add_estudiante_lista_estudiantes_nombre(&lista_estudiantes_nombre,nuevo);
    
    return 0;//se usa en algun lado?
}

void menu_imprimir_lista_estudiantes() {

    int opcion_lista_estudiante;

    do {

        imprimir_encabezado("== Lista de Estudiantes ==");
        
        printf("\t1.- Ver por Orden de creacion\n");
        printf("\t2.- Ver por orden Alfabetico\n");
        printf("\t3.- Ver por orden de Edad\n");
        printf("\t0.- Regresar\n");
        printf("\tIndica la opcion: ");
        scanf("%d", &opcion_lista_estudiante);

        switch (opcion_lista_estudiante) {
            case 1:
                imprimir_lista_estudiantes(lista_estudiantes);
                break;
            case 2:
                imprimir_lista_estudiantes(lista_estudiantes_nombre);
                break;
            case 3:
                imprimir_lista_estudiantes(lista_estudiantes_edad);
            case 0:
                break;
            default:
                opcion_invalida();
                break;
        }
    } while (opcion_lista_estudiante != 0);
}

void imprimir_lista_estudiantes(Lista_Estudiantes* lista) {

    Lista_Estudiantes* puntero = lista;

    imprimir_encabezado("== Lista ==");

    printf("%-20s %-20s %-5s %-75s\n",
        "Nombre", "Apellido", "Edad", "Carrera");

    while (puntero != NULL) {
        Estudiante* estudiante_actual = puntero->estudiante;
        printf("%-20s %-20s %-5d %-75s\n",
               get_estudiante_nombre(estudiante_actual),
               get_estudiante_apellido(estudiante_actual),
               get_estudiante_edad(estudiante_actual),
               get_estudiante_nombre_carrera(estudiante_actual));
        puntero = puntero->sig_est;
    }

    printf("Presione Enter para continuar...");
    getchar();
    getchar();
}

void menu_gestionar_carrera () {

    int opcion_carrera;

    do {

        imprimir_encabezado("== Gestion de Carreras ==");
        
        printf("\t1.- Mostrar lista de Carreras\n");
        printf("\t2.- Gestionar materias de una Carrera\n");
        printf("\t3.- Crear nueva Carrera\n");
        printf("\t0.- Regresar al menu anterior\n");
        printf("\tIndica la opcion: ");
        scanf("%d", &opcion_carrera);

        switch (opcion_carrera) {
            case 1:
                imprimir_lista_carreras(lista_carreras);
                break;
            case 2:
                menu_buscar_carrera();
                break;
            case 3:
                menu_alta_carrera();
                break;
            case 0:
                break;
            default:
                opcion_invalida();
                break;
        }
    } while (opcion_carrera != 0);
}

void menu_buscar_carrera() {
    Carrera* carrera_seleccionada = buscar_carrera(lista_carreras);
    menu_gestionar_materias(carrera_seleccionada);
}

void menu_alta_carrera() {

    Carrera* nueva = nueva_carrera();
    char* nombre = (char*)malloc(101 * sizeof(char));

    imprimir_encabezado("== Nueva Carrera ==");

    printf("\n\tNombre:");
    scanf(" %[^\n]", nombre);

    nombre = (char*)realloc(nombre, (strlen(nombre) + 1) * sizeof(char));
    nombre[strlen(nombre)] = '\0';

    set_carrera_nombre(nueva, nombre);
    set_carrera_lista_materias(nueva, nueva_lista_materias());
    add_carrera_lista_carreras(&lista_carreras, nueva);    
}

void imprimir_lista_carreras(Lista_Carreras* lista) {

    Lista_Carreras* puntero = lista;
    int elementos = 20;
    
    Carrera* pagina[elementos];
    int i = 0;
    int contador = 0;

    while (puntero != NULL){

        imprimir_encabezado("== Lista ==");

        printf("%-5s %-100s %-15s\n","ID","Carrera","Materias");

        while (i < elementos && puntero != NULL) {

            Carrera* carrera_actual = puntero->carrera;
            pagina[i] = carrera_actual;
            int contador_materia = 0;
            Lista_Materias* actual = carrera_actual->sig_mat;

            while (actual != NULL) {
                contador_materia++;
                actual = actual->sig_mat;
            }

            printf("%-5d %-100s %-20d\r", i, get_carrera_nombre(carrera_actual), contador_materia);

            puntero = puntero->sig_car;
            i++;
            contador++;
        }

        int seleccion;
        printf("\tRegresar al menu anterior\n\t 1. Si      \t 0. No\n");
        scanf("%1d", &seleccion);
        if (seleccion == 1) {
            return;
        }else {
            i = 0;
        }
    }
}
Carrera* carrera_estudiante(char* nombre) {
    Lista_Carreras* puntero = lista_carreras;
    Carrera* encontrada = NULL;

    while (puntero != NULL && encontrada == NULL) {
        Carrera* carrera_actual = puntero->carrera;

        if (strcmp(get_carrera_nombre(carrera_actual), nombre) == 0) {
            encontrada = carrera_actual;
        }
        
        puntero = puntero->sig_car;
    }
    
    return encontrada;
}


Carrera* buscar_carrera(Lista_Carreras* lista) {

    Lista_Carreras* puntero = lista;
    int elementos = 20;
    Carrera* pagina[elementos];
    int i = 0;

    while (puntero != NULL) {

        imprimir_encabezado("== Lista de Carreras==");

        printf("%-5s %-100s %-15s\n","ID","Carrera","Materias");

        while (i < elementos && puntero != NULL) {
            Carrera* carrera_actual = puntero->carrera;
            pagina[i] = carrera_actual;
            int contador_materia = 0;
            Lista_Materias* actual = carrera_actual->sig_mat;

            while (actual != NULL) {
                contador_materia++;
                actual = actual->sig_mat;
            }

            printf("%-5d %-100s %-20d\r", i, get_carrera_nombre(carrera_actual), contador_materia);

            puntero = puntero->sig_car;
            i++;
        }
        
        int seleccion;
        printf("\n\tLa Carrera que buscas se encuentra en la lista?\n\t -1. Si      \t -0. No\n");
        scanf("%1d", &seleccion);
        
        if (seleccion == 1) {
            int id_carrera;
            printf("\nIntroduce el ID de la Carrera: ");
            scanf("%d", &id_carrera);
            
            if (id_carrera >= 0 && id_carrera < i) {
                return pagina[id_carrera];
            } else {
                printf("\nID de Carrera invalido.\n");
            }
        } else {
            i = 0;
        }
    }
    return NULL;//ojo con esto
}

void menu_gestionar_materias(Carrera* una_carrera){

    int opcion_materia;

    do {

        imprimir_encabezado("== Menu Gestionar Materias ==");
        
        printf("\n\t 1.- Mostrar lista de Materias\n");
        printf("\t2.- Agregar Materia\n");
        printf("\n\t0.- Regresar al menu anterior\n");
        printf("\tIndica la opcion: ");
        scanf("%d", &opcion_materia);

        switch (opcion_materia) {
            case 1:
                imprimir_lista_materias(una_carrera->sig_mat);
                break;
            case 2:
                menu_agregar_materia(una_carrera);
                break;
            case 0:
                break;
            default:
                opcion_invalida();
                break;
        }
    } while (opcion_materia != 0);
}

void menu_agregar_materia (Carrera* una_carrera) {
    
    imprimir_encabezado("== Nueva Materia ==");

    char* nombre  = (char*)malloc(101 * sizeof(char));
    printf("\n\tNombre de Materia:");
    scanf(" %[^\n]",nombre);

    nombre = (char*)realloc(nombre, (strlen(nombre) + 1) * sizeof(char));
    nombre[strlen(nombre)] = '\0';

    Materia* materia_nueva = nueva_materia();
    set_materia_nombre(materia_nueva,nombre);
    set_materia_nombre_carrera(materia_nueva,get_carrera_nombre(una_carrera));
    Lista_Materias* lista = get_carrera_lista_materias(una_carrera);
    add_materia_lista_materias(&lista, materia_nueva);
    set_carrera_lista_materias(una_carrera,lista);
}

Materia* buscar_materia(Carrera* carrera) {

    Lista_Materias* puntero = get_carrera_lista_materias(carrera);
    int elementos = 20;
    
    Materia* pagina[elementos];
    int i = 0;
    
    while (puntero != NULL) {
        
        imprimir_encabezado(get_carrera_nombre(carrera));
        printf("%-5s %-115s\n","ID","Materia");

        while (i < elementos && puntero != NULL) {
            Materia* materia_actual = puntero->materia;
            pagina[i] = materia_actual;
            printf("%-5d %-115s\r", i, get_materia_nombre(pagina[i]));

            puntero = puntero->sig_mat;
            i++;
        }
        int seleccion;
        printf("\n\tLa Materia que buscas se encuentra en la lista?\n\t -1. Si      \t -0. No\n");
        scanf("%1d", &seleccion);
        if (seleccion == 1) {
            int id_materia;
            printf("\nIntroduce el ID de la Materia: ");
            scanf("%d", &id_materia);
        
                if (id_materia >= 0 && id_materia < i) {
                    return pagina[id_materia];
                } else {
                    printf("\nID de Materia invalido.\n");
                }
        } else {
        i = 0;
        }
    }
    return NULL;//guarda che
}

void imprimir_lista_materias(Lista_Materias * lista) {

    Lista_Materias * puntero = lista;

    imprimir_encabezado("== Lista ==");

    printf("\t%-50s\n",
        "Nombre");
    
    Materia * materia_actual = NULL;

    while (puntero != NULL) {
        materia_actual = puntero->materia;
        printf("\t%-50s\n",
            get_materia_nombre(materia_actual));
        puntero = puntero->sig_mat;
    }

    printf("Presione Enter para continuar...");
    getchar();
    getchar();
}

void imprimir_encabezado(char* encabezado) {

    int longitud_encabezado = strlen(encabezado);
    int margen = (ANCHO_PANTALLA - longitud_encabezado)/2;
    limpiar_pantalla();
    imprimir_separador();
    printf("%*s%s%*s\n", margen, "", encabezado, ANCHO_PANTALLA - margen - longitud_encabezado - 1, "");
    imprimir_separador();
}

void imprimir_separador() {

    for (int i = 0; i < ANCHO_PANTALLA; i++) {
        printf("-");
    }
    printf("\n");
}

void opcion_invalida() {

    printf("\t\nLa opcion ingresada es invalida");
    sleep(1);
}

void salir(){

    imprimir_encabezado("== Saliendo ==");
    printf("\t\n Vuelve pronto!\n\n");
    printf("        /\\_/\\\n");
    printf("       ( TwT )\n");
    printf("       (\")__(\")\n");
    sleep(2);
}

/* Login:
Pre: Recibe dos cadenas de caracteres que serán usuario y contraseña respectivamente
Pos: Devuelve:
                -1: Si la lectura del archivo Almacen de usuarios no se encuentra
                 0: Si la combinación de usuario y contraseña no es encontrada
                 1: Si la combinación de usuario y contraseña Si es encontrada
*/
int menu_inicio_sesion_logica(char *username, char *password) {
    FILE *file = fopen(ALMACEN_USUARIOS, "r");
    if (file == NULL) {
        return -1;
    }

    char line[LOGIN_LONGITUD_MAXIMA];
    while (fgets(line, sizeof(line), file)) {
        char storedUsername[LOGIN_LONGITUD_MAXIMA];
        char storedPassword[LOGIN_LONGITUD_MAXIMA];
        sscanf(line, "%[^,],%s", storedUsername, storedPassword);
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            fclose(file);
            return 1;  // Coinciden, el inicio de sesión es exitoso
        }
    }

    fclose(file);
    return 0;  // No se encontró coincidencia, el inicio de sesión falló
}

void limpiar_pantalla() {
    system("cls");
}

void pausa() {
    system("pause");
}

void cambiar_apariencia() {
    system("COLOR 30");

    HANDLE id_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT pantalla_limite = {0, 0, ANCHO_PANTALLA - 1, ALTO_PANTALLA - 1};
    COORD pantalla_buffer = {ANCHO_PANTALLA, ALTO_PANTALLA};

    SetConsoleWindowInfo(id_consola, TRUE, &pantalla_limite);
    SetConsoleScreenBufferSize(id_consola, pantalla_buffer);
    SetConsoleTextAttribute(id_consola, COLOR_TEXTO);
}