/**
 * @brief It tests object module
 *
 * @file object_test.c
 * @author Álvaro Bravo González
 * @version 1.0
 * @date 04-03-2025
 * @copyright GNU Public License
 */

#include "object_test.h"

/**
 * @brief Main function for OBJECT unit tests.
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
    printf("Running all test for module Object:\n");
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
    test1_object_create();
  if (all || test == 2)
    test2_object_create();
  if (all || test == 3)
    test1_object_set_id();
  if (all || test == 4)
    test2_object_set_id();
  if (all || test == 5)
    test1_object_get_id();
  if (all || test == 6)
    test2_object_get_id();
  if (all || test == 7)
    test1_object_set_name();
  if (all || test == 8)
    test2_object_set_name();
  if (all || test == 9)
    test3_object_set_name();
  if (all || test == 10)
    test1_object_get_name();
  if (all || test == 11)
    test2_object_get_name();
  if (all || test == 12)
    test1_object_set_desc();
  if (all || test == 13)
    test2_object_set_desc();
  if (all || test == 14)
    test3_object_set_desc();
  if (all || test == 15)
    test1_object_get_desc();
  if (all || test == 16)
    test2_object_get_desc();

  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_object_create()
{
  int result;
  Object *o;
  o = object_create(5);
  result = o != NULL;
  PRINT_TEST_RESULT(result);
  object_destroy(o);
}

void test2_object_create()
{
  Object *o;
  o = object_create(5);
  PRINT_TEST_RESULT(object_get_id(o) == 5);
  object_destroy(o);
}

void test1_object_set_id()
{
  Object *o;
  o = object_create(5);
  PRINT_TEST_RESULT(object_set_id(o, 10) == OK);
  object_destroy(o);
}

void test2_object_set_id()
{
  Object *o = NULL;
  PRINT_TEST_RESULT(object_set_id(o, 10) == ERROR);
}

void test1_object_get_id()
{
  Object *o;
  o = object_create(5);
  PRINT_TEST_RESULT(object_get_id(o) == 5);
  object_destroy(o);
}

void test2_object_get_id()
{
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_id(o) == NO_ID);
}

void test1_object_set_name()
{
  Object *o;
  o = object_create(5);
  PRINT_TEST_RESULT(object_set_name(o, "hola") == OK);
  object_destroy(o);
}

void test2_object_set_name()
{
  Object *o = NULL;
  PRINT_TEST_RESULT(object_set_name(o, "hola") == ERROR);
}

void test3_object_set_name()
{
  Object *o;
  o = object_create(5);
  PRINT_TEST_RESULT(object_set_name(o, NULL) == ERROR);
  object_destroy(o);
}

void test1_object_get_name()
{
  Object *o;
  o = object_create(5);
  object_set_name(o, "adios");
  PRINT_TEST_RESULT(strcmp(object_get_name(o), "adios") == 0);
  object_destroy(o);
}

void test2_object_get_name()
{
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_name(o) == NULL);
}

void test1_object_set_desc()
{
  Object *o;
  o = object_create(5);
  PRINT_TEST_RESULT(object_set_desc(o, "hola") == OK);
  object_destroy(o);
}

void test2_object_set_desc()
{
  Object *o = NULL;
  PRINT_TEST_RESULT(object_set_desc(o, "hola") == ERROR);
}

void test3_object_set_desc()
{
  Object *o;
  o = object_create(5);
  PRINT_TEST_RESULT(object_set_desc(o, NULL) == ERROR);
  object_destroy(o);
}

void test1_object_get_desc()
{
  Object *o;
  o = object_create(5);
  object_set_desc(o, "adios");
  PRINT_TEST_RESULT(strcmp(object_get_desc(o), "adios") == 0);
  object_destroy(o);
}

void test2_object_get_desc()
{
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_desc(o) == NULL);
}