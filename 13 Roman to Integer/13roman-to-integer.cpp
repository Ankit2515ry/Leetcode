class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n=s.size();
        int res=0;
        for(int i=n-1;i>=0;i--){
            if(i<n-1&&mp[s[i]]<mp[s[i+1]]){
                res-=mp[s[i]];
            }else res+=mp[s[i]];
        }
        return res;
    }
};