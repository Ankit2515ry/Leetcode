class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>res;
        vector<pair<int,int>>p;
        for(auto it:buildings){
            int l=it[0];
            int r=it[1];
            int h=it[2];
            p.push_back({l,-h});
            p.push_back({r,h});
        }
        sort(p.begin(),p.end());
        multiset<int>st;
        st.insert(0);
        int curr=0;
        for(auto it:p){
            int idx=it.first;
            int h=it.second;
            if(h<0){
                st.insert(-h);
            }else{
                st.erase(st.find(h));
            }
            int val=*st.rbegin();
            if(val!=curr){
                curr=val;
                res.push_back({idx,curr});
            }
        }
        return res;
    }
};