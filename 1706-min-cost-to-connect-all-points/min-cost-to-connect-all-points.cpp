class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res=0;
        int n=points.size();
        vector<int>vis(n,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()&&n>0){
            auto [c,u]=pq.top();
            pq.pop();
            if(vis[u]!=-1)continue;
            vis[u]=0;
            res+=c;
            for(int i=0;i<points.size();i++){
                //if(vis[i]!=-1)continue;
                int d=abs(points[i][0]-points[u][0])+abs(points[i][1]-points[u][1]);
                pq.push({d,i});
            }
            n--;
        }
        return res;
    }
};