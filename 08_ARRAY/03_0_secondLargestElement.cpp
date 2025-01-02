// Brute Force:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int secondLargest(vector<int> &arr)
{
    int n = arr.size();

    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    // Step 2: Find the second largest element
    int largest = arr[n - 1];
    int secondLargest = -1; // Initialize to -1 to handle cases with no second largest

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            secondLargest = arr[i];
            break; // Stop after finding the first element different from the largest
        }
    }

    return secondLargest;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 5, 5, 5};

    int result = secondLargest(arr);
    if (result != -1)
    {
        cout << "The second largest element is: " << result << endl;
    }
    else
    {
        cout << "There is no second largest element in the array." << endl;
    }

    return 0;
}

