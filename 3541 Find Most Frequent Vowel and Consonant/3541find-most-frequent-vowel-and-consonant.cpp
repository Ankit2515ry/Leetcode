class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int res=0;
        int v=0;
        int c=0;
        for(auto &it:mp){
            if(it.first=='a'||it.first=='e'||it.first=='i'||it.first=='o'||it.first=='u'){
                v=max(v,it.second);
            }else{
                c=max(c,it.second);
            }
        }
        res=v+c;
        return res;
    }
};