#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// The majority element is the element that appears more than ⌊n / 2⌋ times in the array.
int majorityElement(vector<int> &nums)
{
    // Boyer-Moore Voting Algorithm
    int vote = 0, candidate = 0;
    for (int num : nums)
    {
        if (vote == 0)
        {
            candidate = num;
        }
        vote += (candidate == num) ? 1 : -1;
    }

    return candidate;

    // For Verify 
    // int count = 0;
    // for (int num : nums)
    //     if (num == candidate)
    //         count++;
    // if (count > nums.size() / 2)
    //     return candidate;
    // else
    //     return -1;
}

int main()
{

    vector<vector<int>> testCases = {
        {3, 2, 3},
        {2, 2, 1, 1, 1, 2, 2},
        {1, 1, 1, 2, 3, 4, 1},
        {5, 5, 5, 5, 2, 3},
        {9}};

    for (int i = 0; i < testCases.size(); ++i)
    {
        cout << "Test Case " << i + 1 << ": ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "\nOutput: " << majorityElement(testCases[i]) << "\n";
        cout << "------------------------\n";
    }

    return 0;
}