class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        for(auto p:s){
            if(isalnum(p)){
                res+=(p);
            }
        }
 transform(res.begin(),res.end(),res.begin(),::tolower);
 string q=res;
 reverse(res.begin(),res.end());
    return (res==q)?true:false;
    }
};