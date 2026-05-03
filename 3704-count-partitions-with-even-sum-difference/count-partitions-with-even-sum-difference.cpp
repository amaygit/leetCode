class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt=0,sum1=0,sum2=0;
        for(int i=0;i<nums.size();i++){
             sum1+=nums[i];//10 10
            for(int j=i+1;j<nums.size();j++){
                sum2+=nums[j];//26 16
              
            }
              if((sum2-sum1)%2==0 && sum2!=0)
                    cnt+=1;
                    sum2=0;
        }
        return cnt;
    }
};