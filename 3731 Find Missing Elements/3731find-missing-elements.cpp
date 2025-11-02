class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        unordered_set<int>st;
        for(auto &it:nums)st.insert(it);
        int n=nums.size();
        int a=nums[0];
        int b=nums[n-1];
        for(int i=a;i<b;i++){
            if(st.find(i)==st.end())res.push_back(i);
        }
        return res;
    }
};