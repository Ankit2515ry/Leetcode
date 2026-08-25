// class Solution {
// public:
//     vector<pair<int,int>>p;
//     bool solve(vector<int>& q,int mask,int idx){
//         int n=q.size();
//         if(mask==(1<<n)-1)return true;
//         if(idx>=p.size())return false;
//         bool res=false;
//         for(int i=0;i<n;i++){
//             if(!((mask>>i)&1)){
//                 int req=q[i];
//                 int avail=p[idx].second;
//                 int rem=avail-req;
//                 if(rem>=0){
//                     p[idx].second=rem;
//                     res|=solve(q,mask|(1<<i),idx);
//                     res|=solve(q,mask|(1<<i),idx+1);
//                     p[idx].second=avail;
//                 }
//             }
//         }
//         res|=solve(q,mask,idx+1);
//         return res;
//     }
//     bool canDistribute(vector<int>& nums, vector<int>& quantity) {    
//         unordered_map<int,int>mp;
//         for(auto it:nums)mp[it]++;
//         for(auto it:mp)p.push_back({it.first,it.second});
//         return solve(quantity,0,0);    
//     }
// };

class Solution {
public:
    vector<int>mask;
    vector<int>freq;
    int dp[1<<10][50];
    bool solve(int m,int idx){
        if(m==0)return true;
        if(idx==freq.size())return false;
        if(dp[m][idx]!=-1)return dp[m][idx];
        bool res=false;
        res|=solve(m,idx+1);
        int sub=m;
        while(sub){
            if(mask[sub]<=freq[idx])res|=solve(m^sub,idx+1);
            sub=(sub-1)&m;
        }
        return dp[m][idx]=res;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int n=quantity.size();
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto [k,v]:mp){
            freq.push_back(v);
        }
        int nm=1<<n;
        for(int i=0;i<nm;i++){
            int val=0;
            for(int j=0;j<quantity.size();j++){
                if((i>>j)&1)val+=quantity[j];
            }
            mask.push_back(val);
        }
        memset(dp,-1,sizeof(dp));
        return solve(nm-1,0);
    }
};