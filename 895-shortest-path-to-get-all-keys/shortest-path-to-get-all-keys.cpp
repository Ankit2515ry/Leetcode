class Solution {
public:
    int n;
    int m;
    vector<pair<int,int>>d={{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<vector<int>>>vis;
    int tm=0;
    int res=1e9;
    void solve(vector<string>& grid,int i,int j,int mask,int step){
        if(step>=vis[i][j][mask]||step>res)return;
        vis[i][j][mask]=step;
        if(mask==tm){
            res=min(res,step);
            return;
        }
        for(auto [x,y]:d){
            int ni=i+x;
            int nj=j+y;
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&grid[ni][nj]!='#'){
                if(grid[ni][nj]>='A'&&grid[ni][nj]<='Z'){
                    int val=grid[ni][nj]-'A';
                    if((mask>>val)&1){
                        solve(grid,ni,nj,mask,step+1);
                    }
                }
                else if(grid[ni][nj]>='a'&&grid[ni][nj]<='z'){
                    int val=grid[ni][nj]-'a';
                    solve(grid,ni,nj,mask|(1<<val),step+1);
                }
                else{
                    solve(grid,ni,nj,mask,step+1);
                }
            }
        }
    }
    int shortestPathAllKeys(vector<string>& grid) {
        n=grid.size();
        m=grid[0].size();
        vis.assign(n,vector<vector<int>>(m,vector<int>(64,1e9)));
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    x=i;
                    y=j;
                }
                if(grid[i][j]>='a'&&grid[i][j]<='z'){
                    int val=grid[i][j]-'a';
                    tm|=(1<<val);
                }
            }
        }
        solve(grid,x,y,0,0);
        if(res>=1e9)return -1;
        return res;
    }
};
// class Solution {
// public:
//     int shortestPathAllKeys(vector<string>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         int startX = 0, startY = 0;
//         int tm = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == '@') {
//                     startX = i;
//                     startY = j;
//                 }
//                 if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
//                     int val = grid[i][j] - 'a';
//                     tm |= (1 << val);
//                 }
//             }
//         }

//         // queue stores: {row, col, mask}
//         queue<tuple<int, int, int>> q;
//         vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(64, false)));

//         q.push({startX, startY, 0});
//         vis[startX][startY][0] = true;

//         int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//         int steps = 0;

//         while (!q.empty()) {
//             int sz = q.size();
//             while (sz--) {
//                 auto [r, c, mask] = q.front();
//                 q.pop();

//                 if (mask == tm) return steps;

//                 for (auto& dir : d) {
//                     int nr = r + dir[0];
//                     int nc = c + dir[1];

//                     if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '#') {
//                         continue;
//                     }

//                     char ch = grid[nr][nc];
//                     int nextMask = mask;

//                     // Lock check
//                     if (ch >= 'A' && ch <= 'F') {
//                         int lockId = ch - 'A';
//                         if (!((mask >> lockId) & 1)) continue;
//                     }

//                     // Key pickup
//                     if (ch >= 'a' && ch <= 'f') {
//                         int keyId = ch - 'a';
//                         nextMask |= (1 << keyId);
//                     }

//                     if (!vis[nr][nc][nextMask]) {
//                         vis[nr][nc][nextMask] = true;
//                         q.push({nr, nc, nextMask});
//                     }
//                 }
//             }
//             steps++;
//         }

//         return -1;
//     }
// };