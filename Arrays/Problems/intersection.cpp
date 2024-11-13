#include <iostream>

using namespace std;

int find_intersection(int array1[], int array2[], int intersection[], int size1, int size2)
{
    int index = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (array1[i] == array2[j])
            {
                intersection[index] = array1[i];
                index++;
            }
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
    // Assume Array do not contain duplicate elements
    int array1[] = {1, 3, 8, 2, 9, 10, 4};
    int array2[] = {4, 5, 2, 6, 7, 1};
    int size1 = sizeof(array1) / sizeof(int);
    int size2 = sizeof(array2) / sizeof(int);
    int intersection[min(size1, size2)];

    cout << "Given Array 1:" << endl;
    print_array(array1, size1);
    cout << "Given Array 2:" << endl;
    print_array(array2, size2);

    // Call the swapping function
    int intersection_index = find_intersection(array1, array2, intersection, size1, size2);

    cout << "Intersection Array" << endl;
    print_array(intersection, intersection_index);

    return 0;
}