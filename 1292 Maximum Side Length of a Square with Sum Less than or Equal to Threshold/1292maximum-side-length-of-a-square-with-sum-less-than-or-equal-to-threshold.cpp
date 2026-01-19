class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int t) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i+1][j+1] = pre[i][j+1] + pre[i+1][j] - pre[i][j] + mat[i][j];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x = i, y = j;
                while (x <= n && y <= m) {
                    int L = x - i + 1;
                    int sum =
                        pre[x][y] - pre[i-1][y] - pre[x][j-1] + pre[i-1][j-1];
                    if (sum <= t)
                        res = max(res, L);
                    x++;
                    y++;
                }
            }
        }
        return res;
    }
};
