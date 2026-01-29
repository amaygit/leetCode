class Solution {
public:
    bool isPalindrome(string s) {
        int st=0,end=s.length()-1;
        while(st<end){
            if((tolower(s[st]))==(tolower(s[end]))){
                st++;
                end--;
            }
            else if(!isalnum(s[st]))
            st++;
             else if(!isalnum(s[end]))
            end--;
            else
            return false;
        }
        return true;
    }
};