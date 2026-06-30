class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        idx++;
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        idx++;
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & (-idx);
        }
        return res;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick bit(vals.size());

        long long ans = 0;

        for (int x : pref) {
            int pos = lower_bound(vals.begin(), vals.end(), x) - vals.begin();

            if (pos > 0)
                ans += bit.query(pos - 1);

            bit.update(pos, 1);
        }

        return ans;
    }
};