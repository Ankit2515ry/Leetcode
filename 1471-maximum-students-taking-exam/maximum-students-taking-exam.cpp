class Solution {
public:
    int n;
    int dp[8][1<<8];
    int solve(vector<vector<char>>& seats,int prev_mask,int idx){
        if(idx==n)return 0;
        if(dp[idx][prev_mask]!=-1)return dp[idx][prev_mask];
        int mask=0;
        int m=seats[idx].size();
        for(int i=0;i<m;i++){
            if(seats[idx][i]=='.'){
                mask|=(1<<i);
            }
        }
        int sub=mask;
        int res=0;
        res=max(res,solve(seats,0,idx+1));
        while(sub){
            bool f=true;
            for(int i=1;i<m;i++){
                if(((sub>>i)&1)&&((sub>>(i-1))&1))f=false;
            }
            if(((sub>>0)&1)&&((prev_mask>>1)&1)){
                f=false;
            }
            if(((sub>>(m-1))&1)&&((prev_mask>>(m-2))&1)){
                f=false;
            }
            for(int i=1;i<m-1;i++){
                if(((sub>>i)&1)&&(((prev_mask>>(i-1))&1)||((prev_mask>>(i+1))&1)))f=false;
            }
            int c=__builtin_popcount(sub);
            if(f){
                res=max(res,c+solve(seats,sub,idx+1));
            }
            sub=(sub-1)&mask;
        }
        return dp[idx][prev_mask]=res;
    }
    int maxStudents(vector<vector<char>>& seats) {
        n=seats.size();
        memset(dp,-1,sizeof(dp));
        return solve(seats,0,0);    
    }
};