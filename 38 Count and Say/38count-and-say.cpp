class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        n--;
        while(n--){
            string temp="";
            int c=1;
            for(int i=1;i<s.size();i++){
                if(s[i]!=s[i-1]){
                    temp+=('0'+c);
                    temp+=s[i-1];
                    c=1;
                }else c++;
            }
            temp+=('0'+c);
            temp+=s[s.size()-1];
            s=temp;
        }
        return s;

    }
};