class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int>res;
        set<int>st;
        for(auto &it:nums){
            if(st.find(it)==st.end())res.push_back(it);
            st.insert(it);
        }
        int n=st.size();
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        if(n<=k)return res;
        while(res.size()>k){
            res.pop_back();
        }
        return res;
    }
};