#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the second smallest element in the array
int findSecondSmallest(int n, vector<int> &arr)
{
    int smallest = arr[0];        // Initialize the smallest element
    int secondSmallest = INT_MAX; // Initialize second smallest to a large value

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        { // Update both smallest and second smallest
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest)
        {
            secondSmallest = arr[i]; // Update only second smallest if conditions match
        }
    }

    return secondSmallest;
}

// Function to find the second largest element in the array
int findSecondLargest(int n, vector<int> &arr)
{
    int largest = arr[0];        // Initialize the largest element
    int secondLargest = INT_MIN; // Initialize second largest to a small value

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        { // Update both largest and second largest
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i]; // Update only second largest if conditions match
        }
    }

    return secondLargest;
}

// Function to return the second largest and second smallest elements in the array
vector<int> getSecondOrderElements(int n, vector<int> &arr)
{
    // Find the second smallest element
    int secondSmallest = findSecondSmallest(n, arr);

    // Find the second largest element
    int secondLargest = findSecondLargest(n, arr);

    // Return both results as a vector
    return {secondLargest, secondSmallest};
}

int main()
{
    // Sample input array
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    // Get the second largest and second smallest elements
    vector<int> result = getSecondOrderElements(n, arr);

    // Print the results
    cout << "Second Largest: " << result[0] << endl;
    cout << "Second Smallest: " << result[1] << endl;

    return 0;
}
