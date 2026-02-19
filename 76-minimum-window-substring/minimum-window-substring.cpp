class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        vector<int> targetCount(128, 0);
        for (char c : t) targetCount[c]++;

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIdx = 0;
        int need = 0; // Number of unique chars in T with non-zero freq
        for(int i : targetCount) if(i > 0) need++;
        
        int have = 0;
        vector<int> windowCount(128, 0);

        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;

            // If this char is needed and we reached the required count
            if (targetCount[c] > 0 && windowCount[c] == targetCount[c]) {
                have++;
            }

            // Shrink from the left while the window is valid
            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                windowCount[leftChar]--;
                
                // If removing this char makes the window invalid
                if (targetCount[leftChar] > 0 && windowCount[leftChar] < targetCount[leftChar]) {
                    have--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};