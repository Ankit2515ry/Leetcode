class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    unordered_set<int>st;
    SmallestInfiniteSet() {
       // priority_queue<int>pq;
        for(int i=1;i<=1000;i++){
            pq.push(i);
            st.insert(i);
        }
    }
    
    int popSmallest() {
        int r=0;
        r=pq.top();
        st.erase(r);
        pq.pop();
        return r;
    }
    
    void addBack(int num) {
        if(!st.count(num)){
            pq.push(num);
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */