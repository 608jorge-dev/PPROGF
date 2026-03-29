#include "link_test.h"





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
    PRINT_TEST_RESULT(character_get_id(l) == 5);
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

