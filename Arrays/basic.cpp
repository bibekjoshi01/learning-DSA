#include <iostream>

int main()
{
    // Declaration and Initialization of an array
    int numbers[5] = {1, 2, 3, 4, 5}; // Declare and initialize with values

    // Accessing and printing array elements
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Modifying array elements
    numbers[0] = 10; // Change the first element to 10
    numbers[4] = 50; // Change the last element to 50

    // Display modified array
    std::cout << "Modified array elements: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
