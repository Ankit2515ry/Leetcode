class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // vector<vector<int>>res(n,vector<int>(n,0));
        // int m=queries.size();
        // for(int x=0;x<m;x++){
        //     int r=queries[x][0];
        //     int c=queries[x][1];
        //     int a=queries[x][2]+1;
        //     int b=queries[x][3]+1;
        //     for(int i=r;i<a;i++){
        //         for(int j=c;j<b;j++){
        //             res[i][j]++;
        //         }
        //     }
        // }
        // return res;
        vector<vector<int>>res(n,vector<int>(n,0));
        int m=queries.size();
        for(auto &it:queries){
            int r1=it[0];
            int c1=it[1];
            int r2=it[2];
            int c2=it[3];
            for(int i=r1;i<=r2;i++){
                res[i][c1]++;
                if(c2+1<n){
                    res[i][c2+1]--;
                }
            }
        }
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                c+=res[i][j];
                res[i][j]=c;
            }
        }
        return res;
    }
};