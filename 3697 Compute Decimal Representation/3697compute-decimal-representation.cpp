class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>res;
        string s=to_string(n);
        int m=s.size();
        for(int i=0;i<s.size();i++){
            int a=s[i]-'0';
            int num=a*pow(10,m-1);
            if(num!=0)res.push_back(num);
            m--;
        }
        return res;
    }
};