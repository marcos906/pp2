/*
    @Descripcion: Implemeta las funciones definidas en Enemy.h
    @Nombre: Enemy.c
    @Autor: Marcos Hernan
    @date 14-02-2022
    @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enemy.h"



struct _Enemy {
  Id id;                    /*!< Numero id del enemigo, tiene que ser único */
  char name[WORD_SIZE + 1]; /*!< Nombre del enemigo */
  Id location;              /*!< Localicación del enemigo */
 int health;                /*Vida del enemigo*/
};

Enemy* Enemy_create(Id id){
    Enemy *newEnemy = NULL;

    /* Control de errores */
  if (id == NO_ID)
    return NULL;

  newEnemy = (Enemy *) malloc(sizeof (Enemy));
  if (newEnemy == NULL) {
    return NULL;

    /* Inicialización de un nuevo enemigo*/
  newEnemy->id = id;
  newEnemy->name[0] = '\0';
  newEnemy->health=MAX_HEALTH;
  
  }

  return newEnemy;

}

STATUS Enemy_destroy(Enemy* Enemy){
    if (!Enemy) {
    return ERROR;
  }

  free(Enemy);
  Enemy = NULL;
  return OK;
}

Id Enemy_get_id(Enemy* Enemy){
    if (!Enemy) {
    return NO_ID;
  }
  return Enemy->location;
}

STATUS Enemy_set_id(Enemy* Enemy, Id id){
  if (!Enemy || id == NO_ID) {
    return ERROR;
  }
  Enemy->location = id;
  return OK;
}

STATUS Enemy_set_name(Enemy* Enemy, char* name){
    if (!Enemy) {
    return NO_ID;
  }
  return Enemy->id;

}

const char* Enemy_get_name(Enemy* Enemy, char* name){
    if (!Enemy || !name) {
    return NULL;
  }

  if (!strcpy(Enemy->name, name)) {
    return NULL;
  }
  return Enemy->name;
}

STATUS Enemy_set_health(Enemy* Enemy){
    if (!Enemy) {
    return ERROR;
  }
  Enemy->health--;
  if (Enemy->health==0)
  {
     return ERROR;
  }
  
  return OK;
}

int Enemy_get_health(Enemy* Enemy){
    if (!Enemy) {
    return -1;
  }
  return Enemy->health;
}

STATUS Enemy_print(Enemy* Enemy){

  /* Control de errores */
  if (!Enemy) {
    return ERROR;
  }

  /* 1. Muestra por pantalla el id del enemigo, su nombre y su localización y su vida */
  fprintf(stdout, "--> Enemy (Id: %ld; Name: %s; Location: %ld; Health:%d)\n", Enemy->id, Enemy->name, Enemy->location,Enemy->health);
  
  

  return OK;
}

