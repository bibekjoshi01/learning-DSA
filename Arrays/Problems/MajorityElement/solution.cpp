#include <iostream>
#include <vector>

using namespace std;

int majority_element(vector<int> nums)
{
    /* Time Complexity: O(n^2) */

    int min_recur = nums.size() / 2;

    for (int i = 0; i < nums.size(); i++)
    {
        int count = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }

        if (count > min_recur)
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