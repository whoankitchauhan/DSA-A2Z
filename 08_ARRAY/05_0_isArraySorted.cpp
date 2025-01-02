#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array is sorted in non-decreasing order
bool isSorted(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++)
    {
        // If the current element is smaller than the previous, the array is not sorted
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true; // Return true if no unsorted pair is found
}

int main()
{
    // Sample input array
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    // Check if the array is sorted
    if (isSorted(n, arr))
    {
        cout << "The array is sorted." << endl;
    }
    else
    {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}
