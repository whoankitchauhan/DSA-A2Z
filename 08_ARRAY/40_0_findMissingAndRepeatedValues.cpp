#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(n + 1, 0); // 1-indexed

    for (int x : nums)
        freq[x]++;

    int repeated = -1, missing = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (freq[i] == 2)
            repeated = i;
        else if (freq[i] == 0)
            missing = i;
        if (repeated != -1 && missing != -1)
            break;
    }
    return {repeated, missing};
}

void runTest(const vector<int> &nums, const vector<int> &expected)
{
    cout << "Input: [ ";
    for (int x : nums)
        cout << x << " ";
    cout << "]\n";

    vector<int> ans = findMissingAndRepeatedValues(nums);

    cout << "Output:   [" << ans[0] << ", " << ans[1] << "]\n";
    cout << "Expected: [" << expected[0] << ", " << expected[1] << "]\n";
    cout << "-------------------------\n";
}

int main()
{
    runTest({1, 2, 2, 4}, {2, 3});
    runTest({1, 1}, {1, 2});
    runTest({2, 2}, {2, 1});
    runTest({3, 2, 3, 4, 6, 5}, {3, 1});
    runTest({4, 3, 6, 2, 1, 1}, {1, 5});
    return 0;
}
