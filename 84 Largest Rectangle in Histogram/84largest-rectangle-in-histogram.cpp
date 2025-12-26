class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>st;
        int res=0;
        h.push_back(0);
        for(int i=0;i<h.size();i++){
            while(!st.empty()&&h[st.top()]>h[i]){
                int height=h[st.top()];
                st.pop();
                int w=(st.empty())?i:i-st.top()-1;
                res=max(res,height*w);
            }
            st.push(i);
        }
        h.pop_back();
        return res;
    }
};