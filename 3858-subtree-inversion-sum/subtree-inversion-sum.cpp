class Solution {
public:
    vector<vector<int>> adj;
    vector<int> nums;
    int n, K;

    long long dp[50005][55][2];
    bool vis[50005][55][2];

    long long dfs(int node, int par, int dist, int inv) {
        if (vis[node][dist][inv]) return dp[node][dist][inv];
        vis[node][dist][inv] = true;

        long long val = inv ? -1LL * nums[node] : nums[node];

        // no invert
        long long best = val;
        for (int nei : adj[node]) {
            if (nei == par) continue;
            best += dfs(nei, node, min(K, dist + 1), inv);
        }

        // invert here
        if (dist >= K) {
            long long cur = -val;
            for (int nei : adj[node]) {
                if (nei == par) continue;
                cur += dfs(nei, node, 1, inv ^ 1);
            }
            best = max(best, cur);
        }

        return dp[node][dist][inv] = best;
    }

    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums_, int k) {
        nums = nums_;
        K = k;
        n = nums.size();

        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        memset(vis, 0, sizeof(vis));

        return dfs(0, -1, K, 0);
    }
};