#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &firstArray, vector<int> &secondArray, int k)
{
    int i = 0, j = 0, count = 0;
    int n = firstArray.size(), m = secondArray.size();

    while (i < n && j < m)
    {
        if (firstArray[i] <= secondArray[j])
        {
            count++;
            if (count == k)
                return firstArray[i];
            i++;
        }
        else
        {
            count++;
            if (count == k)
                return secondArray[j];
            j++;
        }
    }

    while (i < n)
    {
        count++;
        if (count == k)
            return firstArray[i];
        i++;
    }

    while (j < m)
    {
        count++;
        if (count == k)
            return secondArray[j];
        j++;
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
