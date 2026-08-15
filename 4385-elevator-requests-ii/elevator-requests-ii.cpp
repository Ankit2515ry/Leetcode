class Solution {
public:
    vector<int>a;
    int s;
    bool f;
    int sz;
    vector<vector<vector<long long>>>dp;
    long long solve(int l,int r,int side){
        if(l==0&&r==sz-1)return 0;
        if(dp[l][r][side]!=-1)return dp[l][r][side];
        int fill=r-l+1;
        int rem=sz-fill;
        int pos=(side==0)?a[l]:a[r];
        long long res=1e18;
        if(l>0){
            long long temp=1LL*abs(pos-a[l-1])*rem+solve(l-1,r,0);
            res=min(res,temp);
        }
        if(r<sz-1){
            long long temp=1LL*abs(pos-a[r+1])*rem+solve(l,r+1,1);
            res=min(res,temp);
        }
        return dp[l][r][side]=res;
    }
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        int m=requests.size();
        a=requests;
        f=false;
        for(auto it:a){
            if(it==start){
                f=true;
                break;
            }
        }
        if(!f){
            a.push_back(start);
        }
        sort(a.begin(),a.end());
        s=lower_bound(a.begin(),a.end(),start)-a.begin();
        sz=a.size();
        dp.assign(sz,vector<vector<long long>>(sz,vector<long long>(2,-1LL)));
        return solve(s,s,0);
    }
};