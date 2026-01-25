class Solution {
public:
    int search(vector<int>& nums, int target) {
        int freq=0;
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                flag=true;
            break;
            }
            else
            flag=false;
            freq++;
        }
        if(!flag)
        return -1;
        return freq;
    }
};