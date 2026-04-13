/**
 * @brief It declares the tests for the space module
 *
 * @file space_test.h
 * @author Profesores Pprog
 * @version 1.0
 * @date 17-02-2025
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "test.h"

/**
 * @test Test space creation
 * @pre Space ID
 * @post Non NULL pointer to space
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_id setting
 * @pre Space ID
 * @post Output==OK
 */
void test1_space_set_id();

/**
 * @test Test function for space_id setting
 * @pre Pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_id();

/**
 * @test Test function for space_id getting
 * @pre Space ID
 * @post Output==Supplied Space Id
 */
void test1_space_get_id();

/**
 * @test Test function for space_id getting
 * @pre Pointer to space = NULL
 * @post Output==NO_ID
 */
void test2_space_get_id();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre Pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre Pointer to space_name = NULL
 * @post Output==ERROR
 */
void test3_space_set_name();

/**
 * @test Test function for space_name getting
 * @pre Name of the space
 * @post Ouput==TRUE
 */
void test1_space_get_name();

/**
 * @test Test function for space_name getting
 * @pre Pointer to space = NULL
 * @post Ouput==NULL
 */
void test2_space_get_name();

/**
 * @test Test function for space_gdesc setting
 * @pre String with character graphic description
 * @post Ouput==OK
 */
void test1_space_set_gdesc();

/**
 * @test Test function for space_gdesc setting
 * @pre Pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_gdesc();

/**
 * @test Test function for space_gdesc setting
 * @pre Pointer to space_gdesc = NULL
 * @post Output==ERROR
 */
void test3_space_set_gdesc();

/**
 * @test Test function for space_gdesc getting
 * @pre Graphic description of the space
 * @post Ouput==TRUE
 */
void test1_space_get_gdesc();

/**
 * @test Test function for space_gdesc getting
 * @pre Pointer to space = NULL
 * @post Ouput==NULL
 */
void test2_space_get_gdesc();

/**
 * @test Test function for space_object adding
 * @pre Id of the object to add
 * @post Ouput==OK
 */
void test1_space_add_object();

/**
 * @test Test function for space_object adding
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test2_space_add_object();

/**
 * @test Test function for space_object deleting
 * @pre Id of the object to delete
 * @post Ouput==OK
 */
void test1_space_del_object();

/**
 * @test Test function for space_object deleting
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test2_space_del_object();

/**
 * @test Test function for space_object finding
 * @pre Id of the object to find
 * @post Ouput==TRUE
 */
void test1_space_find_object();

/**
 * @test Test function for space_object finding
 * @pre Pointer to space = NULL
 * @post Ouput==FALSE
 */
void test2_space_find_object();

/**
 * @test Test function for space_object finding
 * @pre Id of the object to find
 * @post Ouput==FALSE
 */
void test3_space_find_object();

/**
 * @test Test function for space_character setting
 * @pre Space Character
 * @post Output==OK
 */
void test1_space_set_character();

/**
 * @test Test function for space_character setting
 * @pre Pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_character();

/**
 * @test Test function for space_character getting
 * @pre Space Character
 * @post Output==Supplied Space Character
 */
void test1_space_get_character();

/**
 * @test Test function for space_character getting
 * @pre Pointer to space = NULL
 * @post Output==NO_ID
 */
void test2_space_get_character();

/**
 * @test Test function for space_character finding
 * @pre Id of the character to find
 * @post Ouput==TRUE
 */
void test1_space_find_character();

/**
 * @test Test function for space_character finding
 * @pre Pointer to space = NULL
 * @post Ouput==FALSE
 */
void test2_space_find_character();

/**
 * @test Test function for space_character finding
 * @pre Id of the character to find
 * @post Ouput==FALSE
 */
void test3_space_find_character();

/**
 * @test Test function for space_character setting
 * @pre Space Discovered
 * @post Output==OK
 */
void test1_space_set_discovered();

/**
 * @test Test function for space_character setting
 * @pre Pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_discovered();

/**
 * @test Test function for space_character getting
 * @pre Space Discovered
 * @post Output==Supplied Space Discovered
 */
void test1_space_get_discovered();

/**
 * @test Test function for space_character getting
 * @pre Pointer to space = NULL
 * @post Output==FALSE
 */
void test2_space_get_discovered();

#endif
