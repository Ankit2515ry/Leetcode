class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int res=0;
        int count=0;
        bool f=false;
        if(s[0]=='1')count++;
        for(int i=1;i<n;i++){
            if(s[i]=='1')count++;
            if(s[i]=='0'&&s[i-1]=='1')f=true;
            if(f){
                res+=count;
                f=false;
            }
        }
        return res;
    }
};