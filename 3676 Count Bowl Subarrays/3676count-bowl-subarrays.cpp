class Solution {
public:
    bool check(int i,int j,vector<int>& nums){
        int m=INT_MIN;
        if(j-i+1<3)return false;
        for(int k=i+1;k<j;k++)m=max(nums[k],m);
        int mini=min(nums[i],nums[j]);
        if(mini>m) return true;
        return false;
    }
    long long bowlSubarrays(vector<int>& nums) {
        long long res=0;
        /*for(int i=0;i<nums.size();i++){
            int m=nums[i+1];
            for(int j=i+2;j<nums.size();j++){
                int mini=min(nums[i],nums[j]);
                if(mini>m)res++;
                m=max(m,nums[j]);
                //if(check(i,j,nums))res++;
            }
        }*/
        stack<int>st;
        for(auto &it:nums){
            while(!st.empty()&&st.top()<it){
                st.pop();
                if(!st.empty())res++;
            }
            st.push(it);
        }
        return res;
    }
};