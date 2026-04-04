class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();

        vector<int> dp(n, 1);

        for(int j = 0; j < n; j++) {
            for(int i = 0; i < j; i++) {

                bool valid = true;
                for(int k = 0; k < m; k++) {
                    if(strs[k][i] > strs[k][j]) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        int longest = *max_element(dp.begin(), dp.end());
        return n - longest;
    }
};