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
    bool isIdealPermutation(vector<int>& nums) {
        sz=1e5+2;
        bit.assign(sz,0);
        long long localinv=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i + 1])localinv++;
        }
        long long globalinv=0;
        for(int i=0;i<n;i++){
            int temp=i-query(nums[i]);
            globalinv+=temp;
            update(nums[i]+1,1);
        }
        return (localinv==globalinv);
    }
};