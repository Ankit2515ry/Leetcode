class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int r=1;
        for(auto it:nums)r=max(r,it);
        while(l<r){
            int mid=(r-l)/2+l;
            int sum=0;
            for(auto it:nums){
                sum+=it/mid;
                if(it%mid!=0)sum++;
            }
            if(sum>threshold)l=mid+1;
            else r=mid;
        }
        return r;
    }
};