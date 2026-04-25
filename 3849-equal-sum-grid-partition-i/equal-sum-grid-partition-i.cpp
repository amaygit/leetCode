class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        for (auto &row : grid)
            for (int x : row)
                total += x;

        long long pref = 0;

        // Horizontal cut
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) pref += grid[i][j];
            if (pref * 2 == total) return true;
        }

        pref = 0;

        // Vertical cut
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) pref += grid[i][j];
            if (pref * 2 == total) return true;
        }

        return false;
    }
};