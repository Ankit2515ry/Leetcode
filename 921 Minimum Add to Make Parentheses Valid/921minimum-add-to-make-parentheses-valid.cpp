class Solution {
public:
    int minAddToMakeValid(string s) {
        string a="";
        for(auto it:s){
            if(it=='(')a.push_back(it);
            else {
                if(a.size()>0&&a[a.size()-1]=='(')a.pop_back();
                else a.push_back(it);
            }
        }
        return a.size();
    }
};