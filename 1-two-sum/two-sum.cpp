class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> arr;
        for(int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i}); // value, original index
        }

        sort(arr.begin(), arr.end());

        int st = 0, end = arr.size() - 1;

        while(st < end) {
            int sum = arr[st].first + arr[end].first;

            if(sum == target) {
                return {arr[st].second, arr[end].second};
            }
            else if(sum < target) {
                st++;
            }
            else {
                end--;
            }
        }
        return {};
    }
};
