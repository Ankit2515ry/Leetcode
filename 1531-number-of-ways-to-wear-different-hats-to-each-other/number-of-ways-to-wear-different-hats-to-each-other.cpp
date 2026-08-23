// class Solution {
// public:
//     int mod=1e9+7;
//     int solve(vector<vector<int>>& hats,int i,long long mask){
//         int n=hats.size();
//         if(i==n)return 1;
//         int res=0;
//         for(auto it:hats[i]){
//             if(!((mask>>it)&1)){
//                 res=(res+solve(hats,i+1,mask|(1LL<<it)))%mod;
//             }
//         }
//         return res;
//     }
//     int numberWays(vector<vector<int>>& hats) {
//         return solve(hats,0,0);
//     }
// };
class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>dp;
    long long solve(vector<vector<int>>& hats,int mask,int hn){
        int n=hats.size();
        if(mask==(1<<n)-1)return 1;
        if(hn>40)return 0;
        if(dp[mask][hn]!=-1)return dp[mask][hn];
        long long res=solve(hats,mask,hn+1);
        for(int i=0;i<n;i++){
            if(!((mask>>i)&1)){
                bool f=false;
                for(auto it:hats[i]){
                    if(hn==it)f=true;
                }
                if(f)res=(res+solve(hats,mask|(1<<i),hn+1))%mod;
            }
        }
        return dp[mask][hn]=res;
    }
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        dp.assign((1<<(n+1)),vector<int>(42,-1));
        long long res=solve(hats,0,1);
        return res%mod;
    }
};