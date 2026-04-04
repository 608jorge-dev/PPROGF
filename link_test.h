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

void test1_link_create();

void test2_link_create();

void test1_link_set_id();

void test2_link_set_id();

void test1_link_get_id();

void test2_link_get_id();

void test1_link_set_name();

void test2_link_set_name();

void test3_link_set_name();

void test1_link_get_name();

void test2_link_get_name();

void test1_link_set_origin();

void test2_link_set_origin();

void test1_link_get_origin();

void test2_link_get_origin();

void test1_link_set_destination();

void test2_link_set_destination();

void test1_link_get_destination();

void test2_link_get_destination();

void test1_link_set_open();

void test2_link_set_open();

void test1_link_get_open();

void test2_link_get_open();

#endif