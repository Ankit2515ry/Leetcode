class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a=0;
        int b=0;
        int c=0;
        for(auto it:bills){
            int x=it-5;
            if(x/20>0){
                int d=x/20;
                if(c>=d){
                    x-=d*20;
                    c-=d;
                }else{
                    x-=c*20;
                    c=0;
                }
            }
            if(x/10>0){
                int d=x/10;
                if(b>=d){
                    x-=d*10;
                    b-=d;
                }else{
                    x-=b*10;
                    b=0;
                }
            }
            if(x/5>0){
                int d=x/5;
                if(a>=d){
                    x-=d*5;
                    a-=d;
                }else{
                    x-=a*5;
                    a=0;
                }
            }
            if(x>0){
                return false;
            }
            if(it==20)c++;
            if(it==10)b++;
            if(it==5)a++;
        }
        return true;
    }
};