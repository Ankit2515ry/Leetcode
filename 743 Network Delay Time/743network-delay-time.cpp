class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:times){
            int u=it[0]-1;
            int v=it[1]-1;
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>dis(n,INT_MAX);
        dis[k-1]=0;
        priority_queue<pair<int ,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            for(auto [v,w]:adj[u]){
                if(dis[v]==INT_MAX||dis[v]>d+w){
                    pq.push({d+w,v});
                    dis[v]=d+w;
                }
            }
        }
        int maxdist=INT_MIN;
        for(auto &it:dis)maxdist=max(maxdist,it);
        if(maxdist==INT_MAX)return -1;
        return maxdist;
    }
};