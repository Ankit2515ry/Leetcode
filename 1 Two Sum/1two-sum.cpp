class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //O(n2) time complexity
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target)return {i,j};
        //     }
        // }
        // return {-1,-1};

        //O(n) time and space complexity
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.count(target-nums[i]))return {mp[target-nums[i]],i};
            else mp[nums[i]]=i;
        }
        return {-1,-1};


    }
};