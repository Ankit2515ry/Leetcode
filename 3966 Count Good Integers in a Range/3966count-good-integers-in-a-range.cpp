class Solution {
public:
    long long dp[20][10][2][2];
    long long solve(string &s,int idx,int pre,bool t,bool lz,int k){
        if(idx==s.size())return 1;
        if(dp[idx][pre][t][lz]!=-1)return dp[idx][pre][t][lz];
        long long ans=0;
        int l=t?(s[idx]-'0'):9;
        for(int d=0;d<=l;d++){
            bool nt=t&&(d==l);
            if(lz){
                if(d==0)ans+=solve(s,idx+1,0,nt,true,k);
                else ans+=solve(s,idx+1,d,nt,false,k);
            }else{
                if(abs(d-pre)<=k)ans+=solve(s,idx+1,d,nt,false,k);
            }
        }
        return dp[idx][pre][t][lz]=ans;
    }
    long long cg(long long n, int k){
        if(n<0)return 0;
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0,true,true,k);
    }
    long long goodIntegers(long long l, long long r, int k) {
        return cg(r,k)-cg(l-1,k);
    }
};