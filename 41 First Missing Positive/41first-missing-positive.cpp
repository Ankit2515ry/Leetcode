class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()&&nums[i]<=0){
            i++;
        }
        set<int>st;
        for(i;i<nums.size();i++){
            if(!st.count(nums[i]))st.insert(nums[i]);
        }
        int temp=1;
        for(auto &it:st){
            if(it!=temp)return temp;
            temp++;
        }
        return temp;
    }
};