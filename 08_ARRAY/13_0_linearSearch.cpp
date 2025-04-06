#include <iostream>
#include <vector>
using namespace std;

// Linear Search Function
int linearSearch(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i; // Return the index if found
    }
    return -1; // Not found
}

int main()
{
    vector<int> arr = {4, 2, 7, 1, 9, 5};
    int target = 7;

    int result = linearSearch(arr, target);

    if (result != -1)
        cout << "Linear Search: Element found at index " << result << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    return 0;
}
