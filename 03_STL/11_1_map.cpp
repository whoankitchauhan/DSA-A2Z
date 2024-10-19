#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
    // Example 1: std::map<int, std::pair<int, int>>
    map<int, pair<int, int>> map1;

    // Inserting elements into map1
    map1[1] = make_pair(10, 20);
    map1[2] = make_pair(30, 40);
    map1[3] = make_pair(50, 60);

    // Printing elements of map1
    cout << "Map 1: " << endl;
    for (const auto &entry : map1)
    {
        cout << "Key: " << entry.first << ", Value: (" << entry.second.first << ", " << entry.second.second << ")" << endl;
    }

    // Finding elements in map1
    cout << "\nFinding elements in Map 1:" << endl;
    auto it1 = map1.find(2);
    if (it1 != map1.end())
    {
        cout << "Key 2 found in Map 1. Value: (" << it1->second.first << ", " << it1->second.second << ")" << endl;
    }
    else
    {
        cout << "Key 2 not found in Map 1." << endl;
    }

    // Example 2: std::map<std::pair<int, int>, int>
    map<pair<int, int>, int> map2;

    // Inserting elements into map2
    map2[make_pair(1, 2)] = 10;
    map2[make_pair(3, 4)] = 20;
    map2[make_pair(5, 6)] = 30;

    // Printing elements of map2
    cout << "\nMap 2: " << endl;
    for (const auto &entry : map2)
    {
        cout << "Key: (" << entry.first.first << ", " << entry.first.second << "), Value: " << entry.second << endl;
    }

    // Erasing an element from map2
    cout << "\nErasing (3, 4) from Map 2..." << endl;
    map2.erase(make_pair(3, 4));

    // Printing elements of map2 after erasing
    cout << "Map 2 after erasing:" << endl;
    for (const auto &entry : map2)
    {
        cout << "Key: (" << entry.first.first << ", " << entry.first.second << "), Value: " << entry.second << endl;
    }

    return 0;
}
