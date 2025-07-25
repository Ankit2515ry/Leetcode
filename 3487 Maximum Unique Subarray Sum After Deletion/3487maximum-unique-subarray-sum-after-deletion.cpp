class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int temp=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)st.insert(nums[i]);
            else{
                temp=max(temp,nums[i]);
            }
        }
        if(st.empty())return temp;
        int sum=0;
        for(auto it:st)sum+=it;
        return sum;
    }
};