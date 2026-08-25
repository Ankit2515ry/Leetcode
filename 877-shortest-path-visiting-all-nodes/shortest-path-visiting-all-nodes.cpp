class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>((1<<n),false));
        for(int i=0;i<n;i++){
            vis[i][(1<<i)]=true;
            q.push({i,(1<<i)});
        }
        int res=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [u,mask]=q.front();
                q.pop();
                if(mask==(1<<n)-1)return res;
                for(auto v:graph[u]){
                    int nm=mask|(1<<v);
                    if(!vis[v][nm]){
                        vis[v][nm]=true;
                        q.push({v,nm});
                    }
                }
            }
            res++;
        }
        return 0;
    }
};