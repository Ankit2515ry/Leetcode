class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int res=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n;i++){
            int v=heightMap[i][0];
            pq.push({v,{i,0}});
            v=heightMap[i][m-1];
            pq.push({v,{i,m-1}});
            vis[i][0]=0;
            vis[i][m-1]=0;
        }
        for(int j=1;j<m-1;j++){
            int v=heightMap[0][j];
            pq.push({v,{0,j}});
            v=heightMap[n-1][j];
            pq.push({v,{n-1,j}});
            vis[0][j]=0;
            vis[n-1][j]=0;
        }
        vector<pair<int,int>>d={{0,1},{1,0},{0,-1},{-1,0}};
        while(!pq.empty()){
            int v=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(auto it:d){
                int ni=i+it.first;
                int nj=j+it.second;
                if(ni>0&&ni<n&&nj>0&&nj<m&&vis[ni][nj]==-1){
                    int nv=heightMap[ni][nj];
                    if(nv<v){
                        res+=v-nv;
                        pq.push({v,{ni,nj}});
                        vis[ni][nj]=0;
                    }else{
                        pq.push({nv,{ni,nj}});
                        vis[ni][nj]=0;
                    }
                }
            }
        }
        return res;
    }
};