/**
* @brief It tests character module
 *
 * @file character_test.c
 * @author Álvaro Bravo González
 * @version 1.0
 * @date 04-03-2025
 * @copyright GNU Public License
 */

#include "character_test.h"

/**
 * @brief Main function for CHARACTER unit tests.
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
    printf("Running all test for module Character:\n");
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
    test1_character_create();
  if (all || test == 2)
    test2_character_create();
  if (all || test == 3)
    test1_character_set_id();
  if (all || test == 4)
    test2_character_set_id();
  if (all || test == 5)
    test1_character_get_id();
  if (all || test == 6)
    test2_character_get_id();
  if (all || test == 7)
    test1_character_set_name();
  if (all || test == 8)
    test2_character_set_name();
  if (all || test == 9)
    test3_character_set_name();
  if (all || test == 10)
    test1_character_get_name();
  if (all || test == 11)
    test2_character_get_name();
  if (all || test == 12)
    test1_character_set_gdesc();
  if (all || test == 13)
    test2_character_set_gdesc();
  if (all || test == 14)
    test3_character_set_gdesc();
  if (all || test == 15)
    test1_character_get_gdesc();
  if (all || test == 16)
    test2_character_get_gdesc();
  if (all || test == 17)
    test1_character_set_health();
  if (all || test == 18)
    test2_character_set_health();
  if (all || test == 19)
    test1_character_get_health();
  if (all || test == 20)
    test2_character_get_health();
  if (all || test == 21)
    test1_character_set_friendly();
  if (all || test == 22)
    test2_character_set_friendly();
  if (all || test == 23)
    test1_character_get_friendly();
  if (all || test == 24)
    test2_character_get_friendly();
  if (all || test == 25)
    test1_character_set_message();
  if (all || test == 26)
    test2_character_set_message();
  if (all || test == 27)
    test3_character_set_message();
  if (all || test == 28)
    test1_character_get_message();
  if (all || test == 29)
    test2_character_get_message();

  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_character_create()
{
  int result;
  Character *c;
  c = character_create(5);
  result = c != NULL;
  PRINT_TEST_RESULT(result);
  character_destroy(c);
}

void test2_character_create()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_get_id(c) == 5);
  character_destroy(c);
}

void test1_character_set_id()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_set_id(c, 10) == OK);
  character_destroy(c);
}

void test2_character_set_id()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_set_id(c, 10) == ERROR);
}

void test1_character_get_id()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_get_id(c) == 5);
  character_destroy(c);
}

void test2_character_get_id()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_get_id(c) == NO_ID);
}

void test1_character_set_name()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_set_name(c, "hola") == OK);
  character_destroy(c);
}

void test2_character_set_name()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_set_name(c, "hola") == ERROR);
}

void test3_character_set_name()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_set_name(c, NULL) == ERROR);
  character_destroy(c);
}

void test1_character_get_name()
{
  Character *c;
  c = character_create(5);
  character_set_name(c, "adios");
  PRINT_TEST_RESULT(strcmp(character_get_name(c), "adios") == 0);
  character_destroy(c);
}

void test2_character_get_name()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_get_name(c) == NULL);
}

void test1_character_set_gdesc()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_set_gdesc(c, "hola") == OK);
  character_destroy(c);
}

void test2_character_set_gdesc()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_set_gdesc(c, "hola") == ERROR);
}

void test3_character_set_gdesc()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_set_gdesc(c, NULL) == ERROR);
  character_destroy(c);
}

void test1_character_get_gdesc()
{
  Character *c;
  c = character_create(5);
  character_set_gdesc(c, "adios");
  PRINT_TEST_RESULT(strcmp(character_get_gdesc(c), "adios") == 0);
  character_destroy(c);
}

void test2_character_get_gdesc()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_get_gdesc(c) == NULL);
}

void test1_character_set_health()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_set_health(c, 50) == OK);
  character_destroy(c);
}

void test2_character_set_health()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_set_health(c, 50) == ERROR);
}

void test1_character_get_health()
{
  Character *c;
  c = character_create(5);
  character_set_health(c, 50);
  PRINT_TEST_RESULT(character_get_health(c) == 50);
  character_destroy(c);
}

void test2_character_get_health()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_get_health(c) == NO_ID);
}

void test1_character_set_friendly()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_set_friendly(c, TRUE) == OK);
  character_destroy(c);
}

void test2_character_set_friendly()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_set_friendly(c, TRUE) == ERROR);
}

void test1_character_get_friendly()
{
  Character *c;
  c = character_create(5);
  character_set_friendly(c, TRUE);
  PRINT_TEST_RESULT(character_get_friendly(c) == TRUE);
  character_destroy(c);
}

void test2_character_get_friendly()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_get_friendly(c) == FALSE);
}

void test1_character_set_message()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_set_message(c, "hola") == OK);
  character_destroy(c);
}

void test2_character_set_message()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_set_message(c, "hola") == ERROR);
}

void test3_character_set_message()
{
  Character *c;
  c = character_create(5);
  PRINT_TEST_RESULT(character_set_message(c, NULL) == ERROR);
  character_destroy(c);
}

void test1_character_get_message()
{
  Character *c;
  c = character_create(5);
  character_set_message(c, "adios");
  PRINT_TEST_RESULT(strcmp(character_get_message(c), "adios") == 0);
  character_destroy(c);
}

void test2_character_get_message()
{
  Character *c = NULL;
  PRINT_TEST_RESULT(character_get_message(c) == NULL);
}