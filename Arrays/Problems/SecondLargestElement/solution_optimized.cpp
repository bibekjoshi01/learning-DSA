#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Two Pass Search: Time Complexity: O(n)
int secondLargestElement(vector<int> nums)
{
    int size = nums.size();

    int largest = -1;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] > largest)
        {
            largest = nums[i];
        }
    }

    // finding second largest
    int second_largest = -1;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > second_largest && nums[i] != largest)
        {
            second_largest = nums[i];
        }
    }

    return second_largest;
}

int main()
{
    vector<int> nums = {3, 4, 1, 7, 9, 8, 3, 9};

    cout << "Second Largest: " << secondLargestElement(nums) << endl;

    return 0;
}