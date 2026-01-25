class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0, end = arr.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] < arr[mid + 1])
                st = mid + 1;   // move toward peak
            else
                end = mid;      // peak is here or left
        }

        return st; // or end (same)
    }
};
