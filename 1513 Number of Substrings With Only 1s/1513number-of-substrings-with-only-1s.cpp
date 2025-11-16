class Solution {
public:
    int numSub(string s) {
        int n=s.size();
        long long ans=0;
        long long c=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            if(s[i]=='1')c++;
            else{
                ans+=(c*(c+1))/2;
                c=0;
                ans%=mod;
            }
        }
        ans+=(c*(c+1))/2;
        c=0;
        ans%=mod;
        int res=ans;
        return res;
    }
};