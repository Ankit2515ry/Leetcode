class Solution {
public:
    int countPrimes(int n) {
        //sieve of eratosthenes
        vector<bool>vis(n,true);
        if(n<2)return 0;
        vis[0]=vis[1]=false;
        int count=0;
        for(long long i=2;i<n;i++){
            if(vis[i]==true){
                count++;
                for(long long j=i*i;j<n;j+=i){
                    vis[j]=false;
                }
            }
        }
        return count;
    }
};