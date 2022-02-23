/** 
 * @brief It implements the game reader and all the associated calls
 * for each command
 * 
 * @file game_reader.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 21-02-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"


STATUS game_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_create_from_file(Game *game, char *filename)
{

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_load_spaces(game, filename) == ERROR)
    return ERROR;

  /* The player and the object are located in the first space */
  player_set_id(game->bob, game_get_space_id_at(game, 0));
  object_set_id(game->obj[0], game_get_space_id_at(game, 0));

  object_set_id(game->obj[1], game_get_space_id_at(game, 0));



  object_set_id(game->obj[2], game_get_space_id_at(game, 0));
  object_set_id(game->obj[3], game_get_space_id_at(game, 0));
  
  return OK;
}
BOOL game_reader_spaces_connected(Game *game, Space *space1, Space *space2)
{
  if (!space1 || !space2)
    return FALSE;
  if (space_get_north(space1) == space_get_id(space2))
    return TRUE;
  if (space_get_south(space1) == space_get_id(space2))
    return TRUE;
  if (space_get_west(space1) == space_get_id(space2))
    return TRUE;
  if (space_get_east(space1) == space_get_id(space2))
    return TRUE;
  return FALSE;
}


STATUS game_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "", name[WORD_SIZE] = "", *toks = NULL;
  Id id = NO_ID, spaceId = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

  if (!filename)
    return ERROR;

  file = fopen(filename, "r");
  if (file == NULL)
    return ERROR;

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      
      toks = strtok(NULL, "|");
      spaceId = atol(toks);
      object = object_create(id);
      if (spaceId != NO_ID)
      {
        object_set_id(object, id);
        
        object_set_name(object, name);
        space_set_object(game_get_space(game, spaceId), object);
        game_add_object(game, object);
      }
    }
  }

  if (ferror(file))
    status = ERROR;

  fclose(file);

  return status;
}