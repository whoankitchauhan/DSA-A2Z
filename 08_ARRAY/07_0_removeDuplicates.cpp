#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to remove duplicates using a set
int removeDuplicatesWithSet(vector<int> &nums)
{
    set<int> uniqueElements; // Step 1: Store unique elements in a set

    // Step 2: Insert all elements of nums into the set
    for (int num : nums)
    {
        uniqueElements.insert(num);
    }

    // Step 3: Rewrite nums with unique elements from the set
    int index = 0;
    for (int element : uniqueElements)
    {
        nums[index] = element;
        index++;
    }

    return uniqueElements.size(); // Return the count of unique elements
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 4, 4, 5};

    cout << "Original array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    int uniqueCount = removeDuplicatesWithSet(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Number of unique elements: " << uniqueCount << endl;

    return 0;
}
