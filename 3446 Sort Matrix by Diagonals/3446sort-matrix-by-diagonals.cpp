class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        for(int i=1;i<m;i++){
            vector<int>temp;
            int k=i;
            int j=0;
            while(k<m){
                temp.push_back(grid[j][k]);
                k++;
                j++;
            }
            sort(temp.begin(),temp.end());
            k=i;
            j=0;
            int p=0;
            while(k<m){
                res[j][k]=temp[p];
                k++;
                j++;
                p++;
            }
        }
        for(int i=n-1;i>=0;i--){
            vector<int>temp;
            int k=i;
            int j=0;
            while(k<n){
                temp.push_back(grid[k][j]);
                k++;
                j++;
            }
            sort(temp.begin(),temp.end());
            reverse(temp.begin(),temp.end());
            k=i;
            j=0;
            int p=0;
            while(k<n){
                res[k][j]=temp[p];
                k++;
                j++;
                p++;
            }
        }
        return res;
    }
};