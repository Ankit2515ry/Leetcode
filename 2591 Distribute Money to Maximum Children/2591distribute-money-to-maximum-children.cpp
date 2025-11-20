class Solution {
public:
    int distMoney(int money, int children) {
        int res=-1;
        money-=children;
        if(money<0)return res;
        if(money<7)return 0;
        if(money>children*7)return children-1;
        if(money/7==children-1&&money%7==3)return children-2;
        return money/7;
    }
};