class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& s, vector<vector<int>>& m,int i,int mask){
        int n=s.size();
        if(i==n)return 0;
        if(dp[i][mask]!=-1)return dp[i][mask];
        int res=0;
        for(int j=0;j<n;j++){
            if(!((mask>>j)&1)){
                int cs=0;
                for(int k=0;k<s[0].size();k++){
                    if(s[i][k]==m[j][k])cs++;
                }
                res=max(res,cs+solve(s,m,i+1,(mask|(1<<j))));
            }
        }
        return dp[i][mask]=res;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size();
        int m=1<<(n+1);
        dp.assign(n+1,vector<int>(m,-1));
        return solve(students,mentors,0,0);
    }
};