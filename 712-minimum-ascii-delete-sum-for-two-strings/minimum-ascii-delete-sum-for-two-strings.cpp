class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string& s1, string& s2) {
        if (i == s1.size()) {
            int sum = 0;
            while (j < s2.size()) sum += s2[j++];
            return sum;
        }

        if (j == s2.size()) {
            int sum = 0;
            while (i < s1.size()) sum += s1[i++];
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = solve(i + 1, j + 1, s1, s2);

        return dp[i][j] = min(
            s1[i] + solve(i + 1, j, s1, s2),
            s2[j] + solve(i, j + 1, s1, s2)
        );
    }

    int minimumDeleteSum(string s1, string s2) {
        dp.assign(s1.size(), vector<int>(s2.size(), -1));
        return solve(0, 0, s1, s2);
    }
};