#include <iostream>
using namespace std;

int main()
{
    // Input the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input the elements of the array
    int arr[n];
    cout << "Enter " << n << " integers separated by spaces: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Initialize an array to count occurrences of numbers from 0 to 12
    int hash[13] = {0};

    // Count the occurrences of each number in the array
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    // Input the number of queries
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    // Respond to queries regarding the count of specific numbers
    while (q--)
    {
        int number;
        cout << "Enter a number to query its count: ";
        cin >> number;
        cout << "Count of " << number << " in the array: " << hash[number] << endl;
    }

    return 0;
}
