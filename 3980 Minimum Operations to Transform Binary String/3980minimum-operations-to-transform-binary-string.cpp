class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        if(n==1){
            if(s1[0]=='1'&&s2[0]=='0')return -1;
        }
        int i=0;
        int res=0;
        while(i<n){
            if(s1[i]=='0'&&s2[i]=='1'){
                res++;
                i++;
            }else if(s1[i]=='1'&&s2[i]=='0'){
                if(i+1<n&&s1[i+1]=='1'&&s2[i+1]=='0'){
                    res+=1;
                    i+=2;
                }else {
                    res+=2;
                    i++;
                }
            }else i++;
        }
        return res;
    }
};