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
        vector<int> prefix_product(nums.size(), 1);
        vector<int> postfix_product(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            prefix_product[i] = prefix_product[i - 1] * nums[i - 1];
        }

        // calculating postfix product
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            postfix_product[i] = postfix_product[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            answer[i] = prefix_product[i] * postfix_product[i];
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