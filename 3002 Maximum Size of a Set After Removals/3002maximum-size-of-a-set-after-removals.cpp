class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_set<int>st;
        for(auto &it:nums1)st.insert(it);
        int u1=st.size();
        int ea=0;
        int u2=0;
        unordered_set<int>st2;
        for(auto &it:nums2){
            if(st.count(it)&&!st2.count(it))ea++;
            if(!st.count(it)){
                st.insert(it);
                u2++;
            }
            st2.insert(it);
        }
        //cout<<ea<<" "<<u2;
        int res=0;
        if(u1>=n/2)res+=n/2;
        if(u1<n/2)res+=u1;
        if(u2>=n/2)res+=n/2;
        if(u2<n/2){
            if((u1-(n/2))>0){
                int x=min(ea,(u1-(n/2)));
                if(u2+x>=n/2)res+=n/2;
                else{
                    res+=u2+x;
                }
            }else{
                res+=u2;
            }
        }
        return res;
    }
};