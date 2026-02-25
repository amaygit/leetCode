class Solution {
public:
    int myFunc(vector<int>& nums, int target,int st,int end){
        if(st>end)
        return -1;
           int mid=st+(end-st)/2;
        if(nums[mid]==target)
        return mid;
        else if(nums[mid]<target)
        return myFunc(nums,target,mid+1,end);
        else
        return myFunc(nums,target,st,mid-1);
    }
    int search(vector<int>& nums, int target) {
     return myFunc(nums,target,0,nums.size()-1);
    }
};