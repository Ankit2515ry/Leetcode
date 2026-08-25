// class Solution {
// public:
//     int kk;
//     vector<int>wt;
//     int solve(vector<int>& jobs,int idx){
//         int n=jobs.size();
//         if(idx>=n){
//             int res=0;
//             for(auto it:wt)res=max(res,it);
//             return res;
//         }
//         int res=INT_MAX;
//         for(int i=1;i<=kk;i++){
//             wt[i]+=jobs[idx];
//             res=min(res,solve(jobs,idx+1));
//             wt[i]-=jobs[idx];
//         }
//         return res;
//     }
//     int minimumTimeRequired(vector<int>& jobs, int k) {
//         int n=jobs.size();
//         kk=k;
//         wt.assign(k+1,0);
//         return solve(jobs,0);
//     }
// };
class Solution {
public:
    int k;
    vector<int>maskt;
    int dp[1<<12][12];
    int solve(int mask,int idx){
        if(mask==0)return 0;
        if(idx==k-1)return maskt[mask];
        if(dp[mask][idx]!=-1)return dp[mask][idx];
        int res=INT_MAX;
        res=min(res,solve(mask,idx+1));
        int sub=mask;
        while(sub){
            int curr=maskt[sub];
            int next=solve(mask^sub,idx+1);
            res=min(res,max(curr,next));
            sub=(sub-1)&mask;
        }
        return dp[mask][idx]=res;
    }
    int minimumTimeRequired(vector<int>& jobs, int kk) {
        int n=jobs.size();
        for(int i=0;i<(1<<n);i++){
            int val=0;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    val+=jobs[j];
                }
            }
            maskt.push_back(val);
        }
        k=kk;
        memset(dp,-1,sizeof(dp));
        return solve((1<<n)-1,0);
    }
};