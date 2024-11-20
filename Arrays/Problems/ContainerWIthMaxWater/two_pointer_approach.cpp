#include <iostream>
#include <vector>

using namespace std;

int max_area(vector<int> heights)
{
    int max_water = 0;
    int lp = 0, rp = heights.size() - 1;

    while (rp > lp)
    {
        int width = rp - lp;
        int height = min(heights[lp], heights[rp]);
        int current_water = width * height;
        max_water = max(current_water, max_water);

        heights[rp] > heights[lp] ? lp++ : rp--;
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