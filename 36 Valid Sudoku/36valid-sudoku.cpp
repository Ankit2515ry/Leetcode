class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        for(int i=0;i<n;i++){
            unordered_set<char>st;
            for(int j=0;j<m;j++){
                //cout<<b[i][j]<<" ";
                if(st.find(b[i][j])!=st.end())return false;
                if(b[i][j]!='.')st.insert(b[i][j]);
            }
            //cout<<endl;
        }
        for(int i=0;i<n;i++){
            unordered_set<char>st;
            for(int j=0;j<m;j++){
                if(st.find(b[j][i])!=st.end())return false;
                if(b[j][i]!='.')st.insert(b[j][i]);
            }
        }
        vector<pair<int,int>>idx={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        n=idx.size();
        for(int i=0;i<n;i++){
            int l=idx[i].first;
            int m=idx[i].second;
            unordered_set<char>st;
            for(int c=l;c<l+3;c++){
                for(int d=m;d<m+3;d++){
                    if(st.find(b[c][d])!=st.end())return false;
                    if(b[c][d]!='.')st.insert(b[c][d]);
                }
            }
        }
        return true;
    }
};