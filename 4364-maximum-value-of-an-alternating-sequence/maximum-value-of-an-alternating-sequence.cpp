class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1)return s;
        long long b=n/2;
        long long res=s+(1LL*b*m)-max(b-1,1LL*0);
        return res;
    }
};