#include <iostream>

using namespace std;

int get_unique_values(int array[], int unique_array[], int size)
{
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }

        if (count == 1)
        {
            unique_array[index] = array[i];
            index++;
        }
    }

    return index;
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
    int array[] = {3, 3, 9, 8, 2, 3, 2, 9, 2};
    int size = sizeof(array) / sizeof(int);
    int unique_array[size];

    cout << "Given Array:" << endl;
    print_array(array, size);

    // Call the swapping function
    int unique_array_size = get_unique_values(array, unique_array, size);

    cout << "Unique Values" << endl;
    print_array(unique_array, unique_array_size);

    return 0;
}