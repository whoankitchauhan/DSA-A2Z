#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &firstArray, vector<int> &secondArray, int k)
{
    int n = firstArray.size(), m = secondArray.size();
    if (n > m)
        return kthElement(secondArray, firstArray, k);

    int low = max(0, k - m);
    int high = min(k, n);

    while (low <= high)
    {
        int cutA = (low + high) >> 1;
        int cutB = k - cutA;

        int leftA = (cutA == 0) ? INT_MIN : firstArray[cutA - 1];
        int leftB = (cutB == 0) ? INT_MIN : secondArray[cutB - 1];
        int rightA = (cutA == n) ? INT_MAX : firstArray[cutA];
        int rightB = (cutB == m) ? INT_MAX : secondArray[cutB];

        if (leftA <= rightB && leftB <= rightA)
            return max(leftA, leftB);
        else if (leftA > rightB)
            high = cutA - 1;
        else
            low = cutA + 1;
    }

    return -1;
}

void printVector(const vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    vector<vector<int>> firstArrayTests = {
        {2, 3, 6, 7, 9},
        {1, 4, 8, 10},
        {},
        {1, 2, 3},
        {5}};

    vector<vector<int>> secondArrayTests = {
        {1, 4, 8, 10},
        {2, 3, 6, 7, 9},
        {2, 3},
        {},
        {}};

    vector<int> kValues = {5, 3, 2, 2, 1};

    vector<int> expectedResults = {
        6,
        3,
        3,
        2,
        5};

    for (int i = 0; i < firstArrayTests.size(); ++i)
    {
        cout << "Test Case " << i + 1 << "\n";

        cout << "First Array  = ";
        printVector(firstArrayTests[i]);
        cout << "\nSecond Array = ";
        printVector(secondArrayTests[i]);
        cout << "\nK = " << kValues[i] << "\n";

        int result = kthElement(
            firstArrayTests[i],
            secondArrayTests[i],
            kValues[i]);

        cout << "Expected = " << expectedResults[i] << "\n";
        cout << "Actual   = " << result << "\n\n";
    }

    return 0;
}
