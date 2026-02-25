class Solution {
public:
    int fib(int n) {
        if(n==1 || n==0)
        return n;
        long long prev=0,current=1,ans=0;
        for(int i=2;i<=n;i++){
                ans=prev+current;
                prev=current;
                current=ans;
        }
        return ans;
    }
};