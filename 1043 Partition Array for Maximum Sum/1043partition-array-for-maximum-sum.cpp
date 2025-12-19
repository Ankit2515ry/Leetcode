class Solution {
public:
    vector<int>arr;
    int k;
    vector<vector<int>>dp;
    int solve(int i,int j){
        int n=arr.size();
        if(i>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=0;
        int ind=i;
        int c=k;
        int sum=0;
        while(ind<n&&c>0){
            maxi=max(maxi,arr[ind]);
            sum=max(sum,((ind-j+1)*maxi)+solve(ind+1,ind+1));
            ind++;
            c--;
        }
        return dp[i][j]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& a, int p) {
        arr=a;
        k=p;
        int n=a.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,0);
    }
};