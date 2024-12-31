#include <bits/stdc++.h>
using namespace std;

// Function to calculate and display the element with highest and lowest frequency
void Frequency(int arr[], int n)
{
    // Create an unordered map to store frequency of each element in the array
    unordered_map<int, int> map;

    // Traverse the array and count the frequency of each element
    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    // Initialize variables to store the highest and lowest frequency and their respective elements
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    // Traverse through the map to find the elements with max and min frequencies
    for (auto it : map)
    {
        int count = it.second;  // Frequency of current element
        int element = it.first; // Current element

        // Update max frequency and element
        if (count > maxFreq)
        {
            maxEle = element;
            maxFreq = count;
        }

        // Update min frequency and element
        if (count < minFreq)
        {
            minEle = element;
            minFreq = count;
        }
    }

    // Output the results
    cout << "The highest frequency element is: " << maxEle << " (Frequency: " << maxFreq << ")\n";
    cout << "The lowest frequency element is: " << minEle << " (Frequency: " << minFreq << ")\n";
}

int main()
{
    // Example array with elements
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of array

    // Call the function to calculate and display frequencies
    Frequency(arr, n);
    return 0;
}
