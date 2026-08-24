// class Solution {
// public:
//     vector<vector<int>>dp;
//     int numSlots;
//     int solve(vector<int>& nums,int mask,int slot){
//         int n=nums.size();
//         if(mask==(1<<n)-1)return 0;
//         if(slot>numSlots)return INT_MIN;
//         if(dp[mask][slot]!=-1)return dp[mask][slot];
//         int res=0;
//         res=max(res,solve(nums,mask,slot+1));
//         for(int i=0;i<n;i++){
//             if(!((mask>>i)&1)){
//                 res=max(res,(slot&nums[i])+solve(nums,mask|(1<<i),slot+1));
//                 for(int j=i+1;j<n;j++){
//                     if(!((mask>>j)&1)){
//                         res=max(res,(slot&nums[i])+(slot&nums[j])+solve(nums,mask|(1<<i)|(1<<j),slot+1));
//                     }
//                 }
//             }
//         }
//         return dp[mask][slot]=res;
//     }
//     int maximumANDSum(vector<int>& nums, int slots) {
//         int n=nums.size();
//         numSlots=slots;
//         int sz=(1<<(n+1));
//         dp.assign(sz,vector<int>(slots+1,-1));
//         return solve(nums,0,0);
//     }
// };
class Solution {
public:
    int dp[1 << 18][10][3];
    int numSlots;
    int solve(vector<int>& nums,int mask,int slot,int c){
        int n=nums.size();
        if(mask==(1<<n)-1)return 0;
        if(slot>numSlots)return -1e7;
        if(dp[mask][slot][c]!=-1)return dp[mask][slot][c];
        int res=0;
        res=max(res,solve(nums,mask,slot+1,0));
        if(c<2){
            for(int i=0;i<n;i++){
                if(!((mask>>i)&1)){
                    res=max(res,(slot&nums[i])+solve(nums,mask|(1<<i),slot,c+1));
                }
            }
        }
        return dp[mask][slot][c]=res;
    }
    int maximumANDSum(vector<int>& nums, int slots) {
        int n=nums.size();
        numSlots=slots;
        memset(dp, -1, sizeof(dp));
        return solve(nums,0,1,0);
    }
};
// class Solution {
// public:
//     int maximumANDSum(vector<int>& nums, int numSlots) {
        
//     }
// };