class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int o=0;
        int e=0;
        int mine=INT_MAX;
        int mino=INT_MAX;
        for(auto it:nums1){
            if(it%2==0){
                e++;
                mine=min(mine,it);
            }else{
                o++;
                mino=min(mino,it);
            }
        }
        if(e==n||o==n)return true;
        if(mino<mine)return true;
        return false;
    }
};