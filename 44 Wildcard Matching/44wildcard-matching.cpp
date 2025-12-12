class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i,int j,string &s,string &p){
        int n=s.size();
        int m=p.size();
        if(j==m)return (i==n);
        if(i==n){
            for(int k=j;k<m;k++)
                if(p[k]!='*')return false;
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j]||p[j]=='?')return dp[i][j]=solve(i+1,j+1,s,p);
        if(p[j]=='*'){
            return dp[i][j]=solve(i,j+1,s,p)||solve(i+1,j,s,p);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,s,p);
    }
};