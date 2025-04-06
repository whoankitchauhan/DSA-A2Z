#include <iostream>
#include <vector>
using namespace std;

// Binary Search Function
int binarySearch(const vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Prevents overflow

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Not found
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 7, 9}; // Sorted array
    int target = 7;

    int result = binarySearch(arr, target);

    if (result != -1)
        cout << "Binary Search: Element found at index " << result << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    return 0;
}
