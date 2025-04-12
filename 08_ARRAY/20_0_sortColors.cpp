#include <bits/stdc++.h>
using namespace std;

// Brute force using built-in sort
void sortColors(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    cout << "Sorted Colors: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
