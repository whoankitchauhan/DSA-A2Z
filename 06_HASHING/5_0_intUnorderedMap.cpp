#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // Input the size of the array
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int numbers[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    // Create an unordered_map to store frequency of each number
    // unordered_map uses hash tables, providing faster access (O(1) on average) 
    // for search, insert, and delete operations compared to map (O(log n)).
    unordered_map<int, int> frequencyMap;

    // Populate the unordered_map with the frequency of each number
    for (int i = 0; i < size; i++)
    {
        frequencyMap[numbers[i]]++;
    }

    // Display all key-value pairs in the unordered_map (frequencies of numbers)
    cout << "\nFrequency of each number in the array:" << endl;
    for (const auto &entry : frequencyMap)
    {
        cout << "Number: " << entry.first << " -> Frequency: " << entry.second << endl;
    }

    // Allow the user to query specific numbers for their frequency
    int queryCount;
    cout << "\nEnter the number of queries: ";
    cin >> queryCount;

    while (queryCount--)
    {
        int queryNumber;
        cout << "Enter a number to query its frequency: ";
        cin >> queryNumber;

        // Check and display the frequency of the queried number
        if (frequencyMap.find(queryNumber) != frequencyMap.end())
        {
            cout << "Frequency of " << queryNumber << " in the array: "
                 << frequencyMap[queryNumber] << endl;
        }
        else
        {
            cout << "Number " << queryNumber << " not found in the array." << endl;
        }
    }

    return 0;
}
