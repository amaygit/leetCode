class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> nums2;

        sort(nums.begin(), nums.end());

        nums2.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1])
                nums2.push_back(nums[i]);
        }

        if(nums2.size() < 3){
            return nums2.back();
        }

        return nums2[nums2.size() - 3]; 
    }
};