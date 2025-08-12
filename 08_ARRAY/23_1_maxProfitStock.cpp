#include <iostream>
#include <vector>
using namespace std;

int maxProfitStock(vector<int> &prices)
{
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        minPrice = min(prices[i], minPrice);
        maxProfit = max(prices[i] - minPrice, maxProfit);
    }
    return maxProfit;
}

int main()
{
    vector<vector<int>> testCases = {
        {7, 1, 5, 3, 6, 4},
        {7, 6, 4, 3, 1},
        {2, 4, 1},
        {1, 2, 3, 4, 5}};

    for (int t = 0; t < testCases.size(); t++)
    {
        cout << "Test Case " << t + 1 << ": ";
        for (int p : testCases[t])
            cout << p << " ";
        cout << "\n";

        cout << "Max Profit : " << maxProfitStock(testCases[t]) << "\n";
        cout << "-------------------------\n";
    }
    return 0;
}
