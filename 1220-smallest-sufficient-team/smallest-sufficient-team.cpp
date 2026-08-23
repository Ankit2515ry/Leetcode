// class Solution {
// public:
//     int solve(vector<string>& r, vector<vector<string>>& p,int mask,long long rp){
//         int n=r.size();
//         int c=__builtin_popcount(mask);
//         if(c==n)return rp;
//         int res=0;
//         int pc=61;
//         for(int i=0;i<p.size();i++){
//             if(!((rp>>i)&1)){
//                 int temp=mask;
//                 for(int j=0;j<p[i].size();j++){
//                     for(int k=0;k<n;k++){
//                         if(p[i][j]==r[k]){
//                             temp|=(1<<k);
//                         }
//                     }
//                 }
//                 int a=solve(r,p,temp,(rp|(1<<i)));
//                 int x=__builtin_popcount(a);
//                 if(pc>x){
//                     res=a;
//                     pc=x;
//                 }
//             }
//         }
//         return res;
//     }
//     vector<int> smallestSufficientTeam(vector<string>& r, vector<vector<string>>& p) {
//         int res=solve(r,p,0,0);
//         int i=0;
//         vector<int>ans;
//         while(res){
//             if(res&1){
//                 ans.push_back(i);
//             }
//             i++;
//             res=res>>1;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    unordered_map<string,int>mp;
    vector<int>pm;
    int tm;
    int m;
    vector<vector<long long>>dp;
    long long solve(int i,int mask){
        if(mask==tm)return 0;
        if(i==m)return (1LL<<60)-1;
        if(dp[i][mask]!=-1)return dp[i][mask];
        long long a=solve(i+1,mask);
        long long b=(1LL<<i)|solve(i+1,mask|pm[i]);
        int x=__builtin_popcountll(a);
        int y=__builtin_popcountll(b);
        if(x>y)return dp[i][mask]=b;
        return dp[i][mask]=a;
    }
    vector<int> smallestSufficientTeam(vector<string>& r, vector<vector<string>>& p) {
        int n=r.size();
        m=p.size();
        tm=(1<<n)-1;
        for(int i=0;i<n;i++){
            mp[r[i]]=i;
        }
        pm.assign(m,0);
        for(int i=0;i<m;i++){
            int m=0;
            for(auto it:p[i]){
                m|=(1<<mp[it]);
            }
            pm[i]=m;
        }
        dp.assign(m,vector<long long>(tm,-1));
        long long res=solve(0,0);
        int i=0;
        vector<int>ans;
        while(res){
            if(res&1){
                ans.push_back(i);
            }
            i++;
            res=res>>1;
        }
        return ans;
    }
};