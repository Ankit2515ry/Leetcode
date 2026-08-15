class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>f(n+1,INT_MAX);
        f[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int u=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            for(auto [v,nw]:adj[u]){
                if(f[v]==INT_MAX||f[v]>w+nw){
                    pq.push({w+nw,v});
                    f[v]=w+nw;
                }
            }
        }
        int res=INT_MIN;
        for(int i=1;i<=n;i++){
            if(f[i]==INT_MAX)return -1;
            res=max(res,f[i]);
        }
        return res;
    }
};