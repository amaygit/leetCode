class Solution {
public:
    int longestPalindrome(string s) {
        //sort(s.begin(),s.end());
       vector<bool> used(s.length(), false);
   vector<char>v(s.length());
   int len=0;
   int st=0,end=s.length()-1;
for(int i=0;i<s.length();i++){
    for(int j=i+1;j<s.length();j++){
        if(s[i]==s[j] && !used[i] && !used[j] && st<end){
            v[st]=s[i];
            v[end]=s[j];
            st++;
            end--;
            used[i] = used[j] = true;
        }
    }
}
for(int i=0;i<s.length();i++){
    if(!used[i] && st<=end){
        v[st]=s[i];
        break;
    }
}

//int len=0;

for(auto p:v){
    if(p!='\0'){
        cout<<p<<" ";
        len++;
    }
}

return len;
    }
};