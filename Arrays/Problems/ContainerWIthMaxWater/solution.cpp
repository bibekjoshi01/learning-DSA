#include <iostream>
#include <vector>

using namespace std;

int max_area(vector<int> heights)
{
    int max_water = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        for (int j = i + 1; j < heights.size(); j++)
        {
            int lower_bound = min(heights[i], heights[j]);
            max_water = max(lower_bound * (j - i), max_water);
        }
    }

    return max_water;
}

int main()
{
    vector<int> heights = {1, 7, 3, 4, 6, 8};

    int max_water = max_area(heights);

    cout << "Max Water: " << max_water << endl;
    return 0;
}