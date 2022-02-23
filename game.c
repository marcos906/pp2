/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

/* Funciones que hacen que funciones los comandos. Son privadas. */
void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);
void game_command_take(Game *game);
void game_command_drop(Game *game);

/**
   Game interface implementation
*/

STATUS game_create(Game *game)
{
  Space *s;
  int i;
  /*Pasa por todos los espacios*/
  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }
  /*Crea el objeto y el jugador y dice que no hay ultimo comando*/
  game->bob = player_create(1);
  for ( i = 0; i < MAX_OBJECTS; i++)
  {
    game->obj[i]= object_create(1);
  }
  
  
  
  s= game_get_space(game, 1); 
  space_set_object(s,game->obj[0]);
  space_set_object(s,game->obj[1]);
  space_set_object(s,game->obj[2]);
  space_set_object(s,game->obj[3]);
  
  game->last_cmd = NO_CMD;

  return OK;
}


STATUS game_destroy(Game *game)
{
  int i = 0;
  /*Bucle que va destruyendo cada espacio*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  return OK;
}

STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;
  /*Control errores*/
  if (space == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }
  /*Aade el espacio space a los espacios*/
  game->spaces[i] = space;

  return OK;
}

Id game_get_space_id_at(Game *game, int position)
{
  /*Si la posicion es menor que 0 o es mayor que el numero de espacios dice que no existe*/
  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }
  /*Obtiene la id de la posicion*/
  return space_get_id(game->spaces[position]);
}

Space *game_get_space(Game *game, Id id)
{
  int i = 0;
  /*Control de errores*/
  if (id == NO_ID)
  {
    return NULL;
  }
  /*Bucle para saber cual de los espacios corresponde con la id*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}


STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;
  /*Hace un swith para llamar a las funciones de los comandos*/
  switch (cmd)
  {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      game_command_next(game);
      break;

    case BACK:
      game_command_back(game);
      break;

    case TAKE:
      game_command_take(game);
      break;

    case DROP:
      game_command_drop(game);
      break;

    default:
      break;
  }

  return OK;
}

T_Command game_get_last_command(Game *game)
{
  /*Coge el ultimo comando*/
  return game->last_cmd;
}

void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }
  /*Printea la localizacion actual del objeto y jugador*/
  printf("=> Object location: %d\n", (int)object_get_id(game->obj[0]));
  printf("=> Object location: %d\n", (int)object_get_id(game->obj[1]));
  printf("=> Object location: %d\n", (int)object_get_id(game->obj[2]));
  printf("=> Object location: %d\n", (int)object_get_id(game->obj[3]));
  printf("=> Player location: %d\n", (int)player_get_id(game->bob));
}

BOOL game_is_over(Game *game)
{
  return FALSE;
}

/**
   Calls implementation for each action 
*/

void game_command_unknown(Game *game)
{
  /*Si no hay comando no hace nada*/
}

void game_command_exit(Game *game)
{
  
}

void game_command_next(Game *game)
{
  /*Pone todas las variables a 0*/
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  /*Almacena la Id de bob en una variable*/
  space_id = player_get_id(game->bob);
  if (space_id == NO_ID)
  {
    return;
  }
  /*Bucle por todos los espacios*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        /*Nueva Id del jugador*/
        player_set_id(game->bob, current_id);
        if (player_get_object(game->bob)!=NULL)
        {
           object_set_id(game->obj[0], current_id);
          object_set_id(game->obj[1], current_id);
          object_set_id(game->obj[2], current_id);
          object_set_id(game->obj[3], current_id);
          
        }
        
      }
      return;
    }
  }
}

/*Lo mismo que en next pero al reves*/

void game_command_back(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = player_get_id(game->bob);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID)
      {
        player_set_id(game->bob, current_id);
        if (player_get_object(game->bob)!=NULL)
        {
          object_set_id(game->obj[0], current_id);
          object_set_id(game->obj[1], current_id);
          object_set_id(game->obj[2], current_id);
          object_set_id(game->obj[3], current_id);
        }
      }
      return;
    }   
  }
}
void game_command_take(Game *game)
{
 int i;
 if(player_get_object(game->bob) != NULL)
    return;

 for ( i = 0; i < MAX_OBJECTS; i++)
 {
   
  if (object_get_id(game->obj[i])==player_get_id(game->bob))
  {
    player_set_object(game->bob,game->obj[i]);
  }
  
 }
 
   return;
  
}
  
  
 
  


void game_command_drop(Game *game)
{
  if(player_get_object(game->bob) == NULL)
    return;
  
  player_set_object(game->bob,NULL);
  
}
 Object *game_get_object(Game *game,Id id){
   int i;
   for ( i = 0; i < MAX_OBJECTS; i++)
   {
     if (object_get_id(game->obj[i])==id)
     {
       return game->obj[i];
     }
     
   }
    return NULL;
 }
STATUS game_add_object(Game *game, Object *object)
{
  int i = 0;

  if (object == NULL)
    return ERROR;

  while (game->obj[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
    return ERROR;

  game->obj[i] = object;

  return OK;
}
