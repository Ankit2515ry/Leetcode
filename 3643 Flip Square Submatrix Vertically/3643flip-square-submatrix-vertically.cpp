class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int xn=x+k;
        int ym=y+k;
        for(int i=x;i<xn;i++){
            for(int j=y;j<ym;j++){
                int temp=grid[i][j];
                grid[i][j]=grid[xn-1][j];
                grid[xn-1][j]=temp;
            }
            xn--;
        }
        return grid;
    }
};