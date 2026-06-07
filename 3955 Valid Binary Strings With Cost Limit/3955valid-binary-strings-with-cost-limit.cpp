class Solution {
public:
    int nn=0;
    int kk=0;
    vector<string>res;
    void solve(int idx,int c,string &s){
        if(c>kk)return;
        if(idx==nn){
            res.push_back(s);
            return;
        }
        s.push_back('0');
        solve(idx+1,c,s);
        s.pop_back();
        if(idx==0||s.back()!='1'){
            s.push_back('1');
            solve(idx+1,c+idx,s);
            s.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string s="";
        nn=n;
        kk=k;
        solve(0,0,s);
        return res;       
    }
};