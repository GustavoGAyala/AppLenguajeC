# **Programacion Bajo Nivel (Lenguaje C)**


Integrantes:
1.     Carlos Mauricio Aristizábal Bueno
2.     Facundo Seva
3.     Nicolas Benjamin Caceres Montenegro
4.     Gustavo Ayala

**Objetivos del sistema:**

**Desarrollar un sistema de estudiantes en C. Debe permitir:**
*                         -Dar de alta y listar estudiantes (HECHO)
*                         -Buscar estudiantes por nombre (HECHO)
*                         -Buscar estudiantes por rango de edad (HECHO)


**Además cada estudiante puede anotarse en N materias.**
*                         -Dar de alta y listar materias (HECHO)
*                         -Anotarse en una materia (HECHO)
*                         -Rendir una materia (HECHO)

El sistema debe poder soportar un gran listado de estudiantes y materias. **(HECHO)** \
Utilizar estructuras de datos para almacenar los listados. **(HECHO)**\
Decidir si se utiliza ordenamiento de los datos. **(Si utilizamos, por nombre y por edad)**\
Utilizar la creatividad para que el manejo del sistema sea lo más práctico posible. **(Hicimos un menu interactivo con opciones)**

**Limitaciones:**
*     El estudiante debe estar anotado en la materia para poder rendirla
*     Se pueden crear estudiantes con el mismo nombre pero las busquedas solo funcionan si el nombre no se repite
*     Al rendir la materia colocamos la nota de manera random para darle funcionalidad al sistema
*     Generamos una validacion de la fecha de nacimiento pero no la utilizamos en el sistema
*     Al realizar la interaccion con el Menu se deben respetar las Mayusculas y las minusculas o el sistema puede fallar

**Limitaciones de memoria:**

*     Estudiante: 106 bytes
*     Materia: 124 bytes
*     Carrera: 66 bytes
*     Anotados: 20 bytes
*     Lista_Estudiantes: 16 bytes
*     Lista_Carreras: 16 bytes
*     Lista_Materias: 16 bytes

**Ideas no-obligatorias de implementar pero que suman puntos:**
*     utilizar paginado
*     poder elegir el estudiante/materia de un listado reducido **(HECHO)**
*     generar estudiantes de prueba y materias aleatorias de forma masiva **(HECHO)**
*     estadísticas de los estudiantes y materias, etc.
*     árboles de correlatividad de materias
*     qué pasa si una materia anterior está desaprobada? Puede anotarse?
*     cálculo de promedios.
*     archivo de configuración general donde se especifican las variables del sistema. **(HECHO)**
*     mejoras en la interfaz de usuario (HECHO)
*     tests unitarios **(HEHCO)**
    


Grabar un video de máximo 10 minutos (puede ser menos) mostrando el funcionamiento del sistema y los puntos implementados. 
En esta oportunidad no es necesario enfocarse tanto en el código, ya que se puede ver en el repositorio. 
Concéntrese en presentar el proyecto funcionando.
