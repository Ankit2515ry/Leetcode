class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,0);
        int e=0;
        int o=0;
        for(int i=n-1;i>=0;i--){
            int a=nums[i];
            if(a%2==0){
                res[i]=o;
                e++;
            }
            else {
                res[i]=e;
                o++;
            }
        }
        return res;
    }
};