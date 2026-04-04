/**
 * @brief It defines the tests for the player module
 *
 * @file player_test.h
 * @author Álvaro Bravo González
 * @version 1.0
 * @date 04-03-2025
 * @copyright GNU Public License
 */

#ifndef CHARACTER_TEST_H
#define CHARACTER_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "test.h"

/**
 * @test Test player creation
 * @pre Player ID
 * @post Non NULL pointer to player
 */
void test1_player_create();

/**
 * @test Test player creation
 * @pre Player ID
 * @post Player_ID == Supplied Player Id
 */
void test2_player_create();

/**
 * @test Test function for player_id setting
 * @pre Player ID
 * @post Output==OK
 */
void test1_player_set_id();

/**
 * @test Test function for player_id setting
 * @pre Pointer to player = NULL
 * @post Output==ERROR
 */
void test2_player_set_id();

/**
 * @test Test function for player_id getting
 * @pre Player ID
 * @post Output==Supplied Player Id
 */
void test1_player_get_id();

/**
 * @test Test function for player_id getting
 * @pre Pointer to player = NULL
 * @post Output==NO_ID
 */
void test2_player_get_id();

/**
 * @test Test function for player_name setting
 * @pre String with player name
 * @post Ouput==OK
 */
void test1_player_set_name();

/**
 * @test Test function for player_name setting
 * @pre Pointer to player = NULL
 * @post Output==ERROR
 */
void test2_player_set_name();

/**
 * @test Test function for player_name setting
 * @pre Pointer to player_name = NULL
 * @post Output==ERROR
 */
void test3_player_set_name();

/**
 * @test Test function for player_name getting
 * @pre Name of the player
 * @post Ouput==TRUE
 */
void test1_player_get_name();

/**
 * @test Test function for player_name getting
 * @pre Pointer to player = NULL
 * @post Ouput==NULL
 */
void test2_player_get_name();

/**
 * @test Test function for player_gdesc setting
 * @pre String with player graphic description
 * @post Ouput==OK
 */
void test1_player_set_gdesc();

/**
 * @test Test function for player_gdesc setting
 * @pre Pointer to player = NULL
 * @post Output==ERROR
 */
void test2_player_set_gdesc();

/**
 * @test Test function for player_gdesc setting
 * @pre Pointer to player_gdesc = NULL
 * @post Output==ERROR
 */
void test3_player_set_gdesc();

/**
 * @test Test function for player_gdesc getting
 * @pre Graphic description of the player
 * @post Ouput==TRUE
 */
void test1_player_get_gdesc();

/**
 * @test Test function for player_gdesc getting
 * @pre Pointer to charaplayercter = NULL
 * @post Ouput==NULL
 */
void test2_player_get_gdesc();

/**
 * @test Test function for player_object adding
 * @pre Id of the player to add
 * @post Ouput==OK
 */
void test1_player_add_object();

/**
 * @test Test function for player_object adding
 * @pre Pointer to player = NULL
 * @post Ouput==ERROR
 */
void test2_player_add_object();

/**
 * @test Test function for player_object deleting
 * @pre Id of the object to delete
 * @post Ouput==OK
 */
void test1_player_del_object();

/**
 * @test Test function for player_object deleting
 * @pre Pointer to player = NULL
 * @post Ouput==ERROR
 */
void test2_player_del_object();

/**
 * @test Test function for player_object finding
 * @pre Id of the object to find
 * @post Ouput==TRUE
 */
void test1_player_find_object();

/**
 * @test Test function for player_object finding
 * @pre Pointer to player = NULL
 * @post Ouput==FALSE
 */
void test2_player_find_object();

/**
 * @test Test function for player_object finding
 * @pre Id of the object to find
 * @post Ouput==FALSE
 */
void test3_player_find_object();

/**
 * @test Test function for player_location setting
 * @pre Player location
 * @post Output==OK
 */
void test1_player_set_location();

/**
 * @test Test function for player_location setting
 * @pre Pointer to player = NULL
 * @post Output==ERROR
 */
void test2_player_set_location();

/**
 * @test Test function for player_location getting
 * @pre Player location
 * @post Output==Supplied Player location
 */
void test1_player_get_location();

/**
 * @test Test function for player_location getting
 * @pre Pointer to player = NULL
 * @post Output==NO_ID
 */
void test2_player_get_location();

/**
 * @test Test function for player_health setting
 * @pre Player health
 * @post Output==OK
 */
void test1_player_set_health();

/**
 * @test Test function for player_health setting
 * @pre Pointer to player = NULL
 * @post Output==ERROR
 */
void test2_player_set_health();

/**
 * @test Test function for player_health getting
 * @pre Player health
 * @post Output==Supplied Player health
 */
void test1_player_get_health();

/**
 * @test Test function for player_health getting
 * @pre Pointer to player = NULL
 * @post Output==NO_ID
 */
void test2_player_get_health();

#endif