class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int l=0;
        int s=0;
        int ml=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int v=nums[i];
            if(f[v]==0)s+=v;
            f[v]++;
            while(s>=k){
                ml=min(ml,i-l+1);
                int lv=nums[l];
                f[lv]--;
                if(f[lv]==0)s-=lv;
                l++;
            }
        }
        return ml==INT_MAX?-1:ml;
    }
};