class Solution {
public:
    vector<vector<int>>dp;
    bool check(int i,int j,vector<string>& words){
        string s=words[i];
        string t=words[j];
        int c=0;
        int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[x])x++;
            else{
                c++;
            }
        }
        if(c==1)return true;
        return false;
    }
    int solve(int i,int j,vector<string>& words){
        int n=words.size();
        if(i==n)return 0;
        if(dp[i][j+1]!=-1)return dp[i][j+1];
        int a=0;
        if(j==-1||(words[j].size()==words[i].size()-1&&check(i,j,words)))a=solve(i+1,i,words)+1;
        int b=solve(i+1,j,words);
        return dp[i][j+1]=max(a,b);
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        dp.assign(n,vector<int>(n+1,-1));
        sort(words.begin(), words.end(),
        [](const auto &a, const auto &b) {
            return a.size() < b.size();
        });
        //for(auto &it:words)cout<<it<<" ";
        return solve(0,-1,words);
    }
};