class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0;      // starting index of best palindrome
        int maxLen = 1;     // length of best palindrome

        for (int i = 0; i < n; i++) {

            // -------- ODD length palindrome --------
            int L = i, R = i;
            while (L >= 0 && R < n && s[L] == s[R]) {
                if (R - L + 1 > maxLen) {
                    start = L;
                    maxLen = R - L + 1;
                }
                L--;
                R++;
            }

            // -------- EVEN length palindrome --------
            L = i;
            R = i + 1;
            while (L >= 0 && R < n && s[L] == s[R]) {
                if (R - L + 1 > maxLen) {
                    start = L;
                    maxLen = R - L + 1;
                }
                L--;
                R++;
            }
        }

        return s.substr(start, maxLen);
    }
};
