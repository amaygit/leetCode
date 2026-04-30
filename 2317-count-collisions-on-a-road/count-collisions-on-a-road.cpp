class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        
        int l = 0, r = n - 1;
        
        // skip leading L
        while (l < n && directions[l] == 'L') l++;
        
        // skip trailing R
        while (r >= 0 && directions[r] == 'R') r--;
        
        int ans = 0;
        
        for (int i = l; i <= r; i++) {
            if (directions[i] != 'S') ans++;
        }
        
        return ans;
    }
};