#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// One Pass Search: Time Complexity: O(n)
int secondLargestElement(vector<int> nums)
{
    int size = nums.size();

    int largest = -1;
    int second_largest = -1;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] > largest)
        {
            second_largest = largest;
            largest = nums[i];
        }

        else if (nums[i] < largest && nums[i] > second_largest)
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