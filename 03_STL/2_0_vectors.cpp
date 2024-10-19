#include <iostream>
#include <vector>
#include <algorithm> // For std::copy

using namespace std;

int main()
{
    // Vector of integers
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.emplace_back(3); // Emplacing an element using emplace_back
    a.emplace_back(4);

    // Vector of pairs
    vector<pair<int, int>> b;
    b.push_back({1, 2});
    b.emplace_back(1, 2);

    // Vector initialized with five elements, each set to 100
    vector<int> c(5, 100); // [100, 100, 100, 100, 100]

    // Vector initialized with five default-constructed elements (zeros)
    vector<int> d(5); // [0, 0, 0, 0, 0]

    // Vector copied from another vector
    vector<int> e(c); // Copy

    // Accessing element at index 1
    cout << "Element at index 1 of vector 'a': " << a[1] << endl;

    // Iterating through vector 'a' using iterators
    cout << "Iterating through vector 'a': ";
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Using reverse iterators to access elements in reverse order
    cout << "Reverse order elements of vector 'a': ";
    for (auto it = a.rbegin(); it != a.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Accessing the last element directly using back()
    cout << "Last element of vector 'a': " << a.back() << endl;

    // Checking vector 'b'
    cout << "Elements in vector 'b': ";
    for (const auto &pairElement : b)
    {
        cout << "(" << pairElement.first << ", " << pairElement.second << ") ";
    }
    cout << endl;

    // Displaying vector 'c'
    cout << "Vector 'c' elements: ";
    for (const auto &element : c)
    {
        cout << element << " ";
    }
    cout << endl;

    // Displaying vector 'd'
    cout << "Vector 'd' elements: ";
    for (const auto &element : d)
    {
        cout << element << " ";
    }
    cout << endl;

    // Displaying vector 'e'
    cout << "Vector 'e' elements (copied from vector 'c'): ";
    for (const auto &element : e)
    {
        cout << element << " ";
    }
    cout << endl;

    // Inserting elements at specific positions
    cout << "Inserting 99 at position 2 in vector 'a': ";
    a.insert(a.begin() + 2, 99); // Insert 99 at index 2
    for (const auto &element : a)
    {
        cout << element << " ";
    }
    cout << endl;

    // Copying elements from vector 'a' to vector 'd'
    cout << "Copying elements from vector 'a' to vector 'd': ";
    copy(a.begin(), a.end(), d.begin());
    for (const auto &element : d)
    {
        cout << element << " ";
    }
    cout << endl;

    // Deleting the last element from vector 'a'
    cout << "Deleting the last element from vector 'a': ";
    a.pop_back();
    for (const auto &element : a)
    {
        cout << element << " ";
    }
    cout << endl;

    // Erasing an element at index 1 from vector 'e'
    cout << "Erasing the element at index 1 from vector 'e': ";
    e.erase(e.begin() + 1);
    for (const auto &element : e)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}

/*
Emplace vs Push: Use emplace_back if you're constructing objects in place. For primitive types like int, push_back is fine, but for more complex objects (like pairs), emplace_back is preferred for performance reasons.
*/