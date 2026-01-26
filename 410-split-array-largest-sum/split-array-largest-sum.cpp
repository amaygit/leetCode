class Solution {
public:
    bool canSplit(vector<int>& nums, int m, int maxSum) {
        int subarrays = 1;
        int currSum = 0;

        for (int x : nums) {
            if (currSum + x <= maxSum) {
                currSum += x;
            } else {
                subarrays++;
                currSum = x;
            }
        }

        return subarrays <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, m, mid))
                high = mid;   // try smaller max
            else
                low = mid + 1; // need larger max
        }

        return low;
    }
};
