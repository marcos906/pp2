/**
    @Descripcion: Nombra las funciones que se van a utilizar en el player.c
    @Nombre: player.h
    @Autor: Marcos Hernan
    @date 15-02-2022
    @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H
#define MAX_HEALTH 10
#include "types.h"
#include "object.h"
typedef struct _Player Player;

/*
    @Descripcion: crea la id del personaje
    @Autor: Marcos Hernan
    @parametros: Id
    @return: puntero a estructura player
  */
Player* player_create(Id id);


/*
    @Descripcion: destruye el player
    @Autor: Marcos Hernan
    @parametros: puntero a estructura player
    @return: OK o ERROR
  */
STATUS player_destroy(Player* player);

/*
    @Descripcion: coge la localizacion del personaje
    @Autor: Marcos Hernan
    @parametros: puntero a estructura player
    @return: id de la localización
  */
Id player_get_id(Player* player);

/*
    @Descripcion: define la localizacion del personaje
    @Autor: Marcos Hernan
    @parametros: puntero a estructura player y una id
    @return: OK o ERROR
  */
STATUS player_set_id(Player* player, Id id);

/*
    @Descripcion: le da un nombre al personaje
    @Autor: Marcos Hernan
    @parametros: puntero a estructura player y una cadena de caracteres
    @return: OK o ERROR
  */
STATUS player_set_name(Player* player, char* name);


/*
    @Descripcion: coge el nombre del personaje
    @Autor: Marcos Hernan
    @parametros: puntero a estructura player y una cadena de caracteres
    @return: una cadena de caracteres con el nombre del personaje
  */
const char* player_get_name(Player* player, char* name);

/*
    @Descripcion: determina si el personaje tiene un objeto o no
    @Autor: Marcos Hernan
    @parametros: puntero a estructura player y puntero a una estructura object
    @return: un numero booleano dependiendo de si tiene un objeto (TRUE) o no (FALSE)
  */
STATUS player_set_object(Player* player, Object *obj);

/*
    @Descripcion: obtiene si el espacio tiene un objeto o no
    @Autor: Marcos Hernan
    @parametros: puntero a estructura player 
    @return: un numero booleano dependiendo de si tiene un objeto (TRUE) o no (FALSE)
  */
Object *player_get_object(Player* player);

/**
  * @Descripcion: muestra la informacion del personaje
  * @Autor: Marcos Hernan
  * Esta función muestra por pantalla el nombre del personaje, su localicación y si tiene un objeto o no
  * @parametros: puntero a estructura player 
  * @return: devuelve OK si todo ha ido correctamente o ERROR si ha habido algun error
  */
STATUS player_print(Player* player);


int Player_get_health(Player* Player);
STATUS Player_set_health(Player* Player);

#endif