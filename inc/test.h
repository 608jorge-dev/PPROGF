/**
 * @brief It defines the print_test module interface
 *
 * @file test.h
 * @author Profesores PPROG
 * @version 0
 * @date 28-04-2026
 * @copyright GNU Public License
 */
#ifndef _TEST_H
#define _TEST_H

#pragma GCC diagnostic ignored "-Wpedantic"

#ifndef NOCOLOR         /*!< No color */
#define KRED "\x1B[31m" /*!< Red color */
#define KGRN "\x1B[32m" /*!< Green color */
#define KYEL "\x1B[33m" /*!< Yellow color */
#define KCYN "\x1B[36m" /*!< Cyan color */
#define RESET "\033[0m" /*!< Reset color */

#define MAX_TESTS 50 /*!< Max amount of test possible */
#else
#define KRED  /*!< Red color */
#define KGRN  /*!< Green color*/
#define KYEL  /*!< Yellow color */
#define KCYN  /*!< Cyan color */
#define RESET /*!< Reset color */
#endif

#define PRINT_TEST_RESULT(x)                                         \
  do                                                                 \
  {                                                                  \
    __test_counter++;                                                \
    __pass = (x);                                                    \
    __test_passed = (__pass) ? __test_passed + 1 : __test_passed;    \
    printf(KYEL "%s" RESET " line "                                  \
                "%d " KCYN "%s" RESET ": %s\n",                      \
           __FILE__, __LINE__, __FUNCTION__,                         \
           ((!__pass) ? KRED "NOT PASS" RESET : KGRN "PASS" RESET)); \
  } while (0) /*!< Prints the result of a test */

#define PRINT_PASSED_PERCENTAGE printf("Tests passed %d%%\n", ((__test_passed * 100) / __test_counter)) /*!< Print the percentage of tests that passed */

static int __test_counter = 0;
static int __test_passed = 0;
static int __pass = 0;

#endif
