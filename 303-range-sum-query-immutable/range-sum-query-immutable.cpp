class NumArray {
public:
    int n;
    vector<int>bit;
    NumArray(vector<int>& nums) {
        n=nums.size();
        bit.assign(n+1,0);
        for(int i=0;i<n;i++){
            update(i+1,nums[i]);
        }
    }
    void update(int i,int val){
        while(i<=n){
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
    int sumRange(int left, int right) {
        return query(right+1)-query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */