class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0||k>n)return false;
        int l=n/k;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int f=0;
        for(auto it:mp){
            f=max(f,it.second);
        }
        if(f>l)return false;
        return true;
    }
};