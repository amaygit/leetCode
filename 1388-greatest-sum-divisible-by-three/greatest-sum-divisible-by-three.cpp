class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
    //     int sum=0;
    //     int mx=0;
    //     for(int i=0;i<nums.size();i++){
    //         sum+=nums[i];
    //         if(sum%3==0)
    //         mx=max(mx,sum);
    //     }
    // return mx;
      int sum = 0;

        int r1a = 1e9, r1b = 1e9;
        int r2a = 1e9, r2b = 1e9; 
        for (int x : nums) {
            sum += x;

            if (x % 3 == 1) {
                if (x < r1a) {
                    r1b = r1a;
                    r1a = x;
                } else if (x < r1b) {
                    r1b = x;
                }
            }

            else if (x % 3 == 2) {
                if (x < r2a) {
                    r2b = r2a;
                    r2a = x;
                } else if (x < r2b) {
                    r2b = x;
                }
            }
        }

        if (sum % 3 == 0) return sum;

        if (sum % 3 == 1) {
            return max(sum - r1a, sum - r2a - r2b);
        } else {
            return max(sum - r2a, sum - r1a - r1b);
        }
    }
};