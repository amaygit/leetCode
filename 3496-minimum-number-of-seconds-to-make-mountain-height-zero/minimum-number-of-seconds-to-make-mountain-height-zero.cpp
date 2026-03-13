class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long left = 1, right = 1e16;
        long long ans = right;

        auto can = [&](long long t){
            long long total = 0;

            for(int wt : workerTimes){
                long long h = (sqrt(1.0 + 8.0*t/wt) - 1) / 2;
                total += h;
                if(total >= mountainHeight) return true;
            }

            return false;
        };

        while(left <= right){
            long long mid = (left + right) / 2;

            if(can(mid)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
};