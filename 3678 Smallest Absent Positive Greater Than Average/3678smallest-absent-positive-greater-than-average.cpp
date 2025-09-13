class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int av=0;
        int n=nums.size();
        unordered_set<int>st;
        for(auto &it:nums){
            av+=it;
            st.insert(it);
        }
        av=av/n;
        int c=av+1;
        if(c<=0)c = 1;
        while(st.find(c)!=st.end())c++;
        return c;
    }
};