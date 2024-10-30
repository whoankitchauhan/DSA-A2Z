#include <iostream>
using namespace std;

void countFrequency(int arr[], int n)
{
    int frequency[10] = {0}; // Array to store frequency of numbers 0-9

    // Count each number in the array
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]]++;
    }

    // Print the frequency of each number
    for (int i = 0; i < 10; i++)
    {
        if (frequency[i] > 0)
        {
            cout << "Number " << i << " appears " << frequency[i] << " times." << endl;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Frequency of each number in the array:\n";
    countFrequency(arr, n);

    return 0;
}