class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        vector<int> order;

        // find path start (degree 1), else cycle start 0
        int start = 0;
        for(int i=0;i<n;i++){
            if(deg[i]==1){
                start=i;
                break;
            }
        }

        // build node order
        vector<int> vis(n,0);
        int cur=start, prev=-1;

        while(true){
            order.push_back(cur);
            vis[cur]=1;

            int nxt=-1;
            for(int nei: adj[cur]){
                if(nei!=prev && !vis[nei]){
                    nxt=nei;
                    break;
                }
            }

            if(nxt==-1) break;
            prev=cur;
            cur=nxt;
        }

        // assign largest numbers to middle positions
        vector<int> vals(n);
        int l=(n-1)/2, r=l+1;
        int num=n;

        vals[l]=num--;
        while(num){
            if(r<n) vals[r++]=num--;
            if(num && l>0) vals[--l]=num--;
        }

        vector<int> nodeVal(n);
        for(int i=0;i<n;i++) nodeVal[order[i]]=vals[i];

        long long ans=0;
        for(auto &e: edges){
            ans += 1LL * nodeVal[e[0]] * nodeVal[e[1]];
        }

        return ans;
    }
};