/* Pair Sum : Return pair in sorted array with target sum */
#include <iostream>
#include <vector>

using namespace std;

vector<int> pair_sum(vector<int> nums, int target_sum)
{
    /* Time complexity: O(n)*/
    
    vector<int> result;
    int i = 0;
    int j = nums.size() - 1;
    int pair_sum = 0;
    while (i < j)
    {
        pair_sum = nums[i] + nums[j];
        if (pair_sum < target_sum)
        {
            i++;
        }
        else if (pair_sum > target_sum)
        {
            j--;
        }
        else
        {
            result.push_back(i);
            result.push_back(j);
            return result;
        }
    }
    return result;
}

int main()
{
    // Sorted Array
    vector<int> nums = {4, 5, 8, 9, 10};
    int target_sum = 17;

    vector<int> result = pair_sum(nums, target_sum);

    cout << result[0] << ", " << result[1] << endl;

    return 0;
}