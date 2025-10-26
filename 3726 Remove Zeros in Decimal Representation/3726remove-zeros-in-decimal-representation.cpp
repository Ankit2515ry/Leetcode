class Solution {
public:
    long long removeZeros(long long n) {
        string s=to_string(n);
        string a="";
        for(auto &it:s){
            if(it!='0'){
                a+=it;
            }
        }
        long long res=stoll(a);
        return res;
    }
};