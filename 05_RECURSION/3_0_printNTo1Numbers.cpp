#include <iostream>
#include <vector>

using namespace std;

// Recursive function to generate numbers from x down to 1
vector<int> generateNumbersDescending(int x)
{
    if (x == 0)
    {
        // Base case: If x is 0, return an empty vector
        return {};
    }
    else
    {
        // Create the vector and add x first to get descending order
        vector<int> arr;
        arr.emplace_back(x);

        // Recursive call to add remaining numbers from x-1 down to 1
        vector<int> remaining = generateNumbersDescending(x - 1);
        arr.insert(arr.end(), remaining.begin(), remaining.end());

        return arr;
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Generate the vector from n down to 1
    vector<int> result = generateNumbersDescending(n);

    // Output the vector contents
    cout << "Generated vector: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
