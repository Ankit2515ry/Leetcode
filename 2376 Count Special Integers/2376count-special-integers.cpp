class Solution {
public:
    // bool check(string s){
    //     unordered_set<char>st;
    //     for(auto it:s){
    //         if(st.count(it))return false;
    //         st.insert(it);
    //     }
    //     return true;
    // }
    int countSpecialNumbers(int n) {
        // int res=0;
        // for(int i=1;i<=n;i++){
        //     if(check(to_string(i)))res++;
        // }
        // return res;
        int res=0;
        string s=to_string(n);
        if(s.size()==1)return n;
        for(int i=1;i<s.size();i++){
            int sum=9;
            int x=9;
            int y=i-1;
            while(y>0){
                sum*=x;
                x--;
                y--;
            }
            res+=sum;
        }
        unordered_set<int>used;
        for(int i=0;i<s.size();i++){
            int digit=s[i]-'0';
            for(int d=(i==0?1:0);d<digit;d++){
                if(used.count(d))continue;
                int sum=1;
                int x=9-i;
                int y=s.size()-i-1;
                while(y>0){
                    sum*=x;
                    x--;
                    y--;
                }
                res+=sum;
            }
            if(used.count(digit))break;
            used.insert(digit);
            if(i==s.size()-1)res++;
        }
        return res;
    }
};