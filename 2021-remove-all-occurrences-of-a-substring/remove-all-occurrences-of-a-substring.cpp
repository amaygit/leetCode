class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res="";
            while(s.find(part)<=s.length() && s.length()>0){
                s.erase(s.find(part),part.size());
            }
    return s;
    }
};