class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res(n);
        if(k==n||k==0)return;
        else if(k<n){
            for(int i=0;i<n;i++){
                res[i]=nums[(1LL*(n-k+i))%n];
            }
            nums=res;
        }
        else{
            k%=n;
            for(int i=0;i<n;i++){
                res[i]=nums[(1LL*(n-k+i))%n];
            }
            nums=res;
        }
        // k %= n;
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());
    }
};