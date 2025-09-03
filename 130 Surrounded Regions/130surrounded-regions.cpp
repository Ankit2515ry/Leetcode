class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')q.push({i,0});
            if(board[i][m-1]=='O')q.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')q.push({0,i});
            if(board[n-1][i]=='O')q.push({n-1,i});
        }
        vector<pair<int,int>>d={{0,1},{0,-1},{1,0},{-1,0}};
        vector<pair<int,int>>idx;
        while(!q.empty()){
            auto [i,j]=q.front();
            board[i][j]='X';
            idx.push_back({i,j});
            q.pop();
            for(int k=0;k<4;k++){
                int x=i+d[k].first;
                int y=j+d[k].second;
                if(x<n&&x>=0&&y<m&&y>=0&&board[x][y]=='O'){
                    q.push({x,y});
                }
            }
        }
        for(auto &it:board){
            for(auto &i:it){
                i='X';
            }
        }
        for(auto &it:idx){
            cout<<it.first<<" "<<it.second<<endl;
            board[it.first][it.second]='O';
        }
        // int n = board.size();
        // int m = board[0].size();
        // queue<pair<int,int>> q;
        // for(int i=0;i<n;i++){
        //     if(board[i][0] == 'O') q.push({i,0});
        //     if(board[i][m-1] == 'O') q.push({i,m-1});
        // }
        // for(int j=0;j<m;j++){
        //     if(board[0][j] == 'O') q.push({0,j});
        //     if(board[n-1][j] == 'O') q.push({n-1,j});
        // }
        // vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
        // while(!q.empty()){
        //     auto [i,j] = q.front(); q.pop();
        //     if(i<0 || j<0 || i>=n || j>=m || board[i][j] != 'O') continue;
        //     board[i][j] = 'A'; 
        //     for(auto [dx,dy] : d){
        //         q.push({i+dx,j+dy});
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(board[i][j] == 'O') board[i][j] = 'X'; 
        //         else if(board[i][j] == 'A') board[i][j] = 'O'; 
        //     }
        // }
    }
};