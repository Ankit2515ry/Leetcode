class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //stl

        //next_permutation(nums.begin(),nums.end());

        int n=nums.size();
        int idx=n;
        int temp=INT_MAX;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                temp=nums[i+1];
                break;
            }
        }
        if (idx == n) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int succ=idx+1;
        for(int i=idx+2;i<n;i++){
            if(nums[i]>nums[idx]&&temp>=nums[i]){
                succ=i;
                temp=nums[i];
            }
        }
        swap(nums[idx],nums[succ]);
        int i=idx+1;
        int j=n-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};