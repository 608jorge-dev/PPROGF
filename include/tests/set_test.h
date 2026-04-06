/**
 * @brief It declares the tests for the set module
 *
 * @file set_test.h
 * @author Álvaro Bravo González
 * @version 0.0
 * @date 02-03-2025
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "test.h"

/**
 * @test Test set creation
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test set creation
 * @post Space_ID == Supplied Space Id
 */
void test2_set_create();

/**
 * @test Test set adding
 * @post Output == OK
 */
void test1_set_add();

/**
 * @test Test set adding
 * @pre Pointer to set = NULL
 * @post Output == ERROR
 */
void test2_set_add();

/**
 * @test Test set deleting
 * @post Output == OK
 */
void test1_set_del();

/**
 * @test Test set deleting
 * @pre Pointer to set = NULL
 * @post Output == ERROR
 */
void test2_set_del();

/**
 * @test Test set finding
 * @post Output == OK
 */
void test1_set_find();

/**
 * @test Test set finding
 * @pre Pointer to set = NULL
 * @post Output == ERROR
 */
void test2_set_find();

/**
 * @test Test set finding
 * @post Output == ERROR
 */
void test3_set_find();

#endif
