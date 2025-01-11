/* Searching element in sorted array using binary search */

#include <stdio.h>

int search(int *arr, int low, int high, int target)
{
    if (high > low)
    {
        int mid = (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else
        {
            if (arr[mid] < target)
            {
                return search(arr, mid + 1, high, target);
            }
            else
            {
                return search(arr, low, mid - 1, target);
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    int result = search(arr, 0, size, 2);
    if (result > 0)
    {
        printf("Target found at index %d", result);
    }
    else
    {
        printf("Target not found!");
    }

    return 0;
}
