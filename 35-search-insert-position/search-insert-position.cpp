class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st=0,end=nums.size()-1;
        bool flag=false,temp=true;
        while(st<=end){
            int mid=st+(end-st)/2;

            if(nums[mid]==target){
                return mid;
              
                break;
            }
            else if(nums[mid]<target){
            st=mid+1;

            }

            else{
            end=mid-1;
       
            }
        }
        return st;
      
    }
};