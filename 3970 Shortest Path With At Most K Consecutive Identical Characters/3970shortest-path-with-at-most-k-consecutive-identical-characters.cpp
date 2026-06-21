class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,1});
        vector<vector<int>>dist(n,vector<int>(k+1,1e9));
        dist[0][1]=0;
        while(!pq.empty()){
            auto [d,u,c]=pq.top();
            pq.pop();
            if(d>dist[u][c])continue;
            if(u==n-1)return d;
            for(auto it:adj[u]){
                int v=it.first;
                int w=it.second;
                int nc=(labels[v]==labels[u])?c+1:1;
                if(nc<=k&&d+w<dist[v][nc]){
                    dist[v][nc]=d+w;
                    pq.push({d+w,v,nc});
                }
            }
        }
        int res=1e9;
        for(int c=1;c<=k;c++){
            res=min(res,dist[n-1][c]);
        }
        return (res==1e9)?-1:res;
    }
};