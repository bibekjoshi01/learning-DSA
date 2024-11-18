#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<int> prices)
{
    if (prices.empty())
        return 0;

    int profit = 0, best_buy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        profit = max(profit, prices[i] - best_buy);
        best_buy = min(best_buy, prices[i]);
    }

    return profit;
}

int main()
{

    vector<int> prices = {7, 1, 3, 5, 6, 2};

    int profit = max_profit(prices);

    cout << "Max Profit: " << profit << endl;
    return 0;
}