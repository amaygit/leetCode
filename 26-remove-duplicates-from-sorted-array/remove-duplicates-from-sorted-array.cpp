class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         if (nums.size() == 0) return 0;
        int k=1;
        vector<int>p;
        p.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1])
            {
                p.push_back(nums[i]);
                k++;
            }
           
        }
        nums.erase(nums.begin(),nums.end());
       for(auto q:p){
        nums.push_back(q);
       }
        return k;
    }
};