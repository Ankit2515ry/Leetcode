class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        for(auto it:nums2){
            while(!st.empty()&&st.top()<it){
                mp[st.top()]=it;
                st.pop();
            }
            st.push(it);
        }
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        int n=nums1.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i]=mp[nums1[i]];
        }
        return res;
    }
};