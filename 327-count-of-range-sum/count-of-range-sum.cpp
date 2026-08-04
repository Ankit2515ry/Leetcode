class Solution {
public:
    int sz;
    vector<long long>bit;
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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long long>pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        vector<long long>values;
        for(auto it:pre){
            values.push_back(it);
            values.push_back(it-upper);
            values.push_back(it-lower);
        }
        sort(values.begin(),values.end());
        values.erase(unique(values.begin(),values.end()),values.end());
        sz=values.size()+2;
        bit.assign(sz,0);
        long long res=0;
        for(auto it:pre){
            int r=lower_bound(values.begin(),values.end(),it-lower)-values.begin()+1;
            int l=lower_bound(values.begin(),values.end(),it-upper)-values.begin()+1;
            res+=query(r)-query(l-1);
            int idx=lower_bound(values.begin(),values.end(),it)-values.begin()+1;
            update(idx,1);
        }
        return res;
    }
};