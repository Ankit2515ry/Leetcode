class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& ss) {
        vector<vector<int>> res(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        queue<tuple<int, int, int, int>> q;
        for (auto it : ss) {
            int i = it[0];
            int j = it[1];
            int col = it[2];
            q.push({i, j, col, 0});
            vis[i][j] = 0;
            res[i][j] = col;
        }
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        while (!q.empty()) {
            int c = q.size();
            auto [i, j, col, d] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                    continue;
                if (vis[xx][yy] > d + 1) {
                    vis[xx][yy] = d + 1;
                    res[xx][yy] = col;
                    q.push({xx, yy, col, d + 1});
                } else if (vis[xx][yy] == d + 1 && res[xx][yy] < col) {
                    res[xx][yy] = col;
                    q.push({xx, yy, col, d + 1});
                }
            }
        }
        return res;
    }
};