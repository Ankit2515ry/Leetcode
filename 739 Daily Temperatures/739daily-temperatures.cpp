class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n=tem.size();
        vector<int>res(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&tem[i]>tem[st.top()]){
                int idx=st.top();
                st.pop();
                res[idx]=i-idx;
            }
            st.push(i);
        }
        return res;
    }
};