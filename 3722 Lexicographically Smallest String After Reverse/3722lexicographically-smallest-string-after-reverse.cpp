class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string res=s;
        for(int i=0;i<n;i++){
            string a=s;
            reverse(a.begin(),a.begin()+i);
            string b=s;
            reverse(b.begin()+i,b.end());
            res=min(res,min(a,b));
        }
        return res;
    }
};