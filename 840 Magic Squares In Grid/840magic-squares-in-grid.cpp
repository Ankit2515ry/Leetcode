class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid){
        unordered_set<int>st;
        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                if(grid[x][y] < 1 || grid[x][y] > 9)return false;
                st.insert(grid[x][y]);
            }
        }
        if(st.size()!=9)return false;
        for(int x=i;x<i+3;x++){
            int sum=0;
            for(int y=j;y<j+3;y++){
                sum+=grid[x][y];
            }
            if(sum!=15)return false;
        }
        for(int y=j;y<j+3;y++){
            int sum=0;
            for(int x=i;x<i+3;x++){
                sum+=grid[x][y];
            }
            if(sum!=15)return false;
        }
        int x=i;
        int y=j;
        int sum=0;
        for(int k=0;k<3;k++){
            sum+=grid[x+k][y+k];
        }
        if(sum!=15)return false;
        x=i+2;
        y=j;
        sum=0;
        for(int k=0;k<3;k++){
            sum+=grid[x-k][y+k];
        }
        if(sum!=15)return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3 || grid[0].size() < 3) return 0;
        int res=0;
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[0].size()-2;j++){
                bool f=check(i,j,grid);
                if(f)res++;
            }
        }
        return res;
    }
};