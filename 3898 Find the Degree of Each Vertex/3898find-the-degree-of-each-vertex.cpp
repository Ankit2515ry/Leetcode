class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& m) {
        vector<int>res(m.size(),0);
        for(int i=0;i<m.size();i++){
            int x=0;
            for(int j=0;j<m.size();j++){
                if(m[i][j]==1)x++;
            }
            res[i]=x;
        }
        return res;
    }
};