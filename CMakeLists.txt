cmake_minimum_required(VERSION 3.25)
project(clion C)

set(CMAKE_C_STANDARD 99)

add_executable(grupo1 main.c src/anotados.c src/carreras.c src/estudiantes.c src/interface.c src/interface_logica.c src/lector.c src/lista_carreras.c src/lista_estudiantes.c src/lista_materias.c src/materias.c src/test.c)
