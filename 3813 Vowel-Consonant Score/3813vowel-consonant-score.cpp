class Solution {
public:
    int vowelConsonantScore(string s) {
        int v=0;
        int c=0;
        string vs="aeiou";
        for(auto &x:s){
            if(vs.find(x)!=string::npos)v++;
            else if(x-'a'<26&&x-'a'>=0)c++;
        }
        if(c==0)return 0;
        return floor(v/c);
    }
};