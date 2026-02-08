class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>st;
        for(auto &it:nums){
            long long temp=it;
            st.push(temp);
            while(st.size()>=2){
                temp=st.top();
                st.pop();
                if(st.top()==temp){
                    st.pop();
                    st.push(2*temp);
                }else {
                    st.push(temp);
                    break;
                }
            }
        }
        vector<long long>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};