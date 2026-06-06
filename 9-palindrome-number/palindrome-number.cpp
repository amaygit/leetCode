class Solution {
public:
    bool isPalindrome(int x) {
        long  long  y=0,c=0;
        if(x<0)
        return false;
          long j=x,k=x;
      while(k!=0){
          c++;
          k/=10;
      }
        while(x!=0){
          c--;
            y=(x%10)*pow(10,c)+y;
           
            x/=10;
        }
        if(j==y)
        return true;
        return false;
    }
};