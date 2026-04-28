/**
 * @brief It defines the tests for the link module
 *
 * @file link_test.h
 * @author Álvaro Bravo González
 * @version 1.0
 * @date 04-03-2025
 * @copyright GNU Public License
 */
#ifndef LINK_TEST_H
#define LINK_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#include "test.h"

/**
 * @test Test link creation
 * @post Non NULL pointer to link
 */
void test1_link_create();

/**
 * @test Test link creation
 * @pre Link ID
 * @post Link_ID == Supplied link Id
 */
void test2_link_create();

/**
 * @test Test function for link_id setting
 * @pre Link ID
 * @post Output==OK
 */
void test1_link_set_id();

/**
 * @test Test function for link_id setting
 * @pre Pointer to link = NULL
 * @post Output==ERROR
 */
void test2_link_set_id();

/**
 * @test Test function for link_id getting
 * @pre Link ID
 * @post Output==Supplied Link Id
 */
void test1_link_get_id();

/**
 * @test Test function for link_id getting
 * @pre Pointer to link = NULL
 * @post Output==NO_ID
 */
void test2_link_get_id();

/**
 * @test Test function for link_name setting
 * @pre String with link name
 * @post Ouput==OK
 */
void test1_link_set_name();

/**
 * @test Test function for link_name setting
 * @pre Pointer to link = NULL
 * @post Output==ERROR
 */
void test2_link_set_name();

/**
 * @test Test function for link_name setting
 * @pre Pointer to link_name = NULL
 * @post Output==ERROR
 */
void test3_link_set_name();

/**
 * @test Test function for link_name getting
 * @pre Name of the link
 * @post Ouput==TRUE
 */
void test1_link_get_name();

/**
 * @test Test function for link_name getting
 * @pre Pointer to link = NULL
 * @post Ouput==NULL
 */
void test2_link_get_name();

/**
 * @test Test function for link_origin setting
 * @pre Link origin
 * @post Output==OK
 */
void test1_link_set_origin();
/**
 * @test Test function for link_origin setting
 * @pre Pointer to link = NULL
 * @post Output==ERROR
 */
void test2_link_set_origin();

/**
 * @test Test function for link_origin getting
 * @pre Link origin
 * @post Output==Supplied Link origin
 */
void test1_link_get_origin();

/**
 * @test Test function for link_origin getting
 * @pre Pointer to link = NULL
 * @post Output==NO_ID
 */
void test2_link_get_origin();

/**
 * @test Test function for link_destination setting
 * @pre Link destination
 * @post Output==OK
 */
void test1_link_set_destination();

/**
 * @test Test function for link_destination setting
 * @pre Pointer to link = NULL
 * @post Output==ERROR
 */
void test2_link_set_destination();

/**
 * @test Test function for link_destination getting
 * @pre Link destination
 * @post Output==Supplied Link destination
 */
void test1_link_get_destination();

/**
 * @test Test function for link_destination getting
 * @pre Pointer to link = NULL
 * @post Output==NO_ID
 */
void test2_link_get_destination();

/**
 * @test Test function for link_open setting
 * @pre Link open
 * @post Output==OK
 */
void test1_link_set_open();

/**
 * @test Test function for link_open setting
 * @pre Pointer to link = NULL
 * @post Output==ERROR
 */
void test2_link_set_open();

/**
 * @test Test function for link_open getting
 * @pre Link open
 * @post Output==Supplied Link open
 */
void test1_link_get_open();

/**
 * @test Test function for link_open getting
 * @pre Pointer to link = NULL
 * @post Output==NO_ID
 */
void test2_link_get_open();

#endif