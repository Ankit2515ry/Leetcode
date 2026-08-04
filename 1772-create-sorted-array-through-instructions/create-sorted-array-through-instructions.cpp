class Solution {
public:
    int mod=1e9+7;
    int sz;
    vector<int>bit;
    void update(int i,int v){
        while(i<sz){
            bit[i]+=v;
            i+=i&(-i);
        }
    }
    long long query(int i){
        long long sum=0;
        while(i>0){
            sum+=bit[i];
            i-=i&(-i);
        }
        return sum;
    }
    int createSortedArray(vector<int>& instructions) {
        sz=1e5+2;
        bit.assign(sz,0);
        long long res=0;
        long long n=0;
        for(auto it:instructions){
            long long l=query(it-1);
            long long r=n-query(it);
            res=(res+min(l,r))%mod;
            update(it,1);
            n++;
        }
        return res%mod;
    }
};