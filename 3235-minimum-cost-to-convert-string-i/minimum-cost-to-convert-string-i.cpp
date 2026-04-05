class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // Step 1: initialize
        for(int i = 0; i < 26; i++)
            dist[i][i] = 0;

        // Step 2: direct edges
        for(int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Step 3: Floyd-Warshall
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j],
                                         dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 4: calculate answer
        long long ans = 0;

        for(int i = 0; i < source.size(); i++) {
            if(source[i] == target[i]) continue;

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(dist[u][v] == INF)
                return -1;

            ans += dist[u][v];
        }

        return ans;
    }
};