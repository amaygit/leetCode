class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total = 0;
        int maxTime = 0;

        for (int i = 0; i < colors.size(); i++) {
            if (i > 0 && colors[i] != colors[i-1]) {
                maxTime = 0; // reset for new group
            }

            total += min(maxTime, neededTime[i]);
            maxTime = max(maxTime, neededTime[i]);
        }

        return total;
    }
};