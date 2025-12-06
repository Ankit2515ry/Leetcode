class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            string a="";
            for(int j=i;j<n;j++){
                if(j>i&&s[j]!=s[j-1]){
                    break;
                }
                a+=s[j];
                mp[a]++;
            }
        }
        int res=-1;
        for(auto &it:mp){
            if(it.second>2){
                int a=it.first.size();
                cout<<it.first<<endl;
                res=max(res,a);
            }
        }
        return res;
    }
};