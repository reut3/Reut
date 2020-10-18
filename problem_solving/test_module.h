#ifndef _TEST_MODULE_H_
#define _TEST_MODULE_H_

#include <stddef.h>     /* size_t */

#define SizeOfArr(arr) (sizeof(arr)/sizeof(arr[0]))
typedef enum {UNPRINT, PRINT} print_mode_t;

void CheckEquality(size_t ans, size_t expected_ans, print_mode_t);

void CheckArrEquality(int arr_ans[], int expected_arr[], size_t size, print_mode_t);

void CheckIntEquality(int ans, int expected_ans, print_mode_t print_mode);

void CheckStrEquality(char *str_ans, char *str_expected, print_mode_t print_mode);

void PrintTestsStas();

void PrintInYellow(const char *str);

#endif