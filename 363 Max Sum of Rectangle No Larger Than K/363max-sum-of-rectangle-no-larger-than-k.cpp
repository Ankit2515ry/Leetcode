class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        vector<vector<int>>pre=matrix;
        int n=pre.size();
        int m=pre[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0)pre[i][j]+=pre[i-1][j];
                if(j>0)pre[i][j]+=pre[i][j-1];
                if(i>0&&j>0)pre[i][j]-=pre[i-1][j-1];
            }
        }
        int res=INT_MIN;
        // for(auto &it:pre){
        //     for(auto &i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int x=i;x<n;x++){
                    for(int y=j;y<m;y++){
                        int temp=pre[x][y];
                        if(i>0)temp-=pre[i-1][y];
                        if(j>0)temp-=pre[x][j-1];
                        if(i>0&&j>0)temp+=pre[i-1][j-1];
                        if(temp<=k){
                            res=max(res,temp);
                        }
                    }
                }
            }
        }
        return res;
    }
};