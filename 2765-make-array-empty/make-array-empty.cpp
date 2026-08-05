class Solution {
public:
    int sz;
    vector<int>bit;
    void update(int i,int v){
        while(i<sz){
            bit[i]+=v;
            i+=i&(-i);
        }
    }
    int query(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=i&(-i);
        }
        return sum;
    }
    int range(int l,int r){
        if(l>r)return 0;
        return query(r)-query(l-1);
    }
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({nums[i],i+1});
        }
        sort(p.begin(),p.end());
        // just checking wraparound for min operations
        // long long ans=n;
        // for(int i=1;i<n;i++){
        //     if(p[i].second<p[i-1].second){
        //         ans+=(n-i);
        //     }
        // }
        // return ans;

        // using fenwick tree
        sz=n+2;
        bit.assign(sz,0);
        long long res=0;
        for(int i=0;i<n;i++){
            update(i+1,1);
        }
        int curr=1;
        for(int i=0;i<n;i++){
            int next=p[i].second;
            if(curr<=next){
                res+=range(curr,next-1);
            }else{
                res+=range(curr,n)+range(1,next-1);
            }
            res++;
            update(next,-1);
            curr=next;
        }
        return res;
    }
};