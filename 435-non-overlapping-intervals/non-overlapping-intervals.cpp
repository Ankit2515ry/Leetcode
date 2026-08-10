class Solution {
public:
    vector<int>dp;
    int solve(vector<vector<int>>& intervals,int idx){
        int n=intervals.size();
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int a=solve(intervals,idx+1);
        int e=intervals[idx][1];
        auto it=lower_bound(intervals.begin()+idx+1,intervals.end(),vector<int>{e,INT_MIN});
        int i=it-intervals.begin();
        // int i=idx+1;
        // while(i<n){
        //     if(e<=intervals[i][0])break;
        //     i++;
        // }
        int b=solve(intervals,i)+1;
        return dp[idx]=max(a,b);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        dp.assign(n,-1);
        sort(intervals.begin(),intervals.end());
        return n-solve(intervals,0);
    }
};