class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res="";
        if(sum>9*num)return res;
        for(int i=0;i<num;i++){
            int a=min(9,sum);
            res+=char(a+'0');
            sum-=a;
        }
        return res;
    }
};