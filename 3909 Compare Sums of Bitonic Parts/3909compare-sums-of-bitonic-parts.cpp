class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        long long in=nums[0];
        long long de=nums[n-1];
        int i=1;
        while(i<n&&nums[i]>nums[i-1]){
            in+=nums[i];
            i++;
        }
        i=n-2;
        while(i>=0&&nums[i]>nums[i+1]){
            de+=nums[i];
            i--;
        }
        if(in==de)return -1;
        else if(in>de)return 0;
        return 1;
    }
};