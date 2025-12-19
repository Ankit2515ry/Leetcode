// class Solution {
// public:
//     vector<vector<int>>dp;
//     // bool check(int i,int j,string &s){
//     //     while(i<j){
//     //         if(s[i]!=s[j])return false;
//     //         i++;
//     //         j--;
//     //     }
//     //     return true;
//     // }
//     int solve(int i,int j,string &s,vector<vector<bool>>&pal){
//         if(i>=j||pal[i][j])return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int temp=INT_MAX;
//         for(int k=i;k<j;k++){
//             int a=solve(i,k,s,pal);
//             int b=solve(k+1,j,s,pal);
//             temp=min(temp,a+b+1);
//         }
//         return dp[i][j]=temp;
//     }
//     int minCut(string s) {
//         int n=s.size();
//         vector<vector<bool>> pal(n, vector<bool>(n, false));
//         for (int len = 1; len <= n; len++) {
//             for (int i = 0; i + len - 1 < n; i++) {
//                 int j = i + len - 1;
//                 if (s[i] == s[j] && (len <= 2 || pal[i + 1][j - 1])) {
//                     pal[i][j] = true;
//                 }
//             }
//         }
//         dp.assign(n,vector<int>(n,-1));
//         return solve(0,n-1,s,pal);
//     }
// };
class Solution {
public:
    int n;
    vector<int> dp;
    vector<vector<int>> pal;
    int solve(int i) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for (int j = i; j < n; j++) {
            if (pal[i][j]) {
                ans = min(ans, 1 + solve(j + 1));
            }
        }
        return dp[i] = ans;
    }
    bool check(int i,int j,string &s){
        if(i>=j)return true;//i>j->empty string
        if(pal[i][j]!=-1)return pal[i][j];
        return pal[i][j]=(s[i]==s[j]&&check(i + 1, j - 1, s));
    }
    int minCut(string s) {
        n = s.size();
        pal.assign(n, vector<int>(n, -1));
        for(int i=0;i<n;i++)pal[i][i]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                check(i,j,s);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<pal[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        dp.assign(n, -1);
        return solve(0) - 1;
    }
};
