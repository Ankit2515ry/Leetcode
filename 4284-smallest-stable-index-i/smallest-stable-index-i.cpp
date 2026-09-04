class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxx(n,0);
        vector<int>minn(n,INT_MAX);
        int temp=0;
        for(int i=0;i<n;i++){
            temp=max(temp,nums[i]);
            maxx[i]=temp;
        }
        temp=INT_MAX;
        for(int i=n-1;i>=0;i--){
            temp=min(temp,nums[i]);
            minn[i]=temp;
        }
        for(int i=0;i<n;i++){
            if(maxx[i]-minn[i]<=k)return i;
        }
        return -1;
    }
};