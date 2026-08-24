class Solution {
public:
    int st;
    int dp[1<<14][16];
    int solve(vector<int>& tasks,int mask,int sum){
        int n=tasks.size();
        if(mask==(1<<n)-1){
            if(sum>0)return 1;
            return 0;
        }
        if(dp[mask][sum]!=-1)return dp[mask][sum];
        int res=n;
        if(sum>0)res=min(res,1+solve(tasks,mask,0));
        for(int i=0;i<n;i++){
            if(!((mask>>i)&1)&&sum+tasks[i]<=st){
                res=min(res,solve(tasks,mask|(1<<i),sum+tasks[i]));
            }
        }
        return dp[mask][sum]=res;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        st=sessionTime;
        int n=tasks.size();
        memset(dp,-1,sizeof(dp));
        return solve(tasks,0,0);
    }
};