class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        int occuraance=-1;
        string temp="";        
        for(int i=0;i<haystack.length();i++){
               temp+=haystack[i];
              if(temp.length()>needle.length()){
             temp= temp.substr(1);
            }
        
            if(temp==needle){
            return i - needle.length() + 1;
            }
          
        }
        // if(occuraance>=0)
        // return occuraance-needle.length()+1;
        return -1;
    }
};