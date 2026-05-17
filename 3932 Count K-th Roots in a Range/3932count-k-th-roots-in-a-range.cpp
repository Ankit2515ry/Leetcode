class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1)return (r-l+1);
        int i=0;
        int res=0;
        while(1LL*pow(i,k)<=r){
            if(1LL*pow(i,k)>=l)res++;
            i++;
        }
        return res;
    }
};