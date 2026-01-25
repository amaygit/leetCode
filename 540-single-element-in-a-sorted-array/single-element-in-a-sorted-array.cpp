class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
    return nums[0];
    if (nums[0] != nums[1])
            return nums[0];
        int ans=0;
      int st=1,end=nums.size()-1,freq=0,flag=true;
      while(st<=end){
        int mid=(st+end)/2;
        if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid])
        return nums[mid];
        if(mid%2==0){
            if(nums[mid]==nums[mid+1])
            st=mid+1;
            else
            end=mid-1;
            }

        else{
            if(nums[mid]==nums[mid+1])
            end=mid-1;
            else
            st=mid+1;
                
            }
      }
            return -1;

        
      
      
    
    }
};