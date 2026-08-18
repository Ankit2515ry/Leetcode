class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(1002,0);
        for(auto it:trips){
            int v=it[0];
            int l=it[1];
            int r=it[2];
            diff[l]+=v;
            diff[r]-=v;
        }
        for(int i=1;i<1002;i++){
            diff[i]+=diff[i-1];
        }
        for(auto it:diff)if(it>capacity)return false;
        return true;
    }
};