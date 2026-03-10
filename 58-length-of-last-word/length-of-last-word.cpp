class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        string k="";
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
             if(k!="" && length>0 && s[i]==' ')
            break;
           else if(s[i]==' '){
                continue;
            }
            else{
                k+=s[i];
                length++;
            }
          
        }
        return length;
    }
};