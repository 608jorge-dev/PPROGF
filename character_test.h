/**
 * @brief It declares the tests for the character module
 *
 * @file character_test.h
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
#include "character.h"
#include "test.h"

/**
 * @test Test character creation
 * @pre Character ID
 * @post Non NULL pointer to character
 */
void test1_character_create();

/**
 * @test Test character creation
 * @pre Character ID
 * @post Character_ID == Supplied Character Id
 */
void test2_character_create();

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
 * @test Test function for space_name setting
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
 * @test Test function for character_object getting
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

/**
 * @test Test function for character_health setting
 * @pre Character health
 * @post Output==OK
 */
void test1_character_set_health();

/**
 * @test Test function for character_health setting
 * @pre Pointer to character = NULL
 * @post Output==ERROR
 */
void test2_character_set_health();

/**
 * @test Test function for character_health getting
 * @pre Character health
 * @post Output==Supplied Character health
 */
void test1_character_get_health();

/**
 * @test Test function for character_health getting
 * @pre Pointer to character = NULL
 * @post Output==NO_ID
 */
void test2_character_get_health();

/**
 * @test Test function for character_friendly setting
 * @pre Character friendliness
 * @post Output==OK
 */
void test1_character_set_friendly();

/**
 * @test Test function for character_friendly setting
 * @pre Pointer to character = NULL
 * @post Output==ERROR
 */
void test2_character_set_friendly();

/**
 * @test Test function for character_friendly getting
 * @pre Character friendliness
 * @post Output==Supplied Character friendliness
 */
void test1_character_get_friendly();

/**
 * @test Test function for character_friendly getting
 * @pre Pointer to character = NULL
 * @post Output==NO_ID
 */
void test2_character_get_friendly();

/**
 * @test Test function for space_message setting
 * @pre String with character message
 * @post Ouput==OK
 */
void test1_character_set_message();

/**
 * @test Test function for character_message setting
 * @pre Pointer to character = NULL
 * @post Output==ERROR
 */
void test2_character_set_message();

/**
 * @test Test function for character_message setting
 * @pre Pointer to character_message = NULL
 * @post Output==ERROR
 */
void test3_character_set_message();

/**
 * @test Test function for character_message getting
 * @pre Message of the character
 * @post Ouput==TRUE
 */
void test1_character_get_message();

/**
 * @test Test function for character_message getting
 * @pre Pointer to character = NULL
 * @post Ouput==NULL
 */
void test2_character_get_message();

#endif