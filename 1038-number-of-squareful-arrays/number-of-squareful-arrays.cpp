class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& nums,int mask,int last){
        int n=nums.size();
        if(mask==(1<<n)-1)return 1;
        if(dp[mask][last+1]!=-1)return dp[mask][last+1];
        int res=0;
        int idx=__builtin_popcount(mask);
        for(int i=0;i<n;i++){
            if((mask>>i)&1)continue;
            if(i>0&&nums[i]==nums[i-1]&&!((mask>>(i-1))&1))continue;
            if(last==-1){
                res+=solve(nums,(mask|(1<<i)),i);
            }else{
                int m=nums[last]+nums[i];
                int sq=sqrt(m);
                if(sq*sq==m){
                    res+=solve(nums,(mask|(1<<i)),i);
                }
            }
        }
        return dp[mask][last+1]=res;
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        dp.assign((1<<(n+1)),vector<int>(n+2,-1));
        return solve(nums,0,-1);
    }
};