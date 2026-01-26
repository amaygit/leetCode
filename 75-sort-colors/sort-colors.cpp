class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>arr;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==0)
            arr.push_back(0);
       }
            for(int i=0;i<nums.size();i++){
        if(nums[i]==1)            
            arr.push_back(1);
            }
                 for(int i=0;i<nums.size();i++){
            if(nums[i]==2)
            arr.push_back(2);
                 }

       nums=arr;
       
     //  nums.clear();

      //  return nums;
    }
};