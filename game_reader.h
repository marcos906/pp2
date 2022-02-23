/** 
 * @brief It defines the game reader
 * 
 * @file game_reader.h
 * @author Profesores PPROG
 * @version 2.0 
 * @date 21-02-2022
 * @copyright GNU Public License
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "types.h"
#include "game.h"
#include "object.h"
#include "player.h"

STATUS game_load_spaces(Game *game, char *filename);
STATUS game_create_from_file(Game *game, char *filename);
STATUS game_load_objects(Game *game, char *filename);
Space *game_reader_get_space(Game *game, Id id);


#endif