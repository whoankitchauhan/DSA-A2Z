#include <iostream>
#include <vector>
#include <algorithm> // for max_element
using namespace std;

// Function to determine which kids can have the most candies
vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    vector<bool> ans; // Stores the result (true/false for each kid)

    // Find the maximum number of candies any kid currently has
    int max = *max_element(candies.begin(), candies.end());

    // Iterate through each kid's candy count
    for (int i = 0; i < candies.size(); i++)
    {
        // Check if giving extraCandies makes this kid have the most or equal to max
        ans.push_back(candies[i] + extraCandies >= max);
    }

    return ans; // Return the final result
}

// Driver code
int main()
{
    vector<int> candies = {2, 3, 5, 1, 3}; // Example input
    int extraCandies = 3;

    vector<bool> result = kidsWithCandies(candies, extraCandies);

    // Print the result
    cout << "Output: ";
    for (bool val : result)
    {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
