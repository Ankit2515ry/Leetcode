class Solution {
public:
    long long mod=1e9+7;
    long long solve(long long n){
        long long t1=n;
        long long t2=n+1;
        if(t1%2==0)t1/=2;
        else t2/=2;
        return ((t1%mod)*(t2%mod))%mod;
    }
    int minimumCost(vector<int>& nums, int k) {
        long long res=0;
        long long c=k;
        long long cost=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=c){
                c-=nums[i];
            }else{
                long long temp=nums[i]-c;
                long long x=temp/k;
                if(temp%k!=0)x++;
                c+=k*x;
                c-=nums[i];
                long long pre=solve(cost);
                cost+=x;
                long long curr=solve(cost);
                res=(res+(curr-pre+mod)%mod)%mod;
            }
        }
        return res;
    }
};