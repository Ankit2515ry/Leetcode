class Solution {
public:
    string reverseWords(string s) {
        string res="";
        int pre=0;
        int n=s.size();
        int i=n-1;
        while(i>=0){
            while(i>=0&&s[i]==' ')i--;
            while(i>=0&&s[i]!=' '){
                res+=s[i];
                i--;
            }
            reverse(res.begin()+pre,res.end());
            pre=res.size()+1;
            res+=' ';
            i--;
        }
        while(res.back()==' ')res.pop_back();
        return res;
    }
};