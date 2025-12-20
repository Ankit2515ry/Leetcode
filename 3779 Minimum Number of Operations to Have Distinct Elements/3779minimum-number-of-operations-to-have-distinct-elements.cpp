class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        int x=0;
        for(auto &it:nums){
            mp[it]++;
            if(mp[it]>1)x++;
        }
        int res=0;
        if(x==0)return res;
        for(int i=0;i<nums.size();i+=3){
            if(mp[nums[i]]>1){
                mp[nums[i]]--;
                x--;
            }
            if(i+1<nums.size()&&mp[nums[i+1]]>1){
                mp[nums[i+1]]--;
                x--;
            }
            if(i+2<nums.size()&&mp[nums[i+2]]>1){
                mp[nums[i+2]]--;
                x--;
            }
            res++;
            if(x==0)return res;
        }
        return res;
    }
};