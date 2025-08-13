#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArrayBySign(vector<int> nums)
{
    vector<int> result(nums.size());
    int posIndex = 0;
    int negIndex = 1;

    for (auto num : nums)
    {
        if (num > 0)
        {
            result[posIndex] = num;
            posIndex += 2;
        }
        else
        {
            result[negIndex] = num;
            negIndex += 2;
        }
    }
    return result;
}

void printVector(const vector<int> &v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
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
