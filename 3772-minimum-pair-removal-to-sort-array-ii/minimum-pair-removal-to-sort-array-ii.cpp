class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        vector<long long> val(n);
        for (int i = 0; i < n; i++) {
            val[i] = nums[i];
        }

        vector<int> pre(n), nxt(n);

        for (int i = 0; i < n; i++) {
            pre[i] = i - 1;
            nxt[i] = (i + 1 < n ? i + 1 : -1);
        }

        int bad = 0;

        auto isBad = [&](int i) {
            return i != -1 && nxt[i] != -1 &&
                   val[i] > val[nxt[i]];
        };

        for (int i = 0; i + 1 < n; i++) {
            if (val[i] > val[i + 1]) bad++;
        }

        set<pair<long long, int>> s;

        for (int i = 0; i + 1 < n; i++) {
            s.insert({val[i] + val[i + 1], i});
        }

        vector<bool> alive(n, true);

        int ans = 0;

        while (bad > 0) {

            auto [sum, i] = *s.begin();
            s.erase(s.begin());

            int j = nxt[i];

            if (j == -1 || !alive[i] || !alive[j])
                continue;

            if (val[i] + val[j] != sum)
                continue;

            int L = pre[i];
            int R = nxt[j];

            if (isBad(L)) bad--;
            if (isBad(i)) bad--;
            if (isBad(j)) bad--;

            if (L != -1)
                s.erase({val[L] + val[i], L});

            s.erase({val[i] + val[j], i});

            if (R != -1)
                s.erase({val[j] + val[R], j});

            val[i] += val[j];

            alive[j] = false;

            nxt[i] = R;

            if (R != -1)
                pre[R] = i;

            if (L != -1 && val[L] > val[i]) bad++;

            if (R != -1 && val[i] > val[R]) bad++;

            if (L != -1)
                s.insert({val[L] + val[i], L});

            if (R != -1)
                s.insert({val[i] + val[R], i});

            ans++;
        }

        return ans;
    }
};