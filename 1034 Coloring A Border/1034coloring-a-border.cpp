class Solution {
public:
    int n, m;
    int pre;
    vector<vector<int>> vis;
    vector<pair<int,int>> border;

    void dfs(vector<vector<int>>& grid, int i, int j) {
        vis[i][j] = 1;
        int count = 0;
        vector<int> x = {1, -1, 0, 0};
        vector<int> y = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int xx = i + x[k];
            int yy = j + y[k];
            if (xx >= 0 && yy >= 0 && xx < n && yy < m && grid[xx][yy] == pre) {
                count++;
                if (!vis[xx][yy]) dfs(grid, xx, yy);
            }
        }

        if (count < 4) border.push_back({i, j});
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size();
        m = grid[0].size();
        pre = grid[row][col];
        vis.assign(n, vector<int>(m, 0));

        dfs(grid, row, col);

        for (auto [i, j] : border) grid[i][j] = color;
        return grid;
    }
};
