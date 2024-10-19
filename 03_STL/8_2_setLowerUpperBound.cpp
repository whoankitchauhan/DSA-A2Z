#include <iostream>
#include <set>

using namespace std;

int main()
{
    // Create a set of integers
    set<int> mySet = {10, 20, 30, 40, 50};

    // Find lower bound of 25
    auto it_lower = mySet.lower_bound(25);
    if (it_lower != mySet.end()) 
    {
        cout << "Lower bound of 25: " << *it_lower << endl;
    }
    else
    {
        cout << "Lower bound of 25 not found." << endl;
    }

    // Find upper bound of 25
    auto it_upper = mySet.upper_bound(25);
    if (it_upper != mySet.end())
    {
        cout << "Upper bound of 25: " << *it_upper << endl;
    }
    else
    {
        cout << "Upper bound of 25 not found." << endl;
    }

    return 0;
}

// Lower Bound: For a given value, the lower bound is the iterator pointing to the first element in the container that is not less than the given value. In other words, it returns an iterator pointing to the first element that is equal to or greater than the specified value.

// Upper Bound: For a given value, the upper bound is the iterator pointing to the first element in the container that is greater than the given value. It returns an iterator pointing to the first element that is strictly greater than the specified value.

// In simpler terms:

// Lower bound finds the first element that is equal to or greater than the given value.
// Upper bound finds the first element that is strictly greater than the given value. 