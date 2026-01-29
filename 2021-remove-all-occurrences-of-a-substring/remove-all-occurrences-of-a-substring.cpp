class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result="";
        for(int i=0;i<s.length();i++){
            result=result+s[i];
            if(result.size()>=part.size()&& result.substr(result.length()-part.length())==part)
            result.erase(result.end()-part.length(),result.end());
        }
    return result;
    }
};