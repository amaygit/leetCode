class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int r = 0; r < k; r++) {
                    if(dp[i][j][r] == 0) continue;

                    // move down
                    if(i + 1 < m) {
                        int nr = (r + grid[i+1][j]) % k;
                        dp[i+1][j][nr] = (dp[i+1][j][nr] + dp[i][j][r]) % MOD;
                    }

                    // move right
                    if(j + 1 < n) {
                        int nr = (r + grid[i][j+1]) % k;
                        dp[i][j+1][nr] = (dp[i][j+1][nr] + dp[i][j][r]) % MOD;
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};