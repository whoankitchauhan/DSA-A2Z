#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Function to calculate the maximum profit from a single buy-sell stock transaction
int getMaxStockProfit(vector<int> &prices)
{
    int minPrice = INT_MAX, maxProfit = 0;

    for (int price : prices)
    {
        minPrice = min(minPrice, price);              // Track the lowest price so far (best buy)
        maxProfit = max(maxProfit, price - minPrice); // Max profit if selling today
    }

    return maxProfit;
}

// Driver code to test the function with multiple scenarios
int main()
{
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test Case 1 - Max Stock Profit: " << getMaxStockProfit(prices1) << endl;
    // Expected: 5 (Buy at 1, Sell at 6)

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test Case 2 - Max Stock Profit: " << getMaxStockProfit(prices2) << endl;
    // Expected: 0 (No profitable trade)

    vector<int> prices3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3 - Max Stock Profit: " << getMaxStockProfit(prices3) << endl;
    // Expected: 4 (Buy at 1, Sell at 5)

    vector<int> prices4 = {2, 2, 2, 2};
    cout << "Test Case 4 - Max Stock Profit: " << getMaxStockProfit(prices4) << endl;
    // Expected: 0 (No profit)

    return 0;
}
