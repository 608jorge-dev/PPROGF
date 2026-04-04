/**
 * @brief It defines the tests for the character module
 *
 * @file character_test.h
 * @author Álvaro Bravo González
 * @version 1.0
 * @date 04-03-2025
 * @copyright GNU Public License
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "test.h"

/**
 * @test Test inventory creation
 * @post Non NULL pointer to inventory
 */
void test2_inventory_create();

/**
 * @test Test inventory creation
 * @post Space_ID == Supplied Space Id
 */
void test2_inventory_create();

/**
 * @test Test function for inventory_object adding
 * @pre Id of the object to add
 * @post Ouput==OK
 */
void test1_inventory_add_object();

/**
 * @test Test function for inventory_object adding
 * @pre Pointer to inventory = NULL
 * @post Ouput==ERROR
 */
void test2_inventory_add_object();

/**
 * @test Test function for inventory_object deleting
 * @pre Id of the object to delete
 * @post Ouput==OK
 */
void test1_inventory_del_object();

/**
 * @test Test function for inventory_object deleting
 * @pre Pointer to inventory = NULL
 * @post Ouput==ERROR
 */
void test2_inventory_del_object();

/**
 * @test Test function for inventory_object finding
 * @pre Id of the object to find
 * @post Ouput==TRUE
 */
void test1_inventory_find_object();

/**
 * @test Test function for inventory_object finding
 * @pre Pointer to inventory = NULL
 * @post Ouput==FALSE
 */
void test2_inventory_find_object();

/**
 * @test Test function for inventory_object finding
 * @pre Id of the object to find
 * @post Ouput==FALSE
 */
void test3_inventory_find_object();

/**
 * @test Test function for inventory_health setting
 * @pre Inventory health
 * @post Output==OK
 */
void test1_inventory_set_n_objects();

/**
 * @test Test function for inventory_health setting
 * @pre Pointer to inventory = NULL
 * @post Output==ERROR
 */
void test2_inventory_set_n_objects();

/**
 * @test Test function for inventory_health setting
 * @pre Inventory health
 * @post Output==ERROR
 */
void test3_inventory_set_n_objects();

/**
 * @test Test function for inventory_health getting
 * @pre Inventory health
 * @post Output==Supplied Inventory health
 */
void test1_inventory_get_n_objects();

/**
 * @test Test function for inventory_health getting
 * @pre Pointer to inventory = NULL
 * @post Output==-1
 */
void test2_inventory_get_n_objects();

#endif