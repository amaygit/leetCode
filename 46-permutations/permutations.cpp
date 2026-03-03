class Solution {
public:
void calc(vector<int>&nums,vector<vector<int>> &ans,int indx){
    if(indx==nums.size()){
        ans.push_back(nums);
    }
    for(int i=indx;i<nums.size();i++){
        swap(nums[i],nums[indx]);
        calc(nums,ans,indx+1);
        swap(nums[i],nums[indx]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        calc(nums,ans,0);
        return ans;
    }
};