class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";

        // We already have n=1, so we loop n-1 times
        for (int i = 1; i < n; i++) {
            string temp = "";
            int count = 1;

            for (int j = 0; j < res.length(); j++) {
                // Check if the next character is the same
                if (j + 1 < res.length() && res[j] == res[j + 1]) {
                    count++;
                } else {
                    // If different, "say" the count and the digit
                    temp += to_string(count) + res[j];
                    count = 1; // Reset count for the next digit
                }
            }
            res = temp;
        }

        return res;
    }
};