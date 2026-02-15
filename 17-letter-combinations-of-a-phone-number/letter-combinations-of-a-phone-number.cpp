class Solution {
public:
    void backtrack(string digits, int index, string current, vector<string>& result, vector<string>& mapping) {
        // Base case: If the combination is done
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get letters for the current digit (e.g., '2' -> "abc")
        string letters = mapping[digits[index] - '0'];

        for (char letter : letters) {
            // 1. Add the letter
            current.push_back(letter);
            // 2. Move to the next digit
            backtrack(digits, index + 1, current, result, mapping);
            // 3. Backtrack: remove the letter so we can try the next one
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, 0, "", result, mapping);
        return result;
    }
};