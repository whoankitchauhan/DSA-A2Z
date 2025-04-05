#include <iostream>
#include <vector>
using namespace std;

// Function to rearrange elements with alternate pos-neg,
// extra positives or negatives are added at the end
vector<int> rearrangeAlternateSign(vector<int> &nums)
{
    vector<int> pos, neg;

    // Separate positives and negatives
    for (int num : nums)
    {
        if (num >= 0)
            pos.push_back(num);
        else
            neg.push_back(num);
    }

    vector<int> result;
    int i = 0, j = 0;

    // Interleave positive and negative numbers
    while (i < pos.size() && j < neg.size())
    {
        result.push_back(pos[i++]);
        result.push_back(neg[j++]);
    }

    // Add remaining positive numbers (if any)
    while (i < pos.size())
        result.push_back(pos[i++]);

    // Add remaining negative numbers (if any)
    while (j < neg.size())
        result.push_back(neg[j++]);

    return result;
}

int main()
{
    vector<int> nums = {3, -1, -2, -3, 4, 5}; // Unequal pos & neg
    vector<int> result = rearrangeAlternateSign(nums);

    cout << "Rearranged (pos-neg alternating, order not maintained): ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
