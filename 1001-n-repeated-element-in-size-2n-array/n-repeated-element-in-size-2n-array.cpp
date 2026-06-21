class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0,k=1,mx=INT_MIN,temp=0;
        for(int i=1;i<nums.size();i++){
           if (nums[i] == nums[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
           if(mx<cnt){
            mx=cnt;
            temp=nums[i];
           }
        }
        return temp;
    }
};