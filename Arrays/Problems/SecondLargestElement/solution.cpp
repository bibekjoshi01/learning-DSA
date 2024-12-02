#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Naive Approach: Time Complexity: O(nlog(n))
int secondLargestElement(vector<int> nums)
{
    int size = nums.size();
    int largest = nums[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        if (nums[i] < largest)
        {
            return nums[i];
        }
    }

    return -1;
}


int main()
{
    vector<int> nums = {3, 4, 1, 7, 9, 8, 3, 9};
    sort(nums.begin(), nums.end());

    cout << "Second Largest: " << secondLargestElement(nums) << endl;

    return 0;
}