class Solution {
public:
    void dfs(int i,vector<int>&vis, vector<vector<int>>&adj){
        vis[i]=0;
        for(auto &it:adj[i]){
            if(vis[it]==-1){
                dfs(it,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        int m=c.size();
        if(m<n-1)return -1;
        vector<vector<int>>adj(n);
        for(auto &it:c){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,-1);
        int discon=-1;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                discon++;
                dfs(i,vis,adj);
            }
        }
        return discon;
    }
};