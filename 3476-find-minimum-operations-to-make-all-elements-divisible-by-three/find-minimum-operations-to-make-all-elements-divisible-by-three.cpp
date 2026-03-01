class Solution {
public:
int calc(vector<int>& nums,int n){
    if(n==-1){
        return 0;
    }
    if(nums[n]%3!=0)
    return 1+calc(nums,n-1);
    else
      return calc(nums,n-1);
}
    int minimumOperations(vector<int>& nums) {
        return calc(nums,nums.size()-1);
    
    }
};