class Solution {
public:
    void calc(vector<int>&nums,    set<vector<int>>& ans,vector<int>&temp,int i){

    
        if(i == nums.size()){
            ans.insert(temp);   // insert full subset
            return;
        }

        temp.push_back(nums[i]);
        calc(nums, ans, temp, i+1);

        temp.pop_back();
        calc(nums, ans, temp, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int>temp;
        calc(nums,ans,temp,0);
        return  vector<vector<int>>(ans.begin(),ans.end());

    }
};