class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        long long l=0;
        long long r=0;
        for(int i=0;i<n/2;i++)l+=nums[i];
        for(int i=n/2;i<n;i++)r+=nums[i];
        if(l>r)res++;
        // cout<<l<<" "<<r<<endl;
        for(int i=n/2;i<n-1;i++){
            l-=nums[i-n/2];
            l+=nums[i];
            r+=nums[i-n/2];
            r-=nums[i];
            if(l!=r)res++;
            // cout<<l<<" "<<r<<endl;
        }
        l-=nums[n/2-1];
        l+=nums[n-1];
        r+=nums[n/2-1];
        r-=nums[n-1];
        if(l>r)res++;
        // cout<<l<<" "<<r<<endl;
        return res;
    }
};