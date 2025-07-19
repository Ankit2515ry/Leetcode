class Solution {
public:
    bool isPrime(int n){
        //6k rule check 6k-1 and 6k+1 -> if(n%i==0||n%(i+2)) since i start from 5;
        if(n==2||n==3)return true;
        if(n%2==0||n%3==0)return false;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0||n%(i+2)==0)return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        long long prime_sum=0;
        long long other_sum=0;
        if(nums.size()==1)return abs(nums[0]);
        other_sum+=nums[0]+nums[1];
        for(int i=2;i<nums.size();i++){
            if(isPrime(i))prime_sum+=nums[i];
            else other_sum+=nums[i];
        }
        return abs(prime_sum-other_sum);
    }
};