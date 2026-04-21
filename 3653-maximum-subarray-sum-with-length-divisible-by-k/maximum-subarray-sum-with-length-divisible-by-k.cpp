class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPref(k, LLONG_MAX);

        long long pref = 0;
        long long ans = LLONG_MIN;

        minPref[0] = 0; // important

        for (int i = 0; i < n; i++) {
            pref += nums[i];

            int rem = (i + 1) % k;

            if (minPref[rem] != LLONG_MAX) {
                ans = max(ans, pref - minPref[rem]);
            }

            minPref[rem] = min(minPref[rem], pref);
        }

        return ans;
    }
};