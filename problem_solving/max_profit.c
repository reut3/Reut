#include <assert.h>         /* assert */
#include "test_module.h"

static void Tests();


size_t FindMaxProfit(const int *arr, size_t size)
{
    size_t profit = 0;
    size_t i = 0;

    assert(arr);

    for (i = 0; i < size - 1; i++)
    {
        if (arr[i + 1] > arr [i])
        {
            profit += (size_t)arr[i + 1] - (size_t)arr[i];
        }
    }

    return profit;
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
    int arr1[] = {100, 180, 260, 310, 40, 535, 695};
    int arr2[] = {1, 8, 6, 4, 13, 20, 3, 27};
    int arr3[] = {15, 10, 80, 45, 36, 18};
    int arr4[] = {1, 2, 1, 2, 2, 1};
    int arr5[] = {45, 12, 20, 3, 4, 31, 48};
    int arr6[] = {90, 80, 70, 60, 50};
    int arr7[] = {2, 30, 15, 10, 8, 25, 80};
    int arr8[] = {14, 10, 15, 2, 13, 7, 11};
    int arr9[] = {10, 25, 78, 200, 220};

    CheckSizeTEquality(FindMaxProfit(arr1, SizeOfArr(arr1)), 865, UNPRINT);
    CheckSizeTEquality(FindMaxProfit(arr2, SizeOfArr(arr2)), 47, UNPRINT);
    CheckSizeTEquality(FindMaxProfit(arr3, SizeOfArr(arr3)), 70, UNPRINT);
    CheckSizeTEquality(FindMaxProfit(arr4, SizeOfArr(arr4)), 2, UNPRINT);
    CheckSizeTEquality(FindMaxProfit(arr5, SizeOfArr(arr5)), 53, UNPRINT);
    CheckSizeTEquality(FindMaxProfit(arr6, SizeOfArr(arr6)), 0, UNPRINT);
    CheckSizeTEquality(FindMaxProfit(arr7, SizeOfArr(arr7)), 100, UNPRINT);
    CheckSizeTEquality(FindMaxProfit(arr8, SizeOfArr(arr8)), 20, UNPRINT);
    CheckSizeTEquality(FindMaxProfit(arr9, SizeOfArr(arr9)), 210, UNPRINT);

} 


