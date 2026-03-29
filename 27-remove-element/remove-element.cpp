class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        int indx=0;
        for(int i=0;i<nums.size();i++){
         if(nums[i]==val)
         continue;

        else if(nums[i]!=val){
        nums[indx]=nums[i];
        cnt++;
        }
        indx++;
        }
        return cnt;
    }
};