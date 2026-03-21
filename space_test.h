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
 * @test Test function for space_object getting
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
 * @test Test function for space_north setting
 * @pre Space ID of the space located at the north
 * @post Ouput==OK
 */
void test1_space_set_north();

/**
 * @test Test function for space_north setting
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test2_space_set_north();

/**
 * @test Test function for space_north setting
 * @pre Space ID of the space located at the north
 * @post Ouput==ERROR
 */
void test3_space_set_north();

/**
 * @test Test function for space_north setting
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test4_space_set_north();

/**
 * @test Test function for space_north getting
 * @pre Id of the space located at the north
 * @post Ouput==North space Id
 */
void test1_space_get_north();

/**
 * @test Test function for space_north getting
 * @pre Pointer to space = NULL
 * @post Ouput==NO_ID
 */
void test2_space_get_north();

/**
 * @test Test function for space_south setting
 * @pre Space ID of the space located at the south
 * @post Ouput==OK
 */
void test1_space_set_south();

/**
 * @test Test function for space_south setting
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test2_space_set_south();

/**
 * @test Test function for space_south setting
 * @pre Space ID of the space located at the south
 * @post Ouput==ERROR
 */
void test3_space_set_south();

/**
 * @test Test function for space_south setting
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test4_space_set_south();

/**
 * @test Test function for space_south getting
 * @pre Id of the space located at the south
 * @post Ouput==South space Id
 */
void test1_space_get_south();

/**
 * @test Test function for space_south getting
 * @pre Pointer to space = NULL
 * @post Ouput==NO_ID
 */
void test2_space_get_south();

/**
 * @test Test function for space_east setting
 * @pre Space ID of the space located at the east
 * @post Ouput==OK
 */
void test1_space_set_east();

/**
 * @test Test function for space_east setting
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test2_space_set_east();

/**
 * @test Test function for space_east setting
 * @pre Space ID of the space located at the east
 * @post Ouput==ERROR
 */
void test3_space_set_east();

/**
 * @test Test function for space_east setting
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test4_space_set_east();

/**
 * @test Test function for space_east getting
 * @pre Id of the space located at the east
 * @post Ouput==East space Id
 */
void test1_space_get_east();

/**
 * @test Test function for space_east getting
 * @pre Pointer to space = NULL
 * @post Ouput==NO_ID
 */
void test2_space_get_east();

/**
 * @test Test function for space_west setting
 * @pre Space ID of the space located at the west
 * @post Ouput==OK
 */
void test1_space_set_west();

/**
 * @test Test function for space_west setting
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test2_space_set_west();

/**
 * @test Test function for space_west setting
 * @pre Space ID of the space located at the west
 * @post Ouput==ERROR
 */
void test3_space_set_west();

/**
 * @test Test function for space_west setting
 * @pre Pointer to space = NULL
 * @post Ouput==ERROR
 */
void test4_space_set_west();

/**
 * @test Test function for space_west getting
 * @pre Id of the space located at the west
 * @post Ouput==West space Id
 */
void test1_space_get_west();

/**
 * @test Test function for space_west getting
 * @pre Pointer to space = NULL
 * @post Ouput==NO_ID
 */
void test2_space_get_west();

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

#endif
