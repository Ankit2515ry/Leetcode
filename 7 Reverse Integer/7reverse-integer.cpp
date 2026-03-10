class Solution {
public:
    int reverse(int x) {
        long long res=0;
        long long a=x;
        a=abs(a);
        while(a>0){
            long long d=a%10;
            res=(res*10)+d;
            a/=10;
        }
        if(x<0)res=res*-1;
        if(res<INT_MIN||res>INT_MAX)return 0;
        return res;
    }
};