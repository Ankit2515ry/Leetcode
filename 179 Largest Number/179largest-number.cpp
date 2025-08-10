class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>st;
        for(auto it:nums){
            st.push_back(to_string(it));
        }
        sort(st.begin(),st.end(),[&](auto a,auto b){
            return a+b>b+a;
        });
        string res="";
        for(auto it:st){
            res+=it;
        }
        bool f=false;
        for(auto it:res)if(it!='0')f=true;
        if(f)return res;
        return "0";
    }
};