class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int frq=0,ans;
        for(auto ele:nums){
            if(frq==0)
                ans=ele;
            if(ans==ele)
                frq++;
            else
                frq--;
        }
    return ans;
    }
};