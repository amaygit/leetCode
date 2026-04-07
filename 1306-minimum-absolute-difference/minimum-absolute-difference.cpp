class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int mn = INT_MAX;
        vector<vector<int>> ans;

        // Find minimum difference
        for (int i = 1; i < arr.size(); i++) {
            mn = min(mn, arr[i] - arr[i - 1]);
        }

        // Collect pairs
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == mn) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};