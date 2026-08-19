class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>diff(n+1,0);
        for(int i=0;i<=n;i++){
            int mini=max(0,i-ranges[i]);
            int maxi=min(n,i+ranges[i]);
            diff[mini]=max(maxi,diff[mini]);
        }
        if(diff[0]==0)return -1;
        int res=0;
        int ci=0;
        int ni=0;
        for(int i=0;i<=n;i++){
            cout<<diff[i]<<" ";
            if(ni<i)return -1;
            if(ci<i){
                ci=ni;
                res++;
            }
            ni=max(ni,diff[i]);
        }
        return res;
    }
};