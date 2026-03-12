class DSU {
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;

        if(rank[a]<rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
        return true;
    }
};

class Solution {
public:

bool can(int n, vector<vector<int>>& edges, int k, int target){

    DSU dsu(n);
    int upgrades=0;
    int used=0;

    vector<vector<int>> optional;

    for(auto &e:edges){
        int u=e[0],v=e[1],s=e[2],must=e[3];

      if(must){
    if(s < target) return false;

    if(!dsu.unite(u,v)) 
        return false;   // cycle among mandatory edges

    used++;
}else{
            optional.push_back(e);
        }
    }

    for(auto &e:optional){
        int u=e[0],v=e[1],s=e[2];

        if(s>=target){
            if(dsu.unite(u,v)) used++;
        }
    }

    for(auto &e:optional){
        int u=e[0],v=e[1],s=e[2];

        if(s<target && s*2>=target){
            if(upgrades<k && dsu.unite(u,v)){
                upgrades++;
                used++;
            }
        }
    }

    return used==n-1;
}

int maxStability(int n, vector<vector<int>>& edges, int k){

    int l=1,r=2e5,ans=-1;

    while(l<=r){
        int mid=(l+r)/2;

        if(can(n,edges,k,mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    return ans;
}
};