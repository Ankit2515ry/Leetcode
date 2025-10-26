class Solution {
public:
    long long countStableSubarrays(vector<int>& c) {
        long long res=0;
        int n=c.size();
        vector<long long>pre(n+1,0);
        unordered_map<long long,unordered_map<long long,long long>>mp;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+c[i];
        }
        for(int i=0;i<n;i++){
            if(i>=2){
                int l=i-2;
                long long x=c[l];
                long long y=pre[l+1];
                mp[x][y]++;
            }
            long long a=c[i];
            long long b=pre[i]-a;
            if(mp.find(a)!=mp.end()&&mp[a].find(b)!=mp[a].end()){
                res+=mp[a][b];
            }
        }
        return res;
    }
};