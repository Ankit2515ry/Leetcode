class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int mi=prices[0];
        int n=prices.size();
        vector<int>l(n,0);
        for(int i=1;i<n;i++){
            mi=min(mi,prices[i]);
            l[i]=max(l[i-1],prices[i]-mi);
        }
        mi=prices[n-1];
        vector<int>r(n,0);
        for(int i=n-2;i>=0;i--){
            mi=max(mi,prices[i]);
            r[i]=max(r[i+1],mi-prices[i]);
        }
        for(int i=0;i<n;i++){
            res=max(res,l[i]+r[i]);
        }
        return res;
    }
};