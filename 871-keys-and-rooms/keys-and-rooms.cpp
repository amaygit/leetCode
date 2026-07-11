class Solution {
public:
    void dfs(int node,vector<vector<int>>& rooms , vector<int>&visited){
        
        visited[node]=1;
         for (auto i : rooms[node]) {
            if(visited[i]==0)
            dfs(i,rooms,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);

        dfs(0,rooms,visited);
        for(int i=0;i<n;i++){
            if(visited[i]==0)
            return false;
        }
        return true;
    }
};