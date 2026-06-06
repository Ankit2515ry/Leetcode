class Solution {
public:
    int n=0;
    vector<vector<long long>>dp;
    long long solve(vector<int>& nums, string &s, int idx,bool f){
        if(idx<0)return 0;
        if(dp[idx][f]!=-1)return dp[idx][f];
        long long a=0;
        long long b=0;
        if(s[idx]=='0'){
            if(f){
                a=nums[idx]+solve(nums,s,idx-1,false);
            }else{
                a=solve(nums,s,idx-1,false);
            }
        }else{
            if(f){
                a=nums[idx]+solve(nums,s,idx-1,true);
            }else{
                a=solve(nums,s,idx-1,true);
                b=nums[idx]+solve(nums,s,idx-1,false);
            }
        }  
        return dp[idx][f]=max(a,b);  
    }
    long long maxTotal(vector<int>& nums, string s) {
        n=nums.size();
        dp.assign(n+1,vector<long long>(2,-1));
        return solve(nums,s,n-1,false);
    }
};