class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        int m=nums2.size();
        if(i==n||j==m)return -1e9;
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        int res=max({
            nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2),
            nums1[i]*nums2[j],
            solve(i+1,j,nums1,nums2),
            solve(i,j+1,nums1,nums2)
        }
        );
        return dp[i][j]=res;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        dp.assign(n,vector<int>(m,INT_MIN));
        return solve(0,0,nums1,nums2);
    }
};