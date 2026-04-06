/**
 * @brief It tests set module
 *
 * @file set_test.c
 * @author Álvaro Bravo González
 * @version 0.0
 * @date 02-03-2025
 * @copyright GNU Public License
 */

#include "set_test.h"

/**
 * @brief Main function for SET unit tests.
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
    printf("Running all test for module Set:\n");
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
    test1_set_create();
  if (all || test == 2)
    test2_set_create();
  if (all || test == 3)
    test1_set_add();
  if (all || test == 4)
    test2_set_add();
  if (all || test == 5)
    test1_set_del();
  if (all || test == 6)
    test2_set_del();
  if (all || test == 7)
    test1_set_find();
  if (all || test == 8)
    test2_set_find();
  if (all || test == 9)
    test3_set_find();

  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_set_create()
{
  int result;
  Set *s;
  s = set_create();
  result = s != NULL;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test2_set_create()
{
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_add(s, 4) == OK);
  set_destroy(s);
}

void test1_set_add()
{
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_add(s, 4) == OK);
  set_destroy(s);
}

void test2_set_add()
{
  Set *s = NULL;
  PRINT_TEST_RESULT(set_add(s, 4) == ERROR);
}

void test1_set_del()
{
  Set *s;
  s = set_create();
  set_add(s, 4);
  PRINT_TEST_RESULT(set_del(s, 4) == OK);
  set_destroy(s);
}

void test2_set_del()
{
  Set *s = NULL;
  PRINT_TEST_RESULT(set_del(s, 4) == ERROR);
}

void test1_set_find()
{
  Set *s;
  s = set_create();
  set_add(s, 4);
  PRINT_TEST_RESULT(set_find(s, 4) == TRUE);
  set_destroy(s);
}

void test2_set_find()
{
  Set *s = NULL;
  PRINT_TEST_RESULT(set_find(s, 4) == FALSE);
}

void test3_set_find()
{
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_find(s, 4) == FALSE);
  set_destroy(s);
}
