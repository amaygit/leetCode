class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int num=INT_MIN;
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==original || num==nums[i]){
                num=nums[i]*2;
                flag=false;
            }
        }
        if(!flag)
        return num;
        return original;
    }
};