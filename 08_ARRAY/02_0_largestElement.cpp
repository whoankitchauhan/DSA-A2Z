#include <iostream>
#include <vector>
using namespace std;

// Function to find the largest element in the array
int largest(vector<int> &arr)
{
    // Initialize the largest variable with the first element of the array
    int largest = arr[0];

    // Traverse the array starting from the second element
    for (int i = 1; i < arr.size(); i++)
    {
        // If the current element is larger, update the largest variable
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }

    // Return the largest element found
    return largest;
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

    // Call the function to find the largest element
    int result = largest(arr);

    // Output: Display the largest element
    cout << "The largest element in the array is: " << result << endl;

    return 0;
}
