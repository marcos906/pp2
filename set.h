/**
 * @brief It defines the space interface
 *
 * @file set.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */



#include "types.h"
#include"object.h"


typedef struct _Set Set;


Set* set_create(int n_ids);
STATUS set_destroy(Set *set);
Set* set_add(Set *set, Id id);
Set* set_del(Set *set, Id id);
STATUS set_print(FILE *f,Set *set);
Id set_get_id(Set *set);