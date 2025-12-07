class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n=damage.size();
        long long res=0;
        vector<long long>pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+damage[i-1];
        }
        vector<long long >temp;
        for(int i=0;i<n;i++){
            long long a=pre[i+1]-(hp-requirement[i]);
            auto it=lower_bound(pre.begin(),pre.begin()+i+1,a);
            res+=(pre.begin()+i+1)-it;
        }
        return res;
    }
};