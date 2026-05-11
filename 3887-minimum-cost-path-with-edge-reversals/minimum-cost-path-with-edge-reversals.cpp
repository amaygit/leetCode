class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            // original edge
            adj[u].push_back({v, w});

            // reversed edge
            adj[v].push_back({u, 2 * w});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto &[nbr, wt] : adj[node]) {

                if (dist[node] + wt < dist[nbr]) {

                    dist[nbr] = dist[node] + wt;

                    pq.push({dist[nbr], nbr});
                }
            }
        }

        return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
    }
};