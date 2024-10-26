#include <iostream>
#include <vector>

using namespace std;

// Recursive function to generate numbers from 1 to x
vector<int> generateNumbers(int x)
{
    if (x == 0)
    {
        // Base case: If x is 0, return an empty vector
        return {};
    }
    else
    {
        // Recursive step: Get vector for numbers from 1 to (x - 1)
        vector<int> arr = generateNumbers(x - 1);

        // Append x to the end of the vector
        arr.emplace_back(x);

        // Return the updated vector
        return arr;
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Generate the vector from 1 to n
    vector<int> result = generateNumbers(n);

    // Output the vector contents
    cout << "Generated vector: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
