#include "test_module.h"

long FindMaxSubArr(const int *arr, size_t size, size_t *_start_index, size_t *_end_index)
{
    long max_sum = -1;
    long temp_max_sum = 0;
    size_t start_index = 0;
    size_t temp_start_index = 0;
    size_t end_index = 0;
    size_t i = 0;

    for (i = 0; i < size; i++)
    {
        temp_max_sum += (long)arr[i];
        if (temp_max_sum > max_sum)
        {
            max_sum = temp_max_sum;
            start_index = temp_start_index;
            end_index = i;
        }
        else if (temp_max_sum <= 0)
        {
            temp_max_sum = 0;
            temp_start_index = i + 1;
        }
    }

    *_start_index = start_index;
    *_end_index = end_index;

    return max_sum;
}


void TestMaxSub(int *arr, size_t size, size_t expected_start, size_t expected_end, long expected_sum)
{
    size_t start_index = 0;
    size_t end_index = 0;
    long sum = FindMaxSubArr(arr, size, &start_index, &end_index);

    CheckLongEquality(sum, expected_sum, PRINT);
    CheckSizeTEquality(start_index, expected_start, UNPRINT);
    CheckSizeTEquality(end_index, expected_end, UNPRINT);
}

void Tests()
{
    int arr1[] = {-2,1,-3,4,-1,2,3,-5,4};
    int arr2[] = {10,-3,0,1,-19,5,-2,-1,8,-4,7};
    int arr3[] = {1,7,6,-20,22};

    largestSubset(arr1, SizeOfArr(arr1));
    largestSubset(arr2, SizeOfArr(arr2));
    largestSubset(arr3, SizeOfArr(arr3));

    TestMaxSub(arr1, SizeOfArr(arr1), 3, 6, 8);
    TestMaxSub(arr2, SizeOfArr(arr2), 5, 10, 13);
    TestMaxSub(arr3, SizeOfArr(arr3), 4, 4, 22);

}

int main()
{
    Tests();

    return 0;
}