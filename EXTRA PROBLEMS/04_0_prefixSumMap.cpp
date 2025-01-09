#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    // Creating an unordered map to store key-value pairs
    unordered_map<int, int> prefixSumMap;

    // Inserting some key-value pairs into the map
    prefixSumMap[0] = -1; // key 0 maps to value -1
    prefixSumMap[1] = 0;  // key 1 maps to value 0
    prefixSumMap[3] = 1;  // key 3 maps to value 1
    prefixSumMap[6] = 2;  // key 6 maps to value 2

    // Search for a key that exists in the map
    int keyToFind = 3;
    // `find()` checks if keyToFind (3) exists in the map
    if (prefixSumMap.find(keyToFind) != prefixSumMap.end()) // If the key is found
    {
        cout << "Key " << keyToFind << " found!" << endl;
        // The `find()` function returns an iterator to the key-value pair
        // Access the value associated with the found key using the iterator
        cout << "The value associated with key " << keyToFind << " is " << prefixSumMap[keyToFind] << endl;
    }
    else
    {
        cout << "Key " << keyToFind << " not found!" << endl;
    }

    // Search for a key that doesn't exist in the map
    keyToFind = 5; // A key that is not in the map
    // `find()` checks if keyToFind (5) exists in the map
    if (prefixSumMap.find(keyToFind) != prefixSumMap.end()) // If the key is found
    {
        cout << "Key " << keyToFind << " found!" << endl;
    }
    else
    {
        cout << "Key " << keyToFind << " not found!" << endl;
    }

    return 0;
}

/*
Summary for Future Understanding:
find(key):
It is used to search for a key in the map.
If the key is found, it returns an iterator pointing to the key-value pair.
If the key is not found, it returns an iterator equal to prefixSumMap.end().

end():
This is a special iterator representing the position just past the last element in the map.
It is used to check if find() has found the key, as find() returns end() if the key is not found.


Important Notes:
find() is very efficient (O(1) on average) for searching in an unordered_map since it uses a hash table internally.
The end() function helps in confirming whether the key was found or not. It's important to check if the iterator returned by find() is not equal to end() before accessing the value.

*/