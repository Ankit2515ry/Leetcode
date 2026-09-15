class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&temp,int i){
        int n=temp.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int res=0;
        res=max(res,solve(temp,i+1));
        if(temp[i]>=0){
            res=max(res,1+solve(temp,temp[i]+1));
        }
        return dp[i]=res;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        //if(k==1)return n;
        vector<int>temp(n,-1);
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0&&r<n){
                if(s[l]!=s[r])break;
                if(r-l+1>=k){
                    if(temp[l]!=-1)temp[l]=min(temp[l],r);
                    else temp[l]=r;
                    break;
                }
                l--;
                r++;
            }
            if(i>0){
                l=i-1;
                r=i;
                while(l>=0&&r<n){
                    if(s[l]!=s[r])break;
                    if(r-l+1>=k){
                        if(temp[l]!=-1)temp[l]=min(temp[l],r);
                        else temp[l]=r;
                        break;
                    }
                    l--;
                    r++;
                }
            }
        }
        dp.assign(n+1,-1);
        return solve(temp,0);
    }
};