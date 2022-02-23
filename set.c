/** 
 * @brief It implements the space module
 * 
 * @file set.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Set {
  Id *ids;
  int n_ids;

};
Set* set_create(int n_ids){
    Set *create;
    int i;
    create = (Set*)malloc(n_ids*sizeof(Set));
    if(create == NULL)
      return NULL;
    create->n_ids = n_ids;
    for(i=0;i<create->n_ids;i++){
        create->ids[i] = NO_ID;
    }
    return create;
}

STATUS set_destroy(Set *set){
  if(set == NULL)
    return ERROR;
  free(set);
  return OK;
} 

Set* set_add(Set *set, Id id){
  int i;
  if(set == NULL)
    return ERROR;
  for(i=0;i<set->n_ids;i++){
    if(set->ids[i] == NO_ID)
      set->ids[i] = id;
  }  
  return set;
}

Set* set_del(Set *set, Id id){
  int i;
  if(set == NULL)
    return ERROR;
  for(i=0;i<set->n_ids;i++){
    if(set->ids[i] == id)
      set->ids[i] = NO_ID;
  }  
  return set;
}

STATUS set_print(FILE *f,Set *set){
    int i;
  if(set == NULL|| f==NULL)
    return ERROR;
  
  for ( i = 0; i <set->n_ids; i++)
  {
     fprintf(f,"\nObjeto %ld", set->ids[i]);
      
  }
  return OK;
  
}
Id set_get_id(Set *set){
  int i;
  if (set==NULL)
  {
    return NO_ID;
  }
  for ( i = 0; i < set->n_ids; i++)
  {
    if (set->ids[i]!=NO_ID)
    {
      return set->ids[i];
    }
    
  }
  return NO_ID;
}