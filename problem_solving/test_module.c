#include <stdio.h>          /* printf */
#include <string.h>         /* strcmp */

#include "test_module.h"

void PrintInGreen(){
	printf("\033[0;32m");
}

void PrintInRed(){
	printf("\033[0;31m");
}

void ResetColor(){
	printf("\033[0m");
}

void PrintInBlue(const char *str){
	printf("\033[1;34m%s\033[0m",str);
}

void PrintInYellow(const char *str){
	printf("\033[01;33m%s\033[0m",str);
}


/****************   Macros ans static global variable    *******************/
static size_t failures = 0;
static size_t tests = 0;

/****************   Help function    *******************/

void PrintTestsStas()
{
	printf("\n%ld ERRORS FROM %ld TESTS\n", failures, tests);
}


/****************   Test functions    *******************/

void CheckEquality(size_t ans, size_t expected_ans, print_mode_t print_mode)
{
    tests++;
    if (ans != expected_ans)
    {
        PrintInRed();
		printf("Failed\n");
		ResetColor();
		failures++;

        if (print_mode == PRINT)
        {
            printf("ans= %ld, expected= %ld\n", ans, expected_ans);
        }
    }
    else
    {
        PrintInGreen();
		printf("Pass\n");
		ResetColor();
    }
}

void CheckIntEquality(int ans, int expected_ans, print_mode_t print_mode)
{
    tests++;
    if (ans != expected_ans)
    {
        PrintInRed();
		printf("Failed\n");
		ResetColor();
		failures++;

        if (print_mode == PRINT)
        {
            printf("ans= %d, expected= %d\n", ans, expected_ans);
        }
    }
    else
    {
        PrintInGreen();
		printf("Pass\n");
		ResetColor();
    }
}

void CheckSizeTEquality(size_t ans, size_t expected_ans, print_mode_t print_mode)
{
    tests++;
    if (ans != expected_ans)
    {
        PrintInRed();
		printf("Failed\n");
		ResetColor();
		failures++;

        if (print_mode == PRINT)
        {
            printf("ans= %ld, expected= %ld\n", ans, expected_ans);
        }
    }
    else
    {
        PrintInGreen();
		printf("Pass\n");
		ResetColor();
    }
}

static void PrintAnsAndExpectedArr(int arr_ans[], int expected_arr[], size_t size)
{
    size_t i = 0;

    for ( ; i < size; i++)
    {
        printf("got= %d, expected= %d\n", arr_ans[i], expected_arr[i]);
    }
    
    printf("\n");
}

void CheckArrEquality(int arr_ans[], int expected_arr[], size_t size, print_mode_t print_mode)
{
    size_t i = 0;
    
    tests++;
    for ( ; i < size; i++)
    {
        if (arr_ans[i] != expected_arr[i])
        {
            PrintInRed();
            printf("Failed \n");
            ResetColor();       
            failures++;

            if (print_mode == PRINT)
            {
                PrintAnsAndExpectedArr(arr_ans, expected_arr, size);
            }

            return;
        }
    }

    PrintInGreen();
    printf("Pass\n");
    ResetColor();
}

void CheckStrEquality(char *str_ans, char *str_expected, print_mode_t print_mode)
{
    tests++;
    if (strcmp(str_ans, str_expected) != 0)
    {
        PrintInRed();
		printf("Failed\n");
		ResetColor();
		failures++;

        if (print_mode == PRINT)
        {
            printf("ans= %s, expected= %s\n", str_ans, str_expected);
        }
    }
    else
    {
        PrintInGreen();
		printf("Pass\n");
		ResetColor();
    }
}