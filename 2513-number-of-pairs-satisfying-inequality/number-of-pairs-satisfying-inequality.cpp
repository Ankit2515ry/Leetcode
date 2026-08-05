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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        sz=1e5;
        bit.assign(sz,0);
        long long res=0;
        int offset=5*1e4;
        for(int i=0;i<n;i++){
            int v=offset+nums1[i]-nums2[i];
            int temp=query(v);
            res+=temp;
            v-=diff;
            update(v,1);
        }
        return res;
    }
};