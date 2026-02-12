class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int st = 1;
        int end = nums.size() - 1;

        while(st < end) {
            int mid = st + (end - st) / 2;
            
            int count = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] <= mid)
                    count++;
            }

            if(count > mid)
                end = mid;       // duplicate in left half
            else
                st = mid + 1;    // duplicate in right half
        }

        return st;
    }
};