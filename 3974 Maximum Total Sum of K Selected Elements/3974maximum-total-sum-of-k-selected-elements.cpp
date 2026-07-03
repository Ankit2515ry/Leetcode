class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        vector<long long>temp(n);
        for(int i=0;i<n;i++){
            temp[i]=1LL*nums[i];
        }
        sort(temp.begin(),temp.end());
        for(int i=n-1;i>=0;i--){
            if(mul>0){
                temp[i]*=mul;
                mul--;
            }else break;
        }
        int i=n-1;
        long long res=0;
        while(k--){
            res+=temp[i];
            i--;
        }
        return res;
    }
};