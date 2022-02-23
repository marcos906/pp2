/*
    @Descripcion: Implemeta las funciones definidas en player.h
    @Nombre: player.c
    @Autor: Marcos Hernan
    @date 14-02-2022
    @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"



struct _Player {
  Id id;                    /*!< Numero id del jugador, tiene que ser único */
  char name[WORD_SIZE + 1]; /*!< Nombre del jugador */
  Id location;              /*!< Localicación del jugador */
  Object *obj;              /*!< objeto o no */
  int health;
};

Player* player_create(Id id){
    Player *newPlayer = NULL;

    /* Control de errores */
  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));
  if (newPlayer == NULL) {
    return NULL;

    /* Inicialización de un nuevo jugador*/
  newPlayer->id = id;
  newPlayer->name[0] = '\0';

  newPlayer->obj = FALSE;
  newPlayer->health=MAX_HEALTH;
  }

  return newPlayer;

}

STATUS player_destroy(Player* player){
    if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;
  return OK;
}

Id player_get_id(Player* player){
    if (!player) {
    return NO_ID;
  }
  return player->location;
}

STATUS player_set_id(Player* player, Id id){
  if (!player || id == NO_ID) {
    return ERROR;
  }
  player->location = id;
  return OK;
}

STATUS player_set_name(Player* player, char* name){
    if (!player) {
    return NO_ID;
  }
  return player->id;

}

const char* player_get_name(Player* player, char* name){
    if (!player || !name) {
    return NULL;
  }

  if (!strcpy(player->name, name)) {
    return NULL;
  }
  return player->name;
}

STATUS player_set_object(Player* player, Object *obj){
    if (!player) {
    return ERROR;
  }
  player->obj = obj;
  return OK;
}

Object *player_get_object(Player* player){
    if (!player) {
    return NULL;
  }
  return player->obj;
}

STATUS Player_set_health(Player* Player){
    if (!Player) {
    return ERROR;
  }
  Player->health--;
  if (Player->health==0)
  {
     return ERROR;
  }
  
  return OK;
}

int Player_get_health(Player* Player){
    if (!Player) {
    return -1;
  }
  return Player->health;
}

STATUS player_print(Player* player){

  /* Control de errores */
  if (!player) {
    return ERROR;
  }

  /* 1. Muestra por pantalla el id del jugador, su nombre y su localización */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location: %ld; Health: %d)\n", player->id, player->name, player->location, player->health);
  
  /* 2. Muestra por pantalla si tiene un bojeto o no */
  if (player_get_object(player)) {
    fprintf(stdout, "---> Player owns an object.\n");
  } else {
    fprintf(stdout, "---> Player do not owns an object.\n");
  }

  return OK;
}

