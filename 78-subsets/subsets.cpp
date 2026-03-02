class Solution {
public:
    void calc(vector<int>&nums, vector<vector<int>>&ans,vector<int>&temp,int i){

        if(i==nums.size()){
        ans.push_back(temp);
        return;
        }
        temp.push_back(nums[i]);
         calc(nums,ans,temp,i+1);
          temp.pop_back();
         calc(nums,ans,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
         calc(nums,ans,temp,0);
         return ans;
    }
};