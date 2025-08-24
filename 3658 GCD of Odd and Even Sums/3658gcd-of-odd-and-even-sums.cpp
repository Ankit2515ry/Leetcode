class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumo=0;
        int sume=0;
        int k=1;
        int count=0;
        while(count<n){
            sumo+=k;
            sume+=k+1;
            k+=2;
            count++;
        }
        //cout<<sumo<<" "<<sume;
        int res=__gcd(sume,sumo);
        return res;
    }
};