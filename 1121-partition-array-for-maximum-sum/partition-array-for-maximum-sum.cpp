class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<int>& dp) {
        if (i >= arr.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int mx = 0;
        int ans = 0;

        for (int j = i; j < min((int)arr.size(), i + k); j++) {
            mx = max(mx, arr[j]);

            int len = j - i + 1;

            ans = max(ans,
                      len * mx + solve(j + 1, arr, k, dp));
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);

        return solve(0, arr, k, dp);
    }
};