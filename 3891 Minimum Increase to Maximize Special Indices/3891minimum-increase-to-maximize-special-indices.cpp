class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        vector<long long >pos(n+2,0);
        if(n%2==1){
            for(int i=1;i<n-1;i+=2){
                res+=(nums[i]-max(nums[i-1],nums[i+1])>0)?0:(max(nums[i-1],nums[i+1])-nums[i]+1);
            }
            return res;
        }else{
            res=LLONG_MAX;
            long long a=0;
            for(int i=n-2;i>1;i-=2){
                if(!(nums[i-1]>nums[i-2]&&nums[i-1]>nums[i]))a+=(max(nums[i-2],nums[i])-nums[i-1]+1);
                pos[i]+=pos[i+2];
                if(!(nums[i]>nums[i-1]&&nums[i]>nums[i+1]))pos[i]+=(max(nums[i-1],nums[i+1])-nums[i]+1);
            }
            res=min(a,pos[2]);
            a=0;
            if(!(nums[1]>nums[0]&&nums[1]>nums[2]))a+=(max(nums[0],nums[2])-nums[1]+1);
            for(int i=3;i<n-1;i+=2){
                res=min(res,a+pos[i+1]);
                if(!(nums[i]>nums[i-1]&&nums[i]>nums[i+1]))a+=(max(nums[i-1],nums[i+1])-nums[i]+1);
            }
        }
        return res;
    }
};