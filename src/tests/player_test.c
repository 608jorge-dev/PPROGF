/**
* @brief It tests player module
 *
 * @file player_test.c
 * @author Álvaro Bravo González
 * @version 1.0
 * @date 04-03-2025
 * @copyright GNU Public License
 */

#include "player_test.h"

/**
 * @brief Main function for PLAYER unit tests.
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
    printf("Running all test for module Player:\n");
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
    test1_player_create();
  if (all || test == 2)
    test2_player_create();
  if (all || test == 3)
    test1_player_set_id();
  if (all || test == 4)
    test2_player_set_id();
  if (all || test == 5)
    test1_player_get_id();
  if (all || test == 6)
    test2_player_get_id();
  if (all || test == 7)
    test1_player_set_name();
  if (all || test == 8)
    test2_player_set_name();
  if (all || test == 9)
    test3_player_set_name();
  if (all || test == 10)
    test1_player_get_name();
  if (all || test == 11)
    test2_player_get_name();
  if (all || test == 12)
    test1_player_set_gdesc();
  if (all || test == 13)
    test2_player_set_gdesc();
  if (all || test == 14)
    test3_player_set_gdesc();
  if (all || test == 15)
    test1_player_get_gdesc();
  if (all || test == 16)
    test2_player_get_gdesc();
  if (all || test == 17)
    test1_player_add_object();
  if (all || test == 18)
    test2_player_add_object();
  if (all || test == 19)
    test1_player_del_object();
  if (all || test == 20)
    test2_player_del_object();
  if (all || test == 21)
    test1_player_find_object();
  if (all || test == 22)
    test2_player_find_object();
  if (all || test == 23)
    test3_player_find_object();
  if (all || test == 24)
    test1_player_set_location();
  if (all || test == 25)
    test2_player_set_location();
  if (all || test == 26)
    test1_player_get_location();
  if (all || test == 27)
    test2_player_get_location();
  if (all || test == 28)
    test1_player_set_health();
  if (all || test == 29)
    test2_player_set_health();
  if (all || test == 30)
    test1_player_get_health();
  if (all || test == 31)
    test2_player_get_health();

  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_player_create()
{
  int result;
  Player *p;
  p = player_create(5);
  result = p != NULL;
  PRINT_TEST_RESULT(result);
  player_destroy(p);
}

void test2_player_create()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_get_id(p) == 5);
  player_destroy(p);
}

void test1_player_set_id()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_set_id(p, 10) == OK);
  player_destroy(p);
}

void test2_player_set_id()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_set_id(p, 10) == ERROR);
}

void test1_player_get_id()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_get_id(p) == 5);
  player_destroy(p);
}

void test2_player_get_id()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_id(p) == NO_ID);
}

void test1_player_set_name()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_set_name(p, "hola") == OK);
  player_destroy(p);
}

void test2_player_set_name()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_set_name(p, "hola") == ERROR);
}

void test3_player_set_name()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_set_name(p, NULL) == ERROR);
  player_destroy(p);
}

void test1_player_get_name()
{
  Player *p;
  p = player_create(5);
  player_set_name(p, "adios");
  PRINT_TEST_RESULT(strcmp(player_get_name(p), "adios") == 0);
  player_destroy(p);
}

void test2_player_get_name()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_name(p) == NULL);
}

void test1_player_set_gdesc()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_set_gdesc(p, "hola") == OK);
  player_destroy(p);
}

void test2_player_set_gdesc()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_set_gdesc(p, "hola") == ERROR);
}

void test3_player_set_gdesc()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_set_gdesc(p, NULL) == ERROR);
  player_destroy(p);
}

void test1_player_get_gdesc()
{
  Player *p;
  p = player_create(5);
  player_set_gdesc(p, "adios");
  PRINT_TEST_RESULT(strcmp(player_get_gdesc(p), "adios") == 0);
  player_destroy(p);
}

void test2_player_get_gdesc()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_gdesc(p) == NULL);
}

void test1_player_add_object()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_add_object(p, 6) == OK);
  player_destroy(p);
}

void test2_player_add_object()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_add_object(p, 6) == ERROR);
}

void test1_player_del_object()
{
  Player *p;
  p = player_create(5);
  player_add_object(p, 6);
  PRINT_TEST_RESULT(player_del_object(p, 6) == OK);
  player_destroy(p);
}

void test2_player_del_object()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_del_object(p, 6) == ERROR);
}

void test1_player_find_object()
{
  Player *p;
  p = player_create(5);
  player_add_object(p, 6);
  PRINT_TEST_RESULT(player_find_object(p, 6) == TRUE);
  player_destroy(p);
}

void test2_player_find_object()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_find_object(p, 6) == FALSE);
}

void test3_player_find_object()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_find_object(p, 6) == FALSE);
  player_destroy(p);
}

void test1_player_set_location()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_set_location(p, 11) == OK);
  player_destroy(p);
}

void test2_player_set_location()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_set_location(p, 11) == ERROR);
}

void test1_player_get_location()
{
  Player *p;
  p = player_create(5);
  player_set_location(p, 11);
  PRINT_TEST_RESULT(player_get_location(p) == 11);
  player_destroy(p);
}

void test2_player_get_location()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_location(p) == NO_ID);
}

void test1_player_set_health()
{
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_set_health(p, 50) == OK);
  player_destroy(p);
}

void test2_player_set_health()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_set_health(p, 50) == ERROR);
}

void test1_player_get_health()
{
  Player *p;
  p = player_create(5);
  player_set_health(p, 50);
  PRINT_TEST_RESULT(player_get_health(p) == 50);
  player_destroy(p);
}

void test2_player_get_health()
{
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_health(p) == NO_ID);
}