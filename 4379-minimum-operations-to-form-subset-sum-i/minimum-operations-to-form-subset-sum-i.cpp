// class Solution {
// public:
//     int s;
//     int solve(vector<vector<pair<int,int>>>&temp,int idx,int sum,int op){
//         int n=temp.size();
//         if(sum==s)return op;
//         if(idx>=n)return INT_MAX;
//         int a=solve(temp,idx+1,sum,op);
//         int b=INT_MAX;
//         for(int i=0;i<temp[idx].size();i++){
//             if(sum+temp[idx][i].first<=s){
//                 b=min(b,solve(temp,idx+1,sum+temp[idx][i].first,op+temp[idx][i].second));
//             }
//         }
//         return min(a,b);
//     }
//     int minOperations(vector<int>& nums, int sum) {
//         s=sum;
//         int n=nums.size();
//         vector<vector<pair<int,int>>>temp(n);
//         for(int i=0;i<n;i++){
//             int it=nums[i];
//             temp[i].push_back({it,0});
//             long long x=it;
//             int j=0;
//             while(x<=sum){
//                 x*=2;
//                 j++;
//                 temp[i].push_back({x,j});
//             }
//             x=it;
//             j=0;
//             while(x>0){
//                 x/=2;
//                 j++;
//                 temp[i].push_back({x,j});
//             }
//         }
//         int res = solve(temp,0,0,0);
//         if(res==INT_MAX)return -1;
//         return res;
//     }
// };
class Solution {
public:
    int dp[101][5001];
    int s;
    int solve(vector<vector<pair<int,int>>>&temp,int idx,int sum){
        int n=temp.size();
        if(sum==s)return 0;
        if(idx>=n)return INT_MAX;
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        int a=solve(temp,idx+1,sum);
        int b=INT_MAX;
        for(int i=0;i<temp[idx].size();i++){
            if(sum+temp[idx][i].first<=s){
                int val=solve(temp,idx+1,sum+temp[idx][i].first);
                if(val!=INT_MAX){
                    b=min(b,val+temp[idx][i].second);
                }
            }
        }
        return dp[idx][sum]=min(a,b);
    }
    int minOperations(vector<int>& nums, int sum) {
        s=sum;
        int n=nums.size();
        vector<vector<pair<int,int>>>temp(n);
        for(int i=0;i<n;i++){
            int it=nums[i];
            temp[i].push_back({it,0});
            long long x=it;
            int j=0;
            while(x<=sum){
                x*=2;
                j++;
                temp[i].push_back({x,j});
            }
            x=it;
            j=0;
            while(x>0){
                x/=2;
                j++;
                temp[i].push_back({x,j});
            }
        }
        memset(dp,-1,sizeof(dp));
        int res = solve(temp,0,0);
        if(res==INT_MAX)return -1;
        return res;
    }
};