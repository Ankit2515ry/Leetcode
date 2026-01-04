class Solution {
public:
    string largestEven(string s) {
        string res=s;
        reverse(s.begin(),s.end());
        for(auto &it:s){
            if(it=='1')res.pop_back();
            else return res;
        }
        return res;
    }
};