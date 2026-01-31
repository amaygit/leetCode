class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            string word="";
           // int indx=i;
            while(s[i]!=' ' && i<s.length())
            {
                word+=s[i];i++;

            }
            reverse(word.begin(),word.end());
            if(word.length()>0)
            ans+=' '+word;
        }
        return ans.substr(1);
    }
};