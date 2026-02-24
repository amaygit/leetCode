class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int first=0;
       for(int i=0;i<nums.size();i++){
         first+=nums[i];
        int second=first-k;
        if(mp.find(second)!=mp.end()){
            c += mp[second];
        }
        mp[first]++;
       }
       return c;
    }
};