/** 
 * @brief It implements the space module
 * 
 * @file space.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/*
    En la estructura se pone las propiedades del objecto (su Id y su nombre)
 */
struct _Object {
  Id id;                    /* El Id del objeto */
  char name[WORD_SIZE + 1]; /* Nombre del objeto */
};

/*
    Crea memoria para un objecto y lo inicializa
*/
Object* object_create(Id id) {
  Object *newObject = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));
  if (newObject == NULL) {
    return NULL;
  }

  /* Inicializacin del objeto */
  newObject->id = id;
  newObject->name[0] = '\0';

  return newObject;
}

/*
    Destruye el objeto
  */
STATUS object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;
  return OK;
}

/*
    Obtiene Id del objeto
  */
Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

STATUS object_set_id(Object *object, Id id){
  if (object == NULL || id == NO_ID) {
    return ERROR;
  }

  object->id = id;
  return OK;
}

/*
    Pone el nombre del objeto
  */
STATUS object_set_name(Object* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }
  return OK;
}
/*
    Obtiene el nombre del objeto
  */
const char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}


/*
    Printea la informacion del objeto
  */
STATUS objeto_print(Object* object) {
  if (!object) {
    return ERROR;
  }

  /* 1. Poner la Id y el nombre del objeto */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
 
  return OK;
}