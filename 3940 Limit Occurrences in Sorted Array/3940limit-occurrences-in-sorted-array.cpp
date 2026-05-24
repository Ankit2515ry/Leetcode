class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        vector<int> ans;
        for(auto it:mp){
            int val = it.first;
            int x=it.second;
            int y=k;
            while(x--&&y--){
                ans.push_back(val);
            }
        }
        return ans;
    }
};