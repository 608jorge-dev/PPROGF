/**
 * @brief It tests inventory module
 *
 * @file inventory_test.c
 * @author Álvaro Bravo González
 * @version 1.0
 * @date 04-03-2025
 * @copyright GNU Public License
 */

#include "inventory_test.h"

/**
 * @brief Main function for INVENTORY unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */

int main(int argc, char **argv)
{
  int test = 0;
  int all = 1;

  if (argc < 2)
  {
    printf("Running all test for module Inventory:\n");
  }
  else
  {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS)
    {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1)
    test1_inventory_create();
  if (all || test == 2)
    test2_inventory_create();
  if (all || test == 3)
    test1_inventory_add_object();
  if (all || test == 4)
    test2_inventory_add_object();
  if (all || test == 5)
    test1_inventory_del_object();
  if (all || test == 6)
    test2_inventory_del_object();
  if (all || test == 7)
    test1_inventory_find_object();
  if (all || test == 8)
    test2_inventory_find_object();
  if (all || test == 9)
    test3_inventory_find_object();
  if (all || test == 10)
    test1_inventory_set_n_objects();
  if (all || test == 11)
    test2_inventory_set_n_objects();
  if (all || test == 12)
    test3_inventory_set_n_objects();
  if (all || test == 13)
    test1_inventory_get_n_objects();
  if (all || test == 14)
    test2_inventory_get_n_objects();
  
  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_inventory_create()
{
  int result;
  Inventory *i;
  i = inventory_create();
  result = i != NULL;
  PRINT_TEST_RESULT(result);
  inventory_destroy(i);
}

void test1_inventory_create()
{
  Inventory *i;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_add_object(i, 4) == OK);
  inventory_destroy(i);
}

void test1_inventory_add_object()
{
  Inventory *i;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_add_object(i, 4) == OK);
  inventory_destroy(i);
}

void test2_inventory_add_object()
{
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_add_object(i, 4) == ERROR);
}

void test1_inventory_del_object()
{
  Inventory *i;
  i = inventory_create();
  inventory_add_object(i, 4);
  PRINT_TEST_RESULT(inventory_del_object(i, 4) == OK);
  inventory_destroy(i);
}

void test2_inventory_del_object()
{
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_del_object(i, 4) == ERROR);
}

void test1_inventory_find_object()
{
  Inventory *i;
  i = inventory_create();
  inventory_add_object(i, 4);
  PRINT_TEST_RESULT(inventory_find_object(i, 4) == 0);
  inventory_destroy(i);
}

void test2_inventory_find_object()
{
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_find_object(i, 4) == -1);
}

void test3_inventory_find_object()
{
  Inventory *i;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_find_object(i, 4) == -1);
  inventory_destroy(i);
}

void test1_inventory_set_n_objects()
{
  Inventory *i;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_set_n_objs(i, 4) == OK);
  inventory_destroy(i);
}

void test2_inventory_set_n_objects()
{
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_set_n_objs(i, 4) == ERROR);
}

void test3_inventory_set_n_objects()
{

  Inventory *i;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_set_n_objs(i, -1) == ERROR);
  inventory_destroy(i);
}

void test1_inventory_get_n_objects()
{
  Inventory *i;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_get_n_objs(i) == 5);
  inventory_destroy(i);
}

void test2_inventory_get_n_objects()
{
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_get_n_objs(i) == -1);
}