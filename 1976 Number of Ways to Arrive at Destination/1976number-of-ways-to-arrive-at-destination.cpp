class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:roads){
            int v=it[0];
            int u=it[1];
            int w=it[2];
            adj[v].push_back({u,w});
            adj[u].push_back({v,w});
        }
        vector<int>ways(n,0);
        vector<long long>dis(n,LLONG_MAX);
        ways[0]=1;
        dis[0]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            long long d=p.first;
            int u=p.second;
            if(d>dis[u])continue;
            for(auto &it:adj[u]){
                long long nd=d+it.second;
                if(nd<dis[it.first]){
                    dis[it.first]=nd;
                    ways[it.first]=ways[u];
                    pq.push({nd,it.first});
                }else if(nd==dis[it.first]){
                    ways[it.first]=(ways[it.first]+ways[u])%mod;
                }
            }
        }
        return ways[n-1];
    }
};