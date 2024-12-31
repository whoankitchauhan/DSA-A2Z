#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    string inputString;
    cout << "Enter a string: ";
    cin >> inputString;

    // Create an unordered_map to store character frequencies
    // unordered_map offers faster search, insert, and delete operations compared to map.
    // It uses a hash table with O(1) average time complexity for these operations.
    unordered_map<char, int> characterFrequency;

    // Count the frequency of each character in the input string
    for (char character : inputString)
    {
        characterFrequency[character]++;
    }

    // Display all character frequencies
    cout << "\nCharacter Frequencies in the String:" << endl;
    for (const auto &entry : characterFrequency)
    {
        cout << "'" << entry.first << "' -> " << entry.second << endl;
    }

    // Allow the user to query specific character frequencies
    int queryCount;
    cout << "\nEnter the number of queries: ";
    cin >> queryCount;

    while (queryCount--)
    {
        char queryCharacter;
        cout << "Enter a character to query its frequency: ";
        cin >> queryCharacter;

        // Check and display the frequency of the queried character
        if (characterFrequency.find(queryCharacter) != characterFrequency.end())
        {
            cout << "Frequency of '" << queryCharacter << "' -> "
                 << characterFrequency[queryCharacter] << endl;
        }
        else
        {
            cout << "Character '" << queryCharacter << "' not found in the string." << endl;
        }
    }

    // Advantages of using unordered_map:
    // 1. Faster average lookup time: O(1) instead of O(log n) in map (due to hash table structure).
    // 2. Faster insert and delete operations: O(1) for average cases.
    // 3. No ordering of elements: If order of characters is not important, unordered_map is more efficient.
    // 4. Ideal for situations where quick access to data is needed, like counting occurrences of characters.

    return 0;
}
