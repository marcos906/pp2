/**
    @Descripcion: Nombra las funciones que se van a utilizar en el Enemy.c
    @Nombre: Enemy.h
    @Autor: Marcos Hernan
    @date 15-02-2022
    @copyright GNU Public License
 */

#ifndef Enemy_H
#define Enemy_H
#define MAX_HEALTH 10
#include "types.h"
#include "object.h"
typedef struct _Enemy Enemy;

/*
    @Descripcion: crea la id del personaje
    @Autor: Marcos Hernan
    @parametros: Id
    @return: puntero a estructura Enemy
  */
Enemy* Enemy_create(Id id);


/*
    @Descripcion: destruye el Enemy
    @Autor: Marcos Hernan
    @parametros: puntero a estructura Enemy
    @return: OK o ERROR
  */
STATUS Enemy_destroy(Enemy* Enemy);

/*
    @Descripcion: coge la localizacion del personaje
    @Autor: Marcos Hernan
    @parametros: puntero a estructura Enemy
    @return: id de la localización
  */
Id Enemy_get_id(Enemy* Enemy);

/*
    @Descripcion: define la localizacion del personaje
    @Autor: Marcos Hernan
    @parametros: puntero a estructura Enemy y una id
    @return: OK o ERROR
  */
STATUS Enemy_set_id(Enemy* Enemy, Id id);

/*
    @Descripcion: le da un nombre al personaje
    @Autor: Marcos Hernan
    @parametros: puntero a estructura Enemy y una cadena de caracteres
    @return: OK o ERROR
  */
STATUS Enemy_set_name(Enemy* Enemy, char* name);


/*
    @Descripcion: coge el nombre del personaje
    @Autor: Marcos Hernan
    @parametros: puntero a estructura Enemy y una cadena de caracteres
    @return: una cadena de caracteres con el nombre del personaje
  */
const char* Enemy_get_name(Enemy* Enemy, char* name);

/*
    @Descripcion: determina si el personaje tiene un objeto o no
    @Autor: Marcos Hernan
    @parametros: puntero a estructura Enemy y puntero a una estructura object
    @return: un numero booleano dependiendo de si tiene un objeto (TRUE) o no (FALSE)
  */
STATUS Enemy_set_object(Enemy* Enemy);

/*
    @Descripcion: obtiene si el espacio tiene un objeto o no
    @Autor: Marcos Hernan
    @parametros: puntero a estructura Enemy 
    @return: un numero booleano dependiendo de si tiene un objeto (TRUE) o no (FALSE)
  */
int Enemy_get_object(Enemy* Enemy);

/**
  * @Descripcion: muestra la informacion del personaje
  * @Autor: Marcos Hernan
  * Esta función muestra por pantalla el nombre del personaje, su localicación y si tiene un objeto o no
  * @parametros: puntero a estructura Enemy 
  * @return: devuelve OK si todo ha ido correctamente o ERROR si ha habido algun error
  */
STATUS Enemy_print(Enemy* Enemy);




#endif