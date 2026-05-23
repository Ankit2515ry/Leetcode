class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int res=INT_MAX;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y)continue;
                int c=0;
                for(int i=0;i<n;i++){
                    int r=nums[i]%k;
                    int t=x;
                    if(i%2==1)t=y;
                    int diff=abs(r-t);
                    c+=min(diff,k-diff);
                }
                res=min(res,c);
            }
        }
        return res;
    }
};