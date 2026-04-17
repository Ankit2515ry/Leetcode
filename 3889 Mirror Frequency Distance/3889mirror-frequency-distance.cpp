class Solution {
public:
    int mirrorFrequency(string s) {
        int res=0;
        unordered_map<char,int>mps;
        for(int i=0;i<s.size();i++){
            mps[s[i]]++;
        }
        unordered_set<char>st;
        for(auto it:mps){
            auto a=it.first;
            if(st.count(a))continue;
            char b=a;
            if(a >= 'a' && a <= 'z'){
                b='a'+(25-(a-'a'));
            }else{
                b='0'+(9-(a-'0'));
            }
            int fb = mps.count(b) ? mps[b] : 0;
            res += abs(mps[a] - fb);
            st.insert(a);
            st.insert(b);
        }
        return res;
    }
};