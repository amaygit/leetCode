class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();

        unordered_set<long long> candidates;

        // Edge cases
        candidates.insert((long long)pow(10, len) + 1);
        candidates.insert((long long)pow(10, len - 1) - 1);

        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        for (long long i = prefix - 1; i <= prefix + 1; i++) {
            string first = to_string(i);
            string second = first;

            // odd length -> skip middle char
            if (len % 2 == 1)
                second.pop_back();

            reverse(second.begin(), second.end());

            string pal = first + second;
            candidates.insert(stoll(pal));
        }

        candidates.erase(num);

        long long ans = -1;

        for (long long cand : candidates) {
            if (ans == -1 ||
                abs(cand - num) < abs(ans - num) ||
                (abs(cand - num) == abs(ans - num) && cand < ans)) {
                ans = cand;
            }
        }

        return to_string(ans);
    }
};