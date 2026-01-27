class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indx = -1;

        // 1️⃣ Find the pivot (first decreasing element from right)
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                indx = i;
                break;
            }
        }

        // 2️⃣ If no pivot found → array is in descending order
        if(indx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 3️⃣ Find element just greater than pivot
        for(int i = n - 1; i > indx; i--) {
            if(nums[i] > nums[indx]) {
                swap(nums[i], nums[indx]);
                break;
            }
        }

        // 4️⃣ Reverse the right side
        reverse(nums.begin() + indx + 1, nums.end());
    }
};
