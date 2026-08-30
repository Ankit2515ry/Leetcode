class Solution {
public:
    long long mod=1e9+7;
    long long modpower(long long base,long long exp){
        long long res=1;
        base%=mod;
        while(exp){
            if(exp&1){
                res=(res*base)%mod;
            }
            base=(base*base)%mod;
            exp=exp>>1;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        long long res=0;
        for(auto it:nums){
            long long w=it%10;
            it=floor(it/10);
            stack<int>st;
            while(it){
                int d=it%10;
                st.push(d);
                it/=10;
            }
            long long x=0;
            while(w--){
                x=(x*10)+st.top();
                st.pop();
            }
            long long y=0;
            while(!st.empty()){
                y=(y*10)+st.top();
                st.pop();
            }
            res=(res+modpower(x,y))%mod;
        }
        return res;
    }
};