class Solution {
public:
bool check_bool(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
    bool validPalindrome(string s) {
       int i=0,j=s.length()-1;
       while(i<j){
        if(s[i]!=s[j]){
            return check_bool(s,i+1,j)|| check_bool(s,i,j-1);
        }
        i++;
        j--;
       }
       return true; 
    }
};