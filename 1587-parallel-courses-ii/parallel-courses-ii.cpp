class Solution {
public:
    int k;
    int n;
    int dp[1<<16];
    int solve(vector<vector<int>>& r,int mask){
        if(mask==0)return 0;
        if(dp[mask]!=-1)return dp[mask];
        int sub=mask;
        int res=1000;
        while(sub){
            int c=__builtin_popcount(sub);
            if(c<=k){
                bool f=true;
                for(int i=0;i<r.size();i++){
                    int prev=r[i][0]-1;
                    int curr=r[i][1]-1;
                    if((sub>>curr)&1){
                        if((mask>>prev)&1)f=false;
                    }
                }
                if(f){
                    res=min(res,1+solve(r,mask^sub));
                }
            }
            sub=(sub-1)&mask;
        }
        return dp[mask]=res;
    }
    int minNumberOfSemesters(int nn, vector<vector<int>>& relations, int kk) {
        k=kk;
        n=nn;
        memset(dp,-1,sizeof(dp));
        return solve(relations,(1<<n)-1);
    }
};