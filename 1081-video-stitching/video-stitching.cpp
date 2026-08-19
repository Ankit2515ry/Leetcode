class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int>diff(101,0);
        for(auto it:clips){
            int l=it[0];
            int r=it[1];
            diff[l]=max(diff[l],r);
        }
        if(diff[0]==0)return -1;
        int res=1;
        int ni=0;
        int ci=0;
        for(int i=0;i<101;i++){
            if(ni>=time)return res;
            if(ni<i)return -1;
            if(ci<i){
                res++;
                ci=ni;
            }
            ni=max(ni,diff[i]);
        }
        if(ni<time)return -1;
        return res;
    }
};