class Solution {
public:
    string largestWordCount(vector<string>& m, vector<string>& s) {
        unordered_map<string,int>mp;
        int n=m.size();
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<m[i].size();j++){
                if(m[i][j]==' ')temp++;
            }
            mp[s[i]]+=temp+1;
        }
        int res=0;
        for(auto it:mp){
            res=max(res,it.second);
        }
        string ans="";
        for(auto it:mp){
            if(res==it.second){
                ans=max(ans,it.first);
            }
        }
        return ans;
    }
};