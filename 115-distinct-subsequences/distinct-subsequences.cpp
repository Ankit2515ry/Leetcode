class Solution {
public:
    // string k;
    // int solve(int i,string s,string temp){
    //     if(i>=s.size()){
    //         if(temp==k)return 1;
    //         return 0;
    //     }
    //     return solve(i+1,s,temp+s[i])+solve(i+1,s,temp);
    // }
    vector<vector<int>>dp;
    int solve(int i,int j,string &s,string &t){
        int n=s.size();
        int m=t.size();
        if(i>=n){
            if(j<=m-1)return 0;
            else{
                return 1;
            }
        }
        if(j>=m)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int b=0;
        if(s[i]==t[j]){
            b=solve(i+1,j+1,s,t);
        }
        int a=solve(i+1,j,s,t);
        return dp[i][j]=a+b;
    }
    int numDistinct(string s, string t) {
        // k=t;
        // return solve(0,s,"");
        int n=s.size();
        int m=t.size();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,s,t);
    }
};