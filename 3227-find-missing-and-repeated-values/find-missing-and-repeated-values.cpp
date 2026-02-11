class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        vector<int>q;
        vector<int>a;

        int val=1;
        for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++)
           {
            mp[grid[i][j]]++;
                q.push_back(grid[i][j]);
                val++;

           }
        }
            int repeated = -1, missing = -1;
int n = grid.size();
        for(int i = 1; i <= n*n; i++){
            if(mp[i] == 0)
                missing = i;
            else if(mp[i] > 1)
                repeated = i;
        }

        return {repeated, missing};
    }
};