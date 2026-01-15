#include <bits/stdc++.h>
using namespace std;

bool isValidDivisor(vector<int> &nums, int threshold, int divisor)
{
    long long sum = 0;
    for (int num : nums)
    {
        sum += (num + divisor - 1) / divisor;
        if (sum > threshold)
            return false;
    }
    return true;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValidDivisor(nums, threshold, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

void printVector(const vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    vector<vector<int>> tests = {
        {1, 2, 5, 9},        // standard
        {2, 3, 5, 7, 11},    // primes
        {19},                // single element
        {1, 1, 1, 1, 1},     // all ones
        {1000000, 1000000},  // large values
        {10, 20, 30, 40, 50} // increasing
    };

    vector<int> thresholds = {
        6,  // expected 5
        11, // expected 3
        19, // expected 1
        5,  // expected 1
        2,  // expected 1000000
        10  // expected 15
    };

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << "\n";
        cout << "nums = ";
        printVector(tests[i]);
        cout << "\nthreshold = " << thresholds[i] << "\n";

        int ans = smallestDivisor(tests[i], thresholds[i]);
        cout << "Smallest Divisor = " << ans << "\n\n";
    }

    return 0;
}
