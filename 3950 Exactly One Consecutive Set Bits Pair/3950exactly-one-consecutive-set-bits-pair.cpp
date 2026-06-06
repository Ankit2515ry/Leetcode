class Solution {
public:
    bool consecutiveSetBits(int n) {
        int c=0;
        while(n){
            if((1&n)&&(1&n>>1))c++;
            n=n>>1;
        }
        if(c==1)return true;
        return false;
    }
};