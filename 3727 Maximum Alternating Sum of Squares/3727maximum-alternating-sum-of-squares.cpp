class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res=0;
        long long a=0;
        long long b=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int m=(n+1)/2;
        for(int i=n-1;i>=0;i--){
            if(m>0){
                a+=(long long)(nums[i]*nums[i]);
            }else b+=(long long)(nums[i]*nums[i]);
            m--;
        }
        res=a-b;
        return res;
    }
};