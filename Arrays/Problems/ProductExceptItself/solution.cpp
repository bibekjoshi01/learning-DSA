#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                {
                    answer[i] *= nums[j];
                }
            }
        }
        return answer;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    cout << "Output: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}