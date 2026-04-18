class Solution {
public:
    int kk;
    vector<vector<vector<long long>>>dp;
    long long solve(vector<int>&pos,int i,int c,int op){
        int n=pos.size();
        if(op>=kk)return 0;
        if(i>=n)return 1e18;
        if(dp[i][c][op]!=-1)return dp[i][c][op];
        long long a=1e18;
        a=min(a,solve(pos,i+1,0,op));
        if(!c){
            a=min(a,pos[i]+solve(pos,i+1,1,op+1));
        }
        //cout<<i<<" "<<op<<" "<<a<<endl;
        return dp[i][c][op]=a;
    }
    long long solve2(vector<int>&pos,int i,int c,int op){
        int n=pos.size()-1;
        if(op>=kk)return 0;
        if(i>=n)return 1e18;
        if(dp[i][c][op]!=-1)return dp[i][c][op];
        long long a=1e18;
        a=min(a,solve2(pos,i+1,0,op));
        if(!c){
            a=min(a,pos[i]+solve2(pos,i+1,1,op+1));
        }
        //cout<<i<<" "<<op<<" "<<a<<endl;
        return dp[i][c][op]=a;
    }
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        kk=k;
        if(k>(n/2))return -1;
        vector<int>pos(n,0);
        pos[0]=(nums[0]<=nums[1]||nums[0]<=nums[n-1])?(max(nums[1],nums[n-1])-nums[0]+1):0;
        pos[n-1]=(nums[n-1]<=nums[n-2]||nums[n-1]<=nums[0])?(max(nums[n-2],nums[0])-nums[n-1]+1):0;
        for(int i=1;i<n-1;i++){
            pos[i]=(nums[i]<=nums[i-1]||nums[i]<=nums[i+1])?(max(nums[i-1],nums[i+1])-nums[i]+1):0;
        }
        //for(auto it:pos)cout<<it<<" ";
        //cout<<endl;
        dp.assign(n, vector<vector<long long>>(2, vector<long long>(kk + 1, -1)));
        long long res= solve(pos,1,0,0);
        dp.assign(n, vector<vector<long long>>(2, vector<long long>(kk + 1, -1)));
        res=min(res,solve2(pos,0,0,0));
        return res;
    }
};