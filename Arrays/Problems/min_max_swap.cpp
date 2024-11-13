#include <iostream>

using namespace std;

void min_max_swap(int array[], int size)
{
    if (size <= 1)
        return;
    int min_index = 0, max_index = 0;
    int min = array[0];
    int max = array[0];

    // Find the indices of min and max
    for (int i = 0; i < size; i++)
    {
        if (array[i] < array[min_index])
        {
            min_index = i;
        }
        else if (array[i] > array[max_index])
        {
            max_index = i;
        }
    }

    // Swap min and max values
    if (min_index != max_index)
    {
        int temp = array[min_index];
        array[min_index] = array[max_index];
        array[max_index] = temp;
    }
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int array[] = {4, 5, 9, 8, 2, 3};
    int size = sizeof(array) / sizeof(int);

    cout << "Array after swapping minimum and maximum value" << endl;
    print_array(array, size);

    // Call the swapping function
    min_max_swap(array, size);

    cout << "Array after swapping minimum and maximum value" << endl;
    print_array(array, size);

    return 0;
}