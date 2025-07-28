class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //
        int count=0;
        int maxor=0;
        for(auto it:nums)maxor|=it;
        int n=nums.size();
        int subset=1<<n;
        for(int i=0;i<subset;i++){
            int curror=0;
            for(int j=0;j<n;j++){
                if(i&1<<j)curror|=nums[j];
            }
            if(curror==maxor)count++;
        }
        return count;
    }
};
// class Solution {
// public:
//     int count=0;
//     void rec(int i,int currOR,int maxOR,vector<int>nums,int n){
//         if(i==n){
//             if(currOR==maxOR)count++;
//             return;
//         }
//         rec(i+1,currOR,maxOR,nums,n);
//         rec(i+1,currOR|nums[i],maxOR,nums,n);
//     }
//     int countMaxOrSubsets(vector<int>& nums) {
//         int n=nums.size();
//         int currOR=0;
//         int maxOR=0;
//         for(auto it:nums)maxOR|=it;
//         rec(0,currOR,maxOR,nums,n);
//         return count;
//     }
// };