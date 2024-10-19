#include <iostream>
#include <map>

using namespace std;

int main()
{
    // Create a map of integers to strings
    map<int, string> myMap;

    // Insert key-value pairs into the map
    myMap.insert({1, "One"});
    myMap.insert({2, "Two"});
    myMap[3] = "Three"; // Using subscript operator

    // Print the elements of the map
    cout << "Elements of the map:" << endl;
    for (const auto &pair : myMap)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // Check the size of the map
    cout << "Size of the map: " << myMap.size() << endl;

    // Erase an element from the map
    myMap.erase(2);

    // Print the elements of the map after erasing
    cout << "Elements of the map after erasing key 2:" << endl;
    for (const auto &pair : myMap)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // Check if a key is present in the map
    if (myMap.count(2) > 0)
    {
        cout << "Key 2 is present in the map." << endl;
    }
    else
    {
        cout << "Key 2 is not present in the map." << endl;
    }

    // Clear the map
    myMap.clear();

    // Check if the map is empty after clearing
    if (myMap.empty())
    {
        cout << "The map is empty after clearing." << endl;
    }

    return 0;
}
