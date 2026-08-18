class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        long long sum=0;
        for(auto it:nums)sum+=it;
        if(sum==0)return 0;
        int l=0;
        int r=m-1;
        while(l<r){
            int mid=(l+r)/2;
            vector<int>diff(n+1,0);
            for(int i=0;i<=mid;i++){
                int ll=queries[i][0];
                int rr=queries[i][1];
                int v=queries[i][2];
                diff[ll]+=v;
                diff[rr+1]-=v;
            }
            for(int i=1;i<=n;i++){
                diff[i]+=diff[i-1];
            }
            int f=true;
            for(int i=0;i<n;i++){
                if(nums[i]>diff[i]){
                    f=false;
                    break;
                }
            }
            if(f){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        vector<int>diff(n+1,0);
        for(int i=0;i<m;i++){
            int ll=queries[i][0];
            int rr=queries[i][1];
            int v=queries[i][2];
            diff[ll]+=v;
            diff[rr+1]-=v;
        }
        for(int i=1;i<=n;i++){
            diff[i]+=diff[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>diff[i]){
                return -1;
            }
        }
        return r+1;
    }
};