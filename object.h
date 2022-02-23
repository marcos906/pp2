/**
    @Descripcion: Nombra las funciones que se van a utilizar en el object.c
    @Nombre: object.h
    @Autor: Héctor Labrador Gómez
    @date 14-02-2022
    @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H
#define MAX_OBJECTS 4
#include "types.h"

typedef struct _Object Object;


/*
    @Descripcion: crea el objeto
    @Autor: Héctor Labrador Gómez
    @parametros: Id
    @return: EStructura objeto
  */
Object* object_create(Id id);

/*
    @Descripcion: Destruye el objeto
    @Autor: Héctor Labrador Gómez
    @parametros: Puntero a estructura Objeto
    @return: OK o ERROR
  */
STATUS object_destroy(Object* object);

/*
    @Descripcion: Coge la Id del objeto
    @Autor: Héctor Labrador Gómez
    @parametros: Puntero a estructura Objeto
    @return: Id del objeto
  */
Id object_get_id(Object* object);

STATUS object_set_id(Object *object, Id id);

/*
    @Descripcion: Nombra el objeto
    @Autor: Héctor Labrador Gómez
    @parametros: Puntero a estructura Objeto y puntero a un char
    @return: OK o ERROR
  */
STATUS object_set_name(Object* object, char* name);

/*
    @Descripcion: Coge el nombre de un objeto
    @Autor: Héctor Labrador Gómez
    @parametros: Puntero a estructura Objeto
    @return: Nombre del objeto
  */
const char* object_get_name(Object* object);

/*
    @Descripcion: Muestra el objeto
    @Autor: Héctor Labrador Gómez
    @parametros: Puntero a estructura Objeto
    @return: OK o ERROR
  */
STATUS object_print(Object* object);

#endif
