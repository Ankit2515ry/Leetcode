class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>que;
        int fresh=0;
        int rot=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)que.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        }
        rot-=que.size();
        int min=0;
        while(!que.empty()){
            int k=que.size();
            min++;
            while(k--){
                int x=que.front().first;
                int y=que.front().second;
                que.pop();
                rot++;
                vector<pair<int,int>>dir={{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
                for(auto it:dir){
                    int xn=it.first;
                    int yn=it.second;
                    if(xn>=0&&xn<grid.size()&&yn>=0&&yn<grid[0].size()&&grid[xn][yn]==1){
                        grid[xn][yn]=2;
                        que.push({xn,yn});
                    }
                }
            }
        }
        if(rot!=fresh)return -1;
        if(min==0)return 0;
        return min-1;
    }
};