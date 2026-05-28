class Solution {
public:
    int mySqrt(int x) {
       float m,n;
       long long k=0;
       if(x==1)
       return 1;
      
       long long low=0,high=x;
       while(low<=high){
        long long mid=low+(high-low)/2;
        if(mid*mid<=x)
        {
            k=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
       }
        return k;
    }
};