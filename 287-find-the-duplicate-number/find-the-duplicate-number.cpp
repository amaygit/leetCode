class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int>s;
        int num=0;
       for(int i=0;i<=nums.size();i++){
        if(s.find(nums[i])!=s.end()){
            num=nums[i];
            break;
        }
        s.insert(nums[i]);
       }
       return num;
    }
};