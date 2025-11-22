#include <bits/stdc++.h>
using namespace std;

long long reversePairs(const vector<int> &nums)
{
    int n = nums.size();
    long long count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[i] > 2LL * nums[j])
            {
                ++count;
            }
        }
    }
    return count;
}

void printArray(const vector<int> &arr)
{
    cout << "[ ";
    for (int x : arr)
        cout << x << " ";
    cout << "]";
}

void runTest(const vector<int> &arr, long long expected)
{
    cout << "Input: ";
    printArray(arr);
    cout << "\n";

    long long Ans = reversePairs(arr);

    cout << "Result: " << Ans << "\n";
    cout << "Expected: " << expected << "\n";
    cout << "-----------------------------\n";
}

int main()
{
    vector<vector<int>> testArrays = {
        {1, 3, 2, 3, 1}, // classic example
        {2, 4, 3, 5, 1}, // mixed reverse pairs
        {5, 4, 3, 2, 1}, // maximum reverse pairs
        {1, 2, 3, 4, 5}, // zero reverse pairs
        {2147483647, 1}, // overflow-safe test
        {1},             // single element
        {2, 3, 1, 2, 3}  // some scattered pairs
    };

    vector<long long> expected = {
        2, 3, 4, 0, 1, 0, 1};

    for (int i = 0; i < testArrays.size(); ++i)
    {
        cout << "Test Case " << i + 1 << ":\n";
        runTest(testArrays[i], expected[i]);
    }

    return 0;
}
