class Solution {
public:
    int sz=1e5;
    vector<int>bit;
    void update(int i,int val){
        while(i<sz){
            bit[i]+=val;
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
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>f(sz,0);
        for(auto it:nums){
            int idx=1e4+it+1;
            f[idx]++;
        }
        bit.assign(sz,0);
        for(int i=1;i<sz;i++){
            update(i,f[i]);
        }
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int idx=1e4+nums[i]+1;
            int temp=query(idx-1);
            res[i]=temp;
            update(idx,-1);
        }
        return res;
    }
};