#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    string inputString;
    cout << "Enter a string: ";
    cin >> inputString;

    // Create a map to store character frequencies
    // Key: Character, Value: Frequency (occurrence count)
    map<char, int> characterFrequency;

    // Count the frequency of each character
    for (char character : inputString)
    {
        characterFrequency[character]++;
    }

    // Display all character frequencies
    cout << "\nCharacter Frequencies in the String:" << endl;
    for ( auto character : characterFrequency)
    {
        cout << "'" << character.first << "' -> " << character.second << endl;
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

    return 0;
}
