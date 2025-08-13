#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArrayBySignUnequal(const vector<int> &nums)
{
    vector<int> pos, neg;
    for (int num : nums)
    {
        if (num >= 0)
            pos.push_back(num);
        else
            neg.push_back(num);
    }

    vector<int> result;
    int i = 0, j = 0;
    while (i < pos.size() && j < neg.size())
    {
        result.push_back(pos[i++]);
        result.push_back(neg[j++]);
    }
    while (i < pos.size())
        result.push_back(pos[i++]);
    while (j < neg.size())
        result.push_back(neg[j++]);

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
        printVector(rearrangeArrayBySignUnequal(testCases[t]));
        cout << "-------------------------\n";
    }
}
