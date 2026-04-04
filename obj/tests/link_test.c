#include "link_test.h"

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
    test1_link_create();
  if (all || test == 2)
    test2_link_create();
  if (all || test == 3)
    test1_link_set_id();
  if (all || test == 4)
    test2_link_set_id();
  if (all || test == 5)
    test1_link_get_id();
  if (all || test == 6)
    test2_link_get_id();
  if (all || test == 7)
    test1_link_set_name();
  if (all || test == 8)
    test2_link_set_name();
  if (all || test == 9)
    test3_link_set_name();
  if (all || test == 10)
    test1_link_get_name();
  if (all || test == 11)
    test2_link_get_name();
  if (all || test == 12)
    test1_link_set_origin();
  if (all || test == 13)
    test2_link_set_origin();
  if (all || test == 14)
    test1_link_get_origin();
  if (all || test == 15)
    test2_link_get_origin();
  if (all || test == 16)
    test1_link_set_destination();
  if (all || test == 17)
    test2_link_set_destination();
  if (all || test == 18)
    test1_link_get_destination();
  if (all || test == 19)
    test2_link_get_destination(); 
  if (all || test == 20)
    test1_link_set_open();
  if (all || test == 21)
    test2_link_set_open(); 
  if (all || test == 22)
    test1_link_get_open();  
  if (all || test == 23)
    test2_link_get_open();  
  PRINT_PASSED_PERCENTAGE;

  return 0;
}



void test1_link_create(){

int result;
Link * l;
l = link_create(5);
result = l != NULL;
PRINT_TEST_RESULT(result);
link_destroy(l);

}

void test2_link_create(){
    Link * l;
    l = link_create(5);
    PRINT_TEST_RESULT(link_get_id(l) == 5);
    link_destroy(l);
}

void test1_link_set_id()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_id(l, 10) == OK);
  link_destroy(l);
}

void test2_link_set_id()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_id(l, 10) == ERROR);
}

void test1_link_get_id(){

  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_get_id(l) == 5);
  link_destroy(l);
}

void test2_link_get_id()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_id(l) == NO_ID);
}

void test1_link_set_name()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_name(l, "hola") == OK);
  link_destroy(l);
}

void test2_link_set_name(){
 Link *l = NULL;
 PRINT_TEST_RESULT(link_set_name(l, "hola") == ERROR);
}

void test3_link_set_name(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_name(l, NULL) == ERROR);
  link_destroy(c);
}

void test1_link_get_name(){
  Link *l;
  l = link_create(5);
  link_set_name(l, "adios");
  PRINT_TEST_RESULT(strcmp(link_get_name(l), "adios") == 0);
  link_destroy(l);
}

void test2_link_get_name()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_name(l) == NULL);
}

void test1_link_set_origin(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_origin(l, 5) == OK);
  link_destroy(l);
}

void test2_link_set_origin(){

  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_origin(l, 5) == ERROR);
}

void test1_link_get_origin(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_get_origin(l) == 5);
  link_destroy(l);
}

void test2_link_get_origin(){

  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_origin(l) == NO_ID);

}

void test1_link_set_destination(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_destination(l, 5) == OK);
  link_destroy(l);

}

void test2_link_set_destination(){

 Link *l = NULL;
 PRINT_TEST_RESULT(link_set_destination(l, 5) == ERROR);


}

void test1_link_get_destination(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_get_destination(l) == 5);
  link_destroy(l);
}

void test2_link_get_destination(){

  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_destination(l) == NO_ID);

}

void test1_link_set_open()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_open(l, TRUE) == OK);
  link_destroy(s);
}

void test2_link_set_open()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_open(l, TRUE) == ERROR);
}

void test1_link_get_open()
{
  Link *l;
  l = link_create(5);
  link_set_open(l, TRUE);
  PRINT_TEST_RESULT(link_get_open(l) == TRUE);
  link_destroy(l);
}

void test2_link_get_open()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_open(l) == FALSE);
}
