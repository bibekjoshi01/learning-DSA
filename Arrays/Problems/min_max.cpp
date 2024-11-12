#include <iostream>

int main()
{
    // Sample array
    int numbers[] = {3, 8, 1, 5, 12, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Initialize min and max values with the first element
    int min = numbers[0];
    int max = numbers[0];
    int minIndex = 0;
    int maxIndex = 0;

    // Loop through the array to find min and max values and their indices
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
            minIndex = i;
        }
        if (numbers[i] > max)
        {
            max = numbers[i];
            maxIndex = i;
        }
    }

    // Display the results
    std::cout << "Minimum element is " << min << " at index " << minIndex << std::endl;
    std::cout << "Maximum element is " << max << " at index " << maxIndex << std::endl;

    return 0;
}
