class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;

        vector<vector<long long>> dist(26,
            vector<long long>(26, INF));

        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        int m = original.size();

        // direct edges
        for (int i = 0; i < m; i++) {

            int u = original[i] - 'a';
            int v = changed[i] - 'a';

            dist[u][v] = min(dist[u][v],
                             (long long)cost[i]);
        }

        // Floyd Warshall
        for (int via = 0; via < 26; via++) {

            for (int i = 0; i < 26; i++) {

                for (int j = 0; j < 26; j++) {

                    if (dist[i][via] == INF ||
                        dist[via][j] == INF)
                        continue;

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][via] + dist[via][j]
                    );
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < source.size(); i++) {

            if (source[i] == target[i])
                continue;

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (dist[u][v] == INF)
                return -1;

            ans += dist[u][v];
        }

        return ans;
    }
};