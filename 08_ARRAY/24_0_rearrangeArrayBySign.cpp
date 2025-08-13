#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArrayBySign(vector<int> &nums)
{
    vector<int> pos, neg;

    for (int num : nums)
    {
        if (num > 0)
            pos.push_back(num);
        else
            neg.push_back(num);
    }

    vector<int> result;
    result.reserve(nums.size()); // avoid reallocations

    // Merge them alternately, even if counts are unequal
    for (int i = 0; i < max(pos.size(), neg.size()); i++)
    {
        if (i < pos.size())
            result.push_back(pos[i]);
        if (i < neg.size())
            result.push_back(neg[i]);
    }

    return result;
}

void printVector(const vector<int> &v)
{
    for (int num : v)
        cout << num << " ";
    cout << "\n";
}

int main()
{
    vector<vector<int>> testCases = {
        {3, 1, -2, -5, 2, -4},
        {-1, 1},
        {5, -3, -2, 4},
        {10, -1, 2, -3, 4, -5},
        {1, 2, -1},
        {-1, -2, 3}};

    for (int t = 0; t < testCases.size(); ++t)
    {
        cout << "Test Case " << t + 1 << ": ";
        printVector(testCases[t]);
        cout << "Result : ";
        printVector(rearrangeArrayBySign(testCases[t]));
        cout << "-------------------------\n";
    }
    return 0;
}
