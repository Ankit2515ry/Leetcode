class Solution {
public:
    vector<vector<vector<int>>>dp;
    bool solve(string &s,int idx,int l,int r){
        int n=s.size();
        if(r>l)return false;
        if(idx>=n){
            if(l==r)return true;
            return false;
        }
        if(dp[idx][l][r]!=-1)return dp[idx][l][r];
        bool a=false;
        bool b=false;
        bool c=false;
        if(s[idx]=='('){
            a=solve(s,idx+1,l+1,r);
        }else if(s[idx]==')'){
            a=solve(s,idx+1,l,r+1);
        }else{
            a=solve(s,idx+1,l+1,r);
            b=solve(s,idx+1,l,r+1);
            c=solve(s,idx+1,l,r);
        }
        return dp[idx][l][r]=a||b||c;
    }
    bool checkValidString(string s) {
        // int mini=0;
        // int maxi=0;
        // for(auto it:s){
        //     if(it=='('){
        //         mini++;
        //         maxi++;
        //     }else if(it==')'){
        //         mini--;
        //         maxi--;
        //     }else{
        //         mini--;
        //         maxi++;
        //     }
        //     if(maxi<0)return false;
        //     if(mini<0)mini=0;
        // }
        // return mini==0;
        int n=s.size();
        dp.assign(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(s,0,0,0);
    }
};