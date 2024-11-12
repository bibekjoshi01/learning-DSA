#include <iostream>

using namespace std;

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }

    cout << endl;
}

void reverse_array(int array[], int size)
{
    int temp;
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        swap(array[start], array[end]);
        // temp = array[start];
        // array[start] = array[end];
        // array[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int array[] = {45, 67, 39, 23, 78, 34, 56, 76};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Initial Array: " << endl;
    print_array(array, size);

    // Call the reverse function
    reverse_array(array, size);

    cout << "Reversed Array: " << endl;
    print_array(array, size);

    return 0;
}