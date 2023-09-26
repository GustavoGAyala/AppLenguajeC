#include "include/declaraciones.h"

int main(){
    tests();
    sleep(2);
    cambiar_apariencia();
    if (menu_inicio_sesion()) {
        ejecutar_menu();
    }
    //tests();
    //Lista_Carreras* lista_carreras = nueva_lista_carreras();
    //cargar_programa(&lista_carreras);
    return 0;
}