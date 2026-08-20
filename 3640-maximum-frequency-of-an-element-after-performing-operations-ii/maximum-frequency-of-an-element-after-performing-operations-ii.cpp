class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // int m=1e5+2;
        // vector<int>init(m,0);
        // for(auto it:nums){
        //     init[it]++;
        // }
        // vector<int>lat(m,0);
        // for(auto it:nums){
        //     int l=max(1,it-k);
        //     int r=min(m-2,it+k);
        //     lat[l]++;
        //     lat[r+1]--;
        // }
        // for(int i=1;i<m;i++){
        //     lat[i]+=lat[i-1];
        // }
        // int res=0;
        // for(int i=0;i<m;i++){
        //     int d=lat[i]-init[i];
        //     d=min(d,numOperations);
        //     res=max(res,init[i]+d);
        // }
        // return res;

        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int l=lower_bound(nums.begin(),nums.end(),nums[i]-k)-nums.begin();
            int r=lower_bound(nums.begin(),nums.end(),nums[i]+k+1)-nums.begin();
            int d=r-l-mp[nums[i]];
            res=max(res,min(numOperations,d)+mp[nums[i]]);
            int v=(1LL*nums[i]+1LL*2*k+1>1LL*INT_MAX)?INT_MAX:nums[i]+2*k+1;
            int rr=lower_bound(nums.begin(),nums.end(),v)-nums.begin();
            int x=0;
            if(mp.count(nums[i]+k))x=mp[nums[i]+k];
            int dd=rr-i-x;
            res=max(res,min(numOperations,dd)+x);
        }
        return res;
    }
};