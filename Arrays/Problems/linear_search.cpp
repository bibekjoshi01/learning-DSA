#include <iostream>

using namespace std;

/* Time Complexity: O(n) i.e. Linear Time Complexity */
int linear_search(int array[], int size, int search)
{

    for (int i = 0; i < size; i++)
    {
        if (search == array[i])
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    // Initial Array
    int array[] = {45, 67, 39, 23, 78, 34, 56};
    int size = sizeof(array) / sizeof(array[0]);
    int search;

    cout << "Enter your search: ";
    cin >> search;

    int index = linear_search(array, size, search);

    cout << "Element Found at index: " << index << endl;

    return 0;
}