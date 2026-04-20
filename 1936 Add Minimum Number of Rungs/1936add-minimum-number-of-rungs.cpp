class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int res=0;
        int n=rungs.size();
        int d=rungs[0];
        if(d/dist>0){
            if(d%dist==0)res--;
            res+=d/dist;
        }
        for(int i=1;i<n;i++){
            d=rungs[i]-rungs[i-1];
            if(d/dist>0){
            if(d%dist==0)res--;
                res+=d/dist;
            }
        }
        return res;
    }
};