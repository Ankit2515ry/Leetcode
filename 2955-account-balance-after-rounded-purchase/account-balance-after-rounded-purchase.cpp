class Solution {
public:
    int accountBalanceAfterPurchase(int a) {
        if(a<5)return 100;
        if(a>=5&&a<15)return 90;
        if(a==100)return 0;
        int s=a%10;
        a/=10;
        int f=a;
        f*=10;
        if(s<5)return 100-f;
        f+=10;
        return 100-f;
    }
};