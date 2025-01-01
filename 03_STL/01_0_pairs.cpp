#include <iostream>
#include <utility> // Include this header for pair
using namespace std;

int main()
{
    // Storing two integers in a pair
    pair<int, int> pairA = {1, 2};
    cout << "Pair A: " << pairA.first << " " << pairA.second << endl;

    // Storing an integer and a pair of integers in another pair
    pair<int, pair<int, int>> pairB = {1, {2, 3}};
    cout << "Pair B: " << pairB.first << " " << pairB.second.first << " " << pairB.second.second << endl;
 
    // Storing an array of pairs
    pair<int, int> pairArr[] = {
        {1, 2},
        {3, 4},
        {5, 6}};

    cout << "Pair Array: " << pairArr[0].first << " " << pairArr[0].second << endl;

    // Modifying a pair in the array
    pairArr[1].first = 99;
    pairArr[1].second = 88;

    // Displaying the modified array
    cout << "Modified Pair Array: ";
    for (const auto &p : pairArr)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    // for (const auto &p : pairArr): This is a range-based for loop. It iterates over each element (p) in the array pairArr.

    // cout << "(" << p.first << ", " << p.second << ") ";: This prints the content of the current pair. It uses p.first to access the first element of the pair and p.second to access the second element. The elements are printed within parentheses and separated by a comma.
    return 0;
}
