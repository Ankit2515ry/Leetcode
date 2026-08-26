class Solution {
public:
    long long solve(vector<int>& coins, long long k){
        int n=coins.size();
        long long res=0;
        for(int mask=1;mask<(1<<n);mask++){
            long long c_lcm=1;
            int bit_c=__builtin_popcount(mask);
            bool f=false;
            for(int i=0;i<n;i++){
                if((mask>>i)&1){
                    long long g=__gcd(c_lcm,1LL*coins[i]);
                    if((double)((c_lcm/g)*coins[i])>(double)k){
                        f=true;
                        break;
                    }
                    c_lcm=lcm(c_lcm,1LL*coins[i]);
                    if(c_lcm>k){
                        f=true;
                        break;
                    }
                }
            }
            if(f)continue;
            if(bit_c%2!=0){
                res+=k/c_lcm;
            }else{
                res-=k/c_lcm;
            }
        }
        return res;
    }
    long long findKthSmallest(vector<int>& coins, int kk) {
        // vector<long long>temp;
        // int n=coins.size();
        // sort(coins.begin(),coins.end());
        // long long maxi=1LL*k*coins[n-1];
        // for(auto it:coins){
        //     long long x=1LL*it;
        //     while(x<=maxi){
        //         temp.push_back(x);
        //         x+=it;
        //     }
        // }
        // sort(temp.begin(),temp.end());
        // temp.erase(unique(temp.begin(),temp.end()));
        // //for(auto it:temp)cout<<it<<" ";
        // return temp[k-1];
        long long k=1LL*kk;
        long long l=0;
        long long r=0;
        int n=coins.size();
        sort(coins.begin(),coins.end());
        r=1LL*k*coins[n-1];
        while(l<r){
            long long mid=(r-l)/2+l;
            long long mc=solve(coins,mid);
            if(mc>=k)r=mid;
            else l=mid+1;
        }
        return r;
    }
};