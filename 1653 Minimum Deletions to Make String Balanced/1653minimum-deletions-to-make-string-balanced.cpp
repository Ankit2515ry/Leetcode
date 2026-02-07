class Solution {
public:
    int minimumDeletions(string s) {
        vector<int>pre(s.size(),0);
        if(s[0]=='a')pre[0]=1;
        for(int i=1;i<s.size();i++){
            if(s[i]=='a')pre[i]+=pre[i-1]+1;
            else pre[i]+=pre[i-1];
        }
        vector<int>suf(s.size(),0);
        if(s[s.size()-1]=='b')suf[s.size()-1]=1;
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]=='b')suf[i]+=suf[i+1]+1;
            else suf[i]+=suf[i+1];
        }
        int temp=INT_MIN;
        for(int i=0;i<s.size();i++){
            temp=max(temp,pre[i]+suf[i]);
        }
        return s.size()-temp;
    }
};