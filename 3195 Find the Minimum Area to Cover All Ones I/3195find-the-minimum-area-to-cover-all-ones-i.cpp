class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            bool f=true;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    f=false;
                    break;
                }
            }
            if(f)x++;
            else break;
        }
        for(int i=n-1;i>=0;i--){
            bool f=true;
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]==1){
                    f=false;
                    break;
                }
            }
            if(f)x++;
            else break;
        }
        for(int j=0;j<m;j++){
            bool f=true;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    f=false;
                    break;
                }
            }
            if(f)y++;
            else break;
        }
        for(int j=m-1;j>=0;j--){
            bool f=true;
            for(int i=n-1;i>=0;i--){
                if(grid[i][j]==1){
                    f=false;
                    break;
                }
            }
            if(f)y++;
            else break;
        }
        int res=(n-x)*(m-y);
        return res;
    }
};