class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int,int> minRow, maxRow;
        unordered_map<int,int> minCol, maxCol;

        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            if (!minRow.count(x)) {
                minRow[x] = maxRow[x] = y;
            } else {
                minRow[x] = min(minRow[x], y);
                maxRow[x] = max(maxRow[x], y);
            }

            if (!minCol.count(y)) {
                minCol[y] = maxCol[y] = x;
            } else {
                minCol[y] = min(minCol[y], x);
                maxCol[y] = max(maxCol[y], x);
            }
        }

        int ans = 0;

        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            bool rowCovered =
                minRow[x] < y && y < maxRow[x];

            bool colCovered =
                minCol[y] < x && x < maxCol[y];

            if (rowCovered && colCovered)
                ans++;
        }

        return ans;
    }
};