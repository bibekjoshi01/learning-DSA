/* Solution is optimized using sorting technique */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majority_element(vector<int> nums)
{
    /* Time Complexity: O(nlog(n)) */

    // Sorting the array
    sort(nums.begin(), nums.end());

    int frequency = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        { 
            frequency++;
        }
        else
        {
            frequency = 1;
        }
        if (frequency > nums.size() / 2)
        {
            return nums[i];
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 1, 1, 2, 1, 6, 3, 1};
    int result = majority_element(nums);

    cout << "Majority Element: " << result << endl;
    return 0;
}