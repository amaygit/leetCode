class Solution {
public:

    int minCost(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        using T = tuple<long long,int,int,int>;
        // cost, row, col, usedTeleport

        vector<tuple<int,int,int>> cells;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end());

        vector<vector<vector<long long>>> dist(
            m,
            vector<vector<long long>>(n, vector<long long>(k+1, LLONG_MAX))
        );

        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0][0] = 0;

        pq.push({0,0,0,0});

        vector<int> ptr(k+1, 0);

        while(!pq.empty()) {

            auto [cost, r, c, used] = pq.top();
            pq.pop();

            if(cost > dist[r][c][used])
                continue;

            if(r == m-1 && c == n-1)
                return cost;

            // move down
            if(r+1 < m) {

                long long nc = cost + grid[r+1][c];

                if(nc < dist[r+1][c][used]) {

                    dist[r+1][c][used] = nc;

                    pq.push({nc, r+1, c, used});
                }
            }

            // move right
            if(c+1 < n) {

                long long nc = cost + grid[r][c+1];

                if(nc < dist[r][c+1][used]) {

                    dist[r][c+1][used] = nc;

                    pq.push({nc, r, c+1, used});
                }
            }

            // teleport
            if(used < k) {

                while(ptr[used] < cells.size() &&
                      get<0>(cells[ptr[used]]) <= grid[r][c]) {

                    auto [val, nr, nc] = cells[ptr[used]];

                    if(cost < dist[nr][nc][used+1]) {

                        dist[nr][nc][used+1] = cost;

                        pq.push({cost, nr, nc, used+1});
                    }

                    ptr[used]++;
                }
            }
        }

        return -1;
    }
};