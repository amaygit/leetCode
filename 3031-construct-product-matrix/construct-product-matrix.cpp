class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mod = 12345;

        vector<int> nums;
        for (auto &row : grid) {
            for (int x : row) {
                nums.push_back(x % mod);
            }
        }

        int size = nums.size();
        vector<int> res(size, 1);

        // prefix
        int prefix = 1;
        for (int i = 0; i < size; i++) {
            res[i] = prefix;
            prefix = (prefix * nums[i]) % mod;
        }

        // suffix
        int suffix = 1;
        for (int i = size - 1; i >= 0; i--) {
            res[i] = (res[i] * suffix) % mod;
            suffix = (suffix * nums[i]) % mod;
        }

        // convert back to matrix
        vector<vector<int>> ans(m, vector<int>(n));
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = res[k++];
            }
        }

        return ans;
    }
};