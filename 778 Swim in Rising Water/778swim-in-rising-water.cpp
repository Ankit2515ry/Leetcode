class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<int>x={0,0,1,-1};
        vector<int>y={1,-1,0,0};
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        while(!pq.empty()){
            auto [d,p]=pq.top();
            auto [i,j]=p;
            pq.pop();
            if(i==n-1&&j==n-1)return d;
            for(int k=0;k<4;k++){
                int ni=i+x[k];
                int nj=j+y[k];
                if(ni>=0&&ni<n&&nj>=0&&nj<n){
                    int nd=max(d,grid[ni][nj]);
                    if(dist[ni][nj]>nd){
                        dist[ni][nj]=nd;
                        pq.push({nd,{ni,nj}});
                    }
                }
            }
        }
        return grid[0][0];
    }
};