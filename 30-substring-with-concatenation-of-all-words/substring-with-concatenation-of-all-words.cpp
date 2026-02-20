class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int sLen = s.length();
        int wordCount = words.size();
        int wordLen = words[0].length();
        int totalWindowLen = wordCount * wordLen;

        if (sLen < totalWindowLen) return result;

        // Map of what we NEED
        unordered_map<string, int> targetMap;
        for (const string& w : words) targetMap[w]++;

        // Loop through each possible offset (0 to wordLen - 1)
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> windowMap;

            while (right + wordLen <= sLen) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (targetMap.count(word)) {
                    windowMap[word]++;
                    count++;

                    // If we have too many of 'word', shrink from left
                    while (windowMap[word] > targetMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Check if we found a match
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Invalid word: reset window and start after this word
                    windowMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};