#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer(nums.size(), 1);

        // calculating prefix product
        for (int i = 1; i < nums.size(); i++)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // calculating postfix product
        int suffix = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            suffix *= nums[i + 1];
            answer[i] *= suffix;
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