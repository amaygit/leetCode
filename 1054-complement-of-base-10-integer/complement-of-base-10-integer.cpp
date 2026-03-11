class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
           string ans="";
   while(n!=0){
    int m=n%2;
    ans+=to_string(m);
    n/=2;
   }   
   reverse(ans.begin(), ans.end());
   string res="";
   for(int i=0;i<ans.length();i++)
   {
    if(ans[i]=='0'){
        res+='1';
    }
    else{
        res+='0';
    }
   }
  
   //   n=stoi(res);
   int i=0;
   int k=0;
  // cout<<n;
    for(int j=res.length()-1;j>=0;j--){
            k += (res[j]-'0') * pow(2,i);
            i++;
        }
   return k;
 
    }
};