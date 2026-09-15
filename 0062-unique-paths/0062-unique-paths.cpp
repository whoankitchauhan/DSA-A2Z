class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> pathsPerRow(n, 1);

        for (int row = 1; row < m; row++) {

            for (int col = 1; col < n; col++) {

                pathsPerRow[col] = pathsPerRow[col] + pathsPerRow[col - 1];
            }
        }

        return pathsPerRow[n - 1];
    }
};
