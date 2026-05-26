class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        //O(nlog(n)) time complexity

        // sort(nums.begin(),nums.end());
        // vector<int>res;
        // int c=1;
        // int n=nums.size();
        // int m=n/3;
        // if(n<3)return nums;
        // for(int i=1;i<n;i++){
        //     if(nums[i]==nums[i-1])c++;
        //     else{
        //         c=1;
        //     }
        //     if(c>m){
        //         if(res.empty())res.push_back(nums[i]);
        //         else {
        //             if(res.back()!=nums[i])res.push_back(nums[i]);
        //         }
        //     }
        // }
        // return res;

        //O(n) time and space complexity

        // int n=nums.size();
        // int m=n/3;
        // unordered_map<int,int>mp;
        // vector<int>res;
        // for(auto it:nums){
        //     mp[it]++;
        // }
        // for(auto it:mp){
        //     if(it.second>m)res.push_back(it.first);
        // }
        // return res;

        //moore voting
        //O(n*k) time compexity and k space compexity where k is [n/k+1] in this k=2;

        int n=nums.size();
        int m=n/3;
        int res1=0;
        int c1=0;
        int res2=1;
        int c2=0;
        for(int i=0;i<n;i++){
            if(res1==nums[i]){
                c1++;
            }else if(res2==nums[i]){
                c2++;
            }else if(c1==0){
                res1=nums[i];
                c1=1;
            }else if(c2==0){
                res2=nums[i];
                c2=1;
            }else {
                c1--;
                c2--;
            }
        }
        int f1=0;
        int f2=0;
        for(int it:nums){
            if(res1==it)f1++;
            if(res2==it)f2++;
        }
        vector<int>res;
        if(f1>m)res.push_back(res1);
        if(f2>m)res.push_back(res2);
        return res;
    }
};