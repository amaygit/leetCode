class Solution {
public:
    bool isPalindrome(int x) {
        long long digit=0,ele=1,orginal=x;
        if(x<0)
        return false;
        while(x!=0){
            ele=x%10;
            digit=digit*10+ele;
           x=x/10;
        }
        return orginal==digit;
    }
};