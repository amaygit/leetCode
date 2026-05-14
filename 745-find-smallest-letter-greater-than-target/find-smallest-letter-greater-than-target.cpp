class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        for(char ch : letters) {

            if(ch > target)
                return ch;
        }

        // wrap around
        return letters[0];
    }
};