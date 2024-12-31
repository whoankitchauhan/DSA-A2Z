#include <iostream>
#include <map>
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

    // Map to store the frequency of each number
    map<int, int> frequencyMap;

    // Populate the map with the frequency of each number
    for (int i = 0; i < size; i++)
    {
        frequencyMap[numbers[i]]++;
    }

    // Print all key-value pairs in the frequency map
    cout << "Frequency of each number in the array:" << endl;
    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); it++)
    {
        cout << "Number: " << it->first << ", Count: " << it->second << endl;
    }

    // for ( auto it : frequencyMap)
    // {
    //     cout<< "Number: "  << it.first << " -> "<< ", Count: " << it.second << endl;
    // }

    // Query the frequency of numbers
    int queryCount;
    cout << "Enter the number of queries: ";
    cin >> queryCount;

    while (queryCount--)
    {
        int queryNumber;
        cout << "Enter a number to query its frequency: ";
        cin >> queryNumber;

        // Retrieve and display the frequency of the queried number
        cout << "Frequency of " << queryNumber << " in the array: "
             << frequencyMap[queryNumber] << endl;
    }

    return 0;
}
