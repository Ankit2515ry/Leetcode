class Solution {
public:
    long long countDistinct(long long n) {
        long long res=0;
        string s=to_string(n);
        int m=s.size();
        long long a=9;
        for(int i=1;i<m;i++){
            res+=a;
            a*=9;
        }
        for(int i=0;i<m;i++){
            int d=s[i]-'0';
            int c=0;
            for(int j=1;j<=9;j++){
                if(j<d)c++;
            }
            int r=m-i-1;
            res+=1LL*c*pow(9,r);
            if(d==0)return res;
        }
        res++;
        return res;
    }
};