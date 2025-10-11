#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOveralappingIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    // Mark merged intervals
    vector<bool> mergedFlag(n, false);
    vector<vector<int>> result;

    for (int i = 0; i < n; ++i)
    {
        if (mergedFlag[i])
            continue;
        int start = intervals[i][0];
        int end = intervals[i][1];
        for (int j = i + 1; j < n; ++j)
        {
            if (mergedFlag[j])
                continue;
            // Check if overlap
            if (!(intervals[j][0] > end || intervals[j][1] < start))
            {
                start = min(start, intervals[j][0]);
                end = max(end, intervals[j][1]);
                mergedFlag[j] = true;
            }
        }
        result.push_back({start, end});
    }

    // Sort final result
    sort(result.begin(), result.end());
    return result;
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
