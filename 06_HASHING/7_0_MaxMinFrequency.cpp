#include <bits/stdc++.h>
using namespace std;

// Function to count frequencies and find the element with the highest and lowest frequency
void countFreq(int arr[], int n)
{
    // Vector to keep track of visited elements
    vector<bool> visited(n, false);

    // Variables to store the highest and lowest frequency and their corresponding elements
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    // Loop to count the frequency of each element in the array
    for (int i = 0; i < n; i++)
    {

        // Skip this element if it has already been processed
        if (visited[i] == true)
            continue;

        // Count the frequency of the current element
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = true; // Mark element as visited
                count++;           // Increase frequency count
            }
        }

        // Update maxFreq and minFreq along with the corresponding elements
        if (count > maxFreq)
        {
            maxEle = arr[i]; // Update the element with the highest frequency
            maxFreq = count;
        }
        if (count < minFreq)
        {
            minEle = arr[i]; // Update the element with the lowest frequency
            minFreq = count;
        }
    }

    // Output the results
    cout << "The highest frequency element is: " << maxEle << " (Frequency: " << maxFreq << ")\n";
    cout << "The lowest frequency element is: " << minEle << " (Frequency: " << minFreq << ")\n";
}

int main()
{
    // Example array
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Call the function to calculate and print frequency details
    countFreq(arr, n);

    return 0;
}
