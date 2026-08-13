class Solution {
public:
    string reorganizeString(string s) {
        vector<int>f(26,0);
        for(auto it:s)f[it-'a']++;
        int maxi=0;
        for(auto it:f)maxi=max(maxi,it);
        int idx=0;
        if(maxi>(s.size()+1)/2)return "";
        string res(s.size(),' ');
        char ch=' ';
        for(int i=0;i<26;i++)if(f[i]==maxi)ch='a'+i;
        while(idx<s.size()){
            res[idx]=ch;
            f[ch-'a']--;
            idx+=2;
            if(f[ch-'a']==0)break;
        }
        for(int i=0;i<26;i++){
            while(f[i]>0){
                if(idx>=s.size())idx=1;
                res[idx]='a'+i;
                f[i]--;
                idx+=2;
            }
        }
        return res;
    }
};