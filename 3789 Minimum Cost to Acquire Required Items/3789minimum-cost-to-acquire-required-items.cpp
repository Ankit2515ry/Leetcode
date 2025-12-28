class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // long long res=LLONG_MAX;
        // int temp=max(need1,need2);
        // for(int i=0;i<=temp;i++){
        //     long long a=max(0,(need1-i));
        //     long long b=max(0,(need2-i));
        //     long long c=1LL*i*costBoth+1LL*a*cost1+1LL*b*cost2;
        //     res=min(res,c);
        // }
        // return res;
        long long a=1LL*need1*cost1+1LL*need2*cost2;
        int temp = min(need1, need2);
        long long b=1LL*temp*costBoth+1LL*(need1-temp)*cost1+1LL*(need2-temp)*cost2;
        int temp2=max(need1,need2);
        long long c=1LL*temp2*costBoth;
        return min({a,b,c});
    }
};