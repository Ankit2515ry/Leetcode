class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pair<int,int>p={it.second,it.first};
            pq.push(p);
        }
        vector<int>res;
        int x=k;
        while(x--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};