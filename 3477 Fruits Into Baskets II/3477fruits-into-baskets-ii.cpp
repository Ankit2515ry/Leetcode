class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int res=0;
        for(int i=0;i<n;i++){
            bool f=false;
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j]){
                    f=true;
                    baskets[j]=0;
                    break;
                }
            }
            if(f==false)res++;
        }
        return res;
    }
};