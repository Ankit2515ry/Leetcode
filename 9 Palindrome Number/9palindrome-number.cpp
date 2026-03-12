class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long a=x;
        long long b=0;
        while(x>0){
            long p=x%10;
            b=(b*10)+p;
            x=x/10;
        }
        if(a==b)return true;
        return false;
    }
};