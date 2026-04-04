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
 * @test Test function for character_id setting
 * @pre Character ID
 * @post Output==OK
 */
void test1_character_set_id();

/**
 * @test Test function for character_id setting
 * @pre Pointer to character = NULL
 * @post Output==ERROR
 */
void test2_character_set_id();

/**
 * @test Test function for character_id getting
 * @pre Character ID
 * @post Output==Supplied Character Id
 */
void test1_character_get_id();

/**
 * @test Test function for character_id getting
 * @pre Pointer to character = NULL
 * @post Output==NO_ID
 */
void test2_character_get_id();

/**
 * @test Test function for character_name setting
 * @pre String with character name
 * @post Ouput==OK
 */
void test1_character_set_name();

/**
 * @test Test function for character_name setting
 * @pre Pointer to character = NULL
 * @post Output==ERROR
 */
void test2_character_set_name();

/**
 * @test Test function for character_name setting
 * @pre Pointer to character_name = NULL
 * @post Output==ERROR
 */
void test3_character_set_name();

/**
 * @test Test function for character_name getting
 * @pre Name of the character
 * @post Ouput==TRUE
 */
void test1_character_get_name();

/**
 * @test Test function for character_name getting
 * @pre Pointer to character = NULL
 * @post Ouput==NULL
 */
void test2_character_get_name();

/**
 * @test Test function for space_gdesc setting
 * @pre String with character graphic description
 * @post Ouput==OK
 */
void test1_character_set_gdesc();

/**
 * @test Test function for character_gdesc setting
 * @pre Pointer to character = NULL
 * @post Output==ERROR
 */
void test2_character_set_gdesc();

/**
 * @test Test function for character_gdesc setting
 * @pre Pointer to character_gdesc = NULL
 * @post Output==ERROR
 */
void test3_character_set_gdesc();

/**
 * @test Test function for character_gdesc getting
 * @pre Graphic description of the character
 * @post Ouput==TRUE
 */
void test1_character_get_gdesc();

/**
 * @test Test function for character_gdesc getting
 * @pre Pointer to character = NULL
 * @post Ouput==NULL
 */
void test2_character_get_gdesc();

#endif