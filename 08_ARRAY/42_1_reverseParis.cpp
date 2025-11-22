#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else
        {
            temp.push_back(nums[j++]);
        }
    }

    while (i <= mid)
        temp.push_back(nums[i++]);
    while (j <= high)
        temp.push_back(nums[j++]);

    for (int k = 0; k < temp.size(); ++k)
        nums[low + k] = temp[k];
}

long long countPairs(vector<int> &nums, int low, int mid, int high)
{
    long long count = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && nums[i] > 2LL * nums[right])
        {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}

long long mergeSortAndCount(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;
    long long count = 0;

    count += mergeSortAndCount(nums, low, mid);
    count += mergeSortAndCount(nums, mid + 1, high);
    count += countPairs(nums, low, mid, high);

    merge(nums, low, mid, high);

    return count;
}

long long reversePairs(vector<int> nums)
{ // take by VALUE, not reference
    return mergeSortAndCount(nums, 0, nums.size() - 1);
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
