#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(const vector<int> &nums)
{
    int n = nums.size();

    long long expectedSum = (long long)n * (n + 1) / 2;
    long long expectedSqSum = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long actualSum = 0, actualSqSum = 0;
    for (int num : nums)
    {
        actualSum += num;
        actualSqSum += (long long)num * num;
    }

    long long diffSum = actualSum - expectedSum;       // repeated - missing
    long long diffSqSum = actualSqSum - expectedSqSum; // (repeated^2 - missing^2)

    long long sumAB = diffSqSum / diffSum; // repeated + missing

    long long repeated = (diffSum + sumAB) / 2;
    long long missing = repeated - diffSum;

    return {(int)repeated, (int)missing};
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
