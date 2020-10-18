#include <assert.h>     /* assert */
#include <string.h>     /* memcpy */
#include <stdlib.h>     /* malloc free qsort */
#include <stdio.h>      /* printf */
#include "test_module.h"

static void Swap(int *ptr1, int *ptr2);
static void TestSortArr012(int *arr, size_t size);
static int CmpFunc(const void * a, const void * b);
static void Tests();

/*
    Given an array A[] consisting 0s, 1s and 2s.
    The function sorts the given array.
*/

void SortArr012(int *arr, size_t size)
{
    int *runner = arr;
    int *ptr_end_1 = arr + size - 1;
    int *ptr_start_1 = NULL;

    assert(arr);

    while (runner < ptr_end_1)
    {
        if (*runner & 2)
        {
            Swap(runner, ptr_end_1--);
            continue;
        }

        if (*runner & 1)
        {
            break;
        }

        runner++;
    }

    ptr_start_1 = runner;

    while (runner <= ptr_end_1)
    {
        if (*runner & 2)
        {
            Swap(runner, ptr_end_1);
            ptr_end_1--;
            continue;
        }

        if (!*runner)
        {
            Swap(runner, ptr_start_1);
            ptr_start_1++;
        }

        runner++;
    }
}



int main()
{
    Tests();
    PrintTestsStas();

    return 0;
}


/****************** Static functions implementation *****************/
static void Tests()
{
    int arr1[] = {0,2,1,2,0,0,1,2,1,0};
    int arr2[] = {1,2,0,0,1};
    int arr3[] = {2};
    int arr4[] = {1,2,1,2,2,1};
    int arr5[] = {2,0,0,2,0,2};
    int arr6[] = {1,1,1,0,1,0,0,1};

    TestSortArr012(arr1, SizeOfArr(arr1));
    TestSortArr012(arr2, SizeOfArr(arr2));
    TestSortArr012(arr3, SizeOfArr(arr3));
    TestSortArr012(arr4, SizeOfArr(arr4));
    TestSortArr012(arr5, SizeOfArr(arr5));
    TestSortArr012(arr6, SizeOfArr(arr6));
}

static void TestSortArr012(int *arr, size_t size)
{
    int *arr_dup = malloc(sizeof(int) * size);

    if (!arr_dup)
    {
        printf("malloc failed\n");
    }
    
    memcpy(arr_dup, arr, size * sizeof(int));
    qsort(arr_dup, size, sizeof(int), CmpFunc);
    SortArr012(arr, size);

    CheckArrEquality(arr, arr_dup, size, PRINT);
    free(arr_dup);
    arr_dup = NULL;
}

static int CmpFunc(const void *num1, const void *num2)
{
   return (*(int *)num1 - *(int *)num2);
}

static void Swap(int *ptr1, int *ptr2)
{
    if (ptr1 != ptr2)
    {
        *ptr1 ^= *ptr2;
        *ptr2 ^= *ptr1;
        *ptr1 ^= *ptr2;
    }
}