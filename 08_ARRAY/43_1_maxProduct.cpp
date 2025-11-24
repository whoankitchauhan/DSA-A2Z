#include <bits/stdc++.h>
using namespace std;

int maxProduct(const vector<int> &nums)
{
    int n = nums.size();
    int prefix = 1;
    int suffix = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        prefix *= nums[i];
        suffix *= nums[n - i - 1];

        ans = max(ans, max(prefix, suffix));

        if (nums[i] == 0)
            prefix = 1;
        if (nums[n - 1 - i] == 0)
            suffix = 1;
    }
    return ans;
}

void printArray(const vector<int> &arr)
{
    cout << "[ ";
    for (int x : arr)
        cout << x << " ";
    cout << "]";
}

void runTest(vector<int> nums, int expected)
{
    cout << "Input: ";
    printArray(nums);
    cout << "\n";

    int result = maxProduct(nums);

    cout << "Result:   " << result << "\n";
    cout << "Expected: " << expected << "\n";
    cout << "-----------------------------\n";
}

int main()
{
    vector<vector<int>> tests = {
        {2, 3, -2, 4},
        {-2, 0, -1},
        {-2, 3, -4},
        {0, 0, 0},
        {1, 2, 3, 4},
        {-1, -3, -10, 0, 60},
        {-2, -3, 0, -2, -40},
        {-1},
        {2, -5, -2, -4, 3}, // tricky negative flips
        {0, -1, 2, -3, 0, 4, -1}};

    vector<int> expected = {
        6,
        0,
        24,
        0,
        24,
        60,
        80,
        -1,
        24,
        6};

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test Case " << i + 1 << ":\n";
        runTest(tests[i], expected[i]);
    }

    return 0;
}
