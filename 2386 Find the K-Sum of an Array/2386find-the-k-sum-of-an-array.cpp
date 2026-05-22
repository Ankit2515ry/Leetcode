class Solution {
public:
    // vector<long long>sum;
    // void solve(int i,vector<int>& nums,int s){
    //     int n=nums.size();
    //     if(i==n){
    //         sum.push_back(s);
    //         return;
    //     }
    //     solve(i+1,nums,s+nums[i]);
    //     solve(i+1,nums,s);
    // }
    long long kSum(vector<int>& nums, int k) {
        // solve(0,nums,0);
        // sort(sum.rbegin(),sum.rend());
        // for(auto &it:sum)cout<<it<<" ";
        // return sum[k-1];
        int n=nums.size();
        long long res=0;
        for(auto &it:nums){
            if(it>0)res+=it;
            else it=abs(it);
        }
        sort(nums.begin(),nums.end());
        priority_queue<pair<long long ,int>>pq;
        pq.push({res-nums[0],0});
        while(--k){
            auto [sum, i] = pq.top(); 
            pq.pop();
            if (i + 1 < nums.size()) {
                pq.push({sum - nums[i + 1], i + 1});
                pq.push({sum + nums[i] - nums[i + 1], i + 1});
            }
            res = sum;
        }
        return res;
    }
};