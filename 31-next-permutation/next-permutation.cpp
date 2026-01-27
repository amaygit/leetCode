class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot=-1,index=-1;;
      
        int st=0,end=nums.size()-1;
        if(nums.size()==2)
        {
            swap(nums[0],nums[1]);
            return;
        }
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                pivot=nums[i-1];
               
                index=i-1;
                break;
            }
        }
        if(index==-1){
        reverse(nums.begin(),nums.end());
        return ;
        }
        for(int i=nums.size()-1;i>0;i--){
            if(pivot<nums[i]){
                swap(nums[i],nums[index]);
                break;
            }
        }
            reverse(nums.begin()+index+1,nums.end());
        

        
            


        
    }
};