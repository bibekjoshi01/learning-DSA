/* Pair Sum : Return pair in sorted array with target sum */
#include <iostream>
#include <vector>

using namespace std;

vector<int> pair_sum(vector<int> nums, int target_sum)
{
    /* Time complexity: O(n^2)*/

    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == target_sum)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {4, 5, 8, 9, 10};
    int target_sum = 17;

    vector<int> result = pair_sum(nums, target_sum);

    cout << result[0] << ", " << result[1] << endl;

    return 0;
}