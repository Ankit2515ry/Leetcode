class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>&vis,int i,int j){
        vis[i][j]=0;
        if(i+1<board.size()&&j<board[0].size()&&board[i+1][j]=='X'&&vis[i+1][j]==-1)dfs(board,vis,i+1,j);
        if(i<board.size()&&j+1<board[0].size()&&board[i][j+1]=='X'&&vis[i][j+1]==-1)dfs(board,vis,i,j+1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int res=0;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'&&vis[i][j]==-1){
                    res++;
                    dfs(board,vis,i,j);
                }
            }
        }
        return res;
        // int n = board.size(), m = board[0].size();
        // int count = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (board[i][j] == 'X') {
        //             if ((i == 0 || board[i-1][j] != 'X') && 
        //                 (j == 0 || board[i][j-1] != 'X')) {
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;
    }
};