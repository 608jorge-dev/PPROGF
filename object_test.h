/**
 * @brief It defines the tests for the object module
 *
 * @file object_test.h
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
#include "object.h"
#include "test.h"

/**
 * @test Test object creation
 * @pre Object ID
 * @post Non NULL pointer to object
 */
void test1_object_create();

/**
 * @test Test object creation
 * @pre Object ID
 * @post Object_ID == Supplied Object Id
 */
void test2_object_create();

/**
 * @test Test function for object_id setting
 * @pre Object ID
 * @post Output==OK
 */
void test1_object_set_id();

/**
 * @test Test function for object_id setting
 * @pre Pointer to object = NULL
 * @post Output==ERROR
 */
void test2_object_set_id();

/**
 * @test Test function for object_id getting
 * @pre Object ID
 * @post Output==Supplied Object Id
 */
void test1_object_get_id();

/**
 * @test Test function for object_id getting
 * @pre Pointer to object = NULL
 * @post Output==NO_ID
 */
void test2_object_get_id();

/**
 * @test Test function for object_name setting
 * @pre String with object name
 * @post Ouput==OK
 */
void test1_object_set_name();

/**
 * @test Test function for object_name setting
 * @pre Pointer to object = NULL
 * @post Output==ERROR
 */
void test2_object_set_name();

/**
 * @test Test function for object_name setting
 * @pre Pointer to object_name = NULL
 * @post Output==ERROR
 */
void test3_object_set_name();

/**
 * @test Test function for object_name getting
 * @pre Name of the object
 * @post Ouput==TRUE
 */
void test1_object_get_name();

/**
 * @test Test function for object_name getting
 * @pre Pointer to object = NULL
 * @post Ouput==NULL
 */
void test2_object_get_name();

/**
 * @test Test function for space_desc setting
 * @pre String with object description
 * @post Ouput==OK
 */
void test1_object_set_desc();

/**
 * @test Test function for object_gdesc setting
 * @pre Pointer to object = NULL
 * @post Output==ERROR
 */
void test2_object_set_desc();

/**
 * @test Test function for object_desc setting
 * @pre Pointer to object_desc = NULL
 * @post Output==ERROR
 */
void test3_object_set_desc();

/**
 * @test Test function for object_desc getting
 * @pre Description of the object
 * @post Ouput==TRUE
 */
void test1_object_get_desc();

/**
 * @test Test function for object_desc getting
 * @pre Pointer to object = NULL
 * @post Ouput==NULL
 */
void test2_object_get_desc();

#endif