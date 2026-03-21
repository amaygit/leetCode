class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int r=x,c=y;
         for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                swap(grid[r + i][c + j], grid[r + k - 1 - i][c + j]);
            }
        }
        return grid;
    }
};