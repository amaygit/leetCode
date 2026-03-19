class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);  // stores last index of each char

        int l = 0;
        int maxLen = 0;

        for(int r = 0; r < s.length(); r++){
            if(last[s[r]] != -1){
                l = max(l, last[s[r]] + 1);
            }

            last[s[r]] = r;

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};