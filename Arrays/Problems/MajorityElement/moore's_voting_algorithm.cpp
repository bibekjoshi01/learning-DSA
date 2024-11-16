#include <iostream>
#include <vector>

using namespace std;

int majority_element(vector<int> nums)
{
    int freq = 0, result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
        {
            result = nums[i];
        }

        if (result != nums[i])
        {
            freq--;
        }
        else
        {
            freq++;
        }
    }

    // This is check incase majority element is not present
    int count = 0;
    for (int num : nums)
    {
        if (num == result)
        {
            count++;
        }
    }

    if (count > nums.size() / 2)
        return result;
    
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 1, 1, 2, 1, 6, 3, 1};
    int result = majority_element(nums);

    cout << "Majority Element: " << result << endl;
    return 0;
}