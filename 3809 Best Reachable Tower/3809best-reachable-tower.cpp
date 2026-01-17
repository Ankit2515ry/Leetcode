class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int r) {
        int x=center[0];
        int y=center[1];
        int n=towers.size();
        int res1=-1;
        int res2=-1;
        int q=-1;
        for(auto &it:towers){
            int i=it[0];
            int j=it[1];
            if(abs(x-i)+abs(y-j)<=r){
                if(q<it[2]){
                    q=it[2];
                    res1=it[0];
                    res2=it[1];
                }
                if(q==it[2]){
                    if(res1>it[0]){
                        res1=it[0];
                        res2=it[1];
                    }
                    if(res1==it[0]&&res2>it[1]){
                        res1=it[0];
                        res2=it[1];
                    }
                }
            }
        }
        return {res1,res2};
    }
};