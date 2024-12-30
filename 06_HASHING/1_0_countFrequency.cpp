// #include <iostream>
// using namespace std;

// void countFrequency(int arr[], int n)
// {
//     int frequency[10] = {0}; // Array to store frequency of numbers 0-9

//     // Count each number in the array
//     for (int i = 0; i < n; i++)
//     {
//         frequency[arr[i]]++;
//     }

//     // Print the frequency of each number
//     for (int i = 0; i < 10; i++)
//     {
//         if (frequency[i] > 0)
//         {
//             cout << "Number " << i << " appears " << frequency[i] << " times." << endl;
//         }
//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 5, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Frequency of each number in the array:\n";
//     countFrequency(arr, n);

//     return 0;
// }

#include <iostream>
using namespace std;

void countFrequency(int arr[], int n)
{
    // Find the maximum element in the array
    int maxElement = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    // Create a frequency array of size (maxElement + 1)
    int frequency[maxElement + 1] = {0};

    // Count occurrences of each number
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]]++;
    }

    // Print only non-zero frequencies
    cout << "Element : Frequency" << endl;
    for (int i = 0; i <= maxElement; i++)
    {
        if (frequency[i] > 0)
        {
            cout << "Number " << i << " appears " << frequency[i] << " times." << endl;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 1, 1, 3, 4, 5, 5, 9, 8, 8, 1, 5, 10, 12, 12, 12, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    countFrequency(arr, n);

    return 0;
}
