class Solution {
public:
    vector<string> ans;

    void solve(string digits, int idx, string curr,
               vector<string>& mp) {

        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for (char ch : letters) {
            solve(digits, idx + 1, curr + ch, mp);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(digits, 0, "", mp);

        return ans;
    }
};