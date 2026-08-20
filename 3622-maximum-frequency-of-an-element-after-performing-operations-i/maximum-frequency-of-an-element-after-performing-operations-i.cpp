class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int m=1e5+2;
        vector<int>init(m,0);
        for(auto it:nums){
            init[it]++;
        }
        vector<int>lat(m,0);
        for(auto it:nums){
            int l=max(1,it-k);
            int r=min(m-2,it+k);
            lat[l]++;
            lat[r+1]--;
        }
        for(int i=1;i<m;i++){
            lat[i]+=lat[i-1];
        }
        int res=0;
        for(int i=0;i<m;i++){
            int d=lat[i]-init[i];
            d=min(d,numOperations);
            res=max(res,init[i]+d);
        }
        return res;
    }
};