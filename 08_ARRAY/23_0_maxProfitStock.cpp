#include <iostream>
#include <vector>
using namespace std;

int maxProfitStock(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    { // buy day
        for (int j = i + 1; j < n; j++)
        { // sell day
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
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
