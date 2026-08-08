class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>f(n,0);
        vector<long long>nf(n,0);
        sort(meetings.begin(), meetings.end());
        for(auto it:meetings){
            int s=it[0];
            int e=it[1];
            long long d=e-s;
            int p=n;
            long long se=LLONG_MAX;
            int sei=n;
            for(int i=n-1;i>=0;i--){
                if(nf[i]<=s)p=i;
                else{
                    if(se>=nf[i]){
                        se=nf[i];
                        sei=i;
                    }
                }
            }
            if(p==n)p=sei;
            f[p]++;
            long long x=max(1LL*s,nf[p]);
            nf[p]=x+d;
        }
        int res=0;
        int temp=0;
        for(int i=0;i<n;i++){
            if(temp<f[i]){
                res=i;
                temp=f[i];
            }
        }
        return res;
    }
};