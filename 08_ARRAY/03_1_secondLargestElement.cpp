#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Function to find the second largest element in the array
int secondLargest(vector<int> &arr)
{
    // Handle edge case: If the array has less than 2 elements
    if (arr.size() < 2)
    {
        cout << "Array must have at least two elements." << endl;
        return -1; // Indicates an invalid result
    }

    // Initialize the largest and second largest elements
    int largest = INT_MIN, secondLargest = INT_MIN;

    // Traverse the array to find the largest and second largest elements
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            // Update secondLargest before updating largest
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] < largest)
        {
            // Update secondLargest only if the current element is less than largest
            secondLargest = arr[i];
        }
    }

    // If secondLargest is still INT_MIN, there is no valid second largest element
    if (secondLargest == INT_MIN)
    {
        cout << "No second largest element found (all elements might be the same)." << endl;
        return -1;
    }

    return secondLargest;
}

int main()
{
    int n;

    // Input: Number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Declare a vector to store the array elements
    vector<int> arr(n);

    // Input: Elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call the function to find the second largest element
    int result = secondLargest(arr);

    // Output: Display the second largest element if valid
    if (result != -1)
    {
        cout << "The second largest element in the array is: " << result << endl;
    }

    return 0;
}
