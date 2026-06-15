class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        long long res=-1e10;
        vector<int>s=nums;
        sort(s.begin(),s.end());
        multiset<int>c;
        multiset<int>o;
        int n=nums.size();
        for(int i=0;i<n;i++){
            c.clear();
            o.clear();
            long long sum=0;
            for(int j=0;j<(n-k);j++){
                o.insert(s[j]);
            }
            for(int j=(n-k);j<n;j++){
                c.insert(s[j]);
            }
            for(int j=i;j<n;j++){
                if(!o.empty()){
                    int v;
                    auto it=o.find(nums[j]);
                    if(it!=o.end()){
                        v=*it;
                        o.erase(it);
                    }else{
                        it=prev(o.end());
                        v=*it;
                        o.erase(it);
                    }
                    c.insert(v);
                }
                auto it=prev(c.end());
                sum+=*it;
                res=max(res,sum);
                c.erase(it);
            }
        }
        return res;
    }
};