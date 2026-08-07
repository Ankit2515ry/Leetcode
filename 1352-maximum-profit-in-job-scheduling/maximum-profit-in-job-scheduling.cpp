class Solution {
public:
    vector<int>dp;
    int n;
    vector<pair<pair<int,int>,int>>temp;
    vector<int>s;
    int solve(int idx){
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int a=solve(idx+1);
        auto it=temp[idx];
        int ns=it.first.second;
        int i=lower_bound(s.begin(),s.end(),ns)-s.begin();
        int b=it.second+solve(i);
        return dp[idx]=max(a,b);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        s=startTime;
        dp.assign(n,-1);
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++){
            temp.push_back({{startTime[i],endTime[i]},profit[i]});
        }
        sort(temp.begin(),temp.end());
        return solve(0);
    }
};