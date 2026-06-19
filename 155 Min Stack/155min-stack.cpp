class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int value) {
        int mini=INT_MAX;
        if(!st.empty())mini=st.top().second;
        mini=min(mini,value);
        st.push({value,mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int v=st.top().first;
        return v;
    }
    
    int getMin() {
        int v=st.top().second;
        return v;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */