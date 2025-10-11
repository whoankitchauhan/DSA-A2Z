#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOveralappingIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n <= 1)
        return intervals;

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < n; ++i)
    {
        vector<int> &last = merged.back();
        if (intervals[i][0] <= last[1])
        {
            last[1] = max(last[1], intervals[i][1]);
        }
        else
        {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

void printIntervals(const vector<vector<int>> &intervals)
{
    cout << "[ ";
    for (auto &iv : intervals)
        cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << "]";
}

int main()
{
    vector<vector<vector<int>>> testCases = {
        {{1, 3}, {2, 6}, {8, 10}, {15, 18}},
        {{1, 4}, {4, 5}},
        {{1, 10}, {2, 3}, {4, 8}, {9, 12}},
        {{5, 6}, {1, 2}, {3, 4}}};

    vector<vector<vector<int>>> expectedOutputs = {
        {{1, 6}, {8, 10}, {15, 18}},
        {{1, 5}},
        {{1, 12}},
        {{1, 2}, {3, 4}, {5, 6}}};

    for (int t = 0; t < testCases.size(); ++t)
    {
        cout << "Test Case " << t + 1 << ":\nInput: ";
        printIntervals(testCases[t]);
        cout << "\n";

        vector<vector<int>> result = mergeOveralappingIntervals(testCases[t]);

        cout << "Output:   ";
        printIntervals(result);
        cout << "\nExpected: ";
        printIntervals(expectedOutputs[t]);
        cout << "\n-------------------------\n";
    }
    return 0;
}
