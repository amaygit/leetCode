class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string &s1, string &s2, int i, int j, int len) {

        string key = to_string(i) + "," + to_string(j) + "," + to_string(len);

        if (memo.count(key))
            return memo[key];

        if (s1.substr(i, len) == s2.substr(j, len))
            return memo[key] = true;

        vector<int> freq(26, 0);
        for (int k = 0; k < len; k++) {
            freq[s1[i + k] - 'a']++;
            freq[s2[j + k] - 'a']--;
        }

        for (int x : freq)
            if (x != 0)
                return memo[key] = false;

        for (int split = 1; split < len; split++) {

            // No swap
            if (solve(s1, s2, i, j, split) &&
                solve(s1, s2, i + split, j + split, len - split))
                return memo[key] = true;

            // Swap
            if (solve(s1, s2, i, j + len - split, split) &&
                solve(s1, s2, i + split, j, len - split))
                return memo[key] = true;
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        return solve(s1, s2, 0, 0, s1.size());
    }
};