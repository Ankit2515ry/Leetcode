class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s="";
        for(int i=0;i<n;i++)s+='.';
        vector<string>res;
        res.push_back(s);
        for(int i=0;i<n-1;i++)s[i]='#';
        for(int i=0;i<m-1;i++){
            res.push_back(s);
        }
        return res;
    }
};