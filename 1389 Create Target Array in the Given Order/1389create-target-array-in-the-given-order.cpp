class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            int m=res.size();
            int idx=index[i];
            stack<int>st;
            int j=m-1;
            while(j>=idx){
                st.push(res.back());
                res.pop_back();
                j--;
            }
            res.push_back(nums[i]);
            while(!st.empty()){
                res.push_back(st.top());
                st.pop();
            }
        }
        return res;
    }
};