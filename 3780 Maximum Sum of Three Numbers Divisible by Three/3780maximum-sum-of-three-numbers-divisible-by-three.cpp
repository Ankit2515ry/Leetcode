class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>k[3];
        for(auto &it:nums)k[it%3].push_back(it);
        for(int i=0;i<3;i++){
            sort(k[i].rbegin(),k[i].rend());
        }
        int res=0;
        if(k[0].size()>=3){
            res=max(res,k[0][0]+k[0][1]+k[0][2]);
        }
        if(k[1].size()>=3){
            res=max(res,k[1][0]+k[1][1]+k[1][2]);
        }
        if(k[2].size()>=3){
            res=max(res,k[2][0]+k[2][1]+k[2][2]);
        }
        if(!k[0].empty()&&!k[1].empty()&&!k[2].empty()){
            res=max(res,k[0][0]+k[1][0]+k[2][0]);
        }
        return res;
    }
};