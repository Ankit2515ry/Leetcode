class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        for(auto it:nums){
            r+=it;
            l=max(l,it);
        }
        while(l<r){
            int mid=(r-l)/2+l;
            int p=0;
            int sum=0;
            for(auto it:nums){
                if(sum+it>mid){
                    p++;
                    sum=it;
                }else {
                    sum+=it;
                }
            }
            p++;
            if(p>k){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return r;
    }
};