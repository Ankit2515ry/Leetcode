class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int res=0;
        int x=nums.size()-1;
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        int g=nums[0];
        for(int i=0;i<n;i++){
            g=__gcd(g,nums[i]);
            pre[i]=g;
        }
        g=nums[n-1];
        for(int i=n-1;i>=0;i--){
            g=__gcd(g,nums[i]);
            suf[i]=g;
        }
        int temp=0;
        for(int i=0;i<n-1;i++){
            if(pre[i]==suf[i+1])temp++;
        }
        res=max(res,temp);
        while(x>=0){
            vector<int>num=nums;
            num.erase(num.begin()+x);
            int n=num.size();
            vector<int>pre(n,0);
            vector<int>suf(n,0);
            int g=num[0];
            for(int i=0;i<n;i++){
                g=__gcd(g,num[i]);
                pre[i]=g;
            }
            g=num[n-1];
            for(int i=n-1;i>=0;i--){
                g=__gcd(g,num[i]);
                suf[i]=g;
            }
            int temp=0;
            for(int i=0;i<n-1;i++){
                if(pre[i]==suf[i+1])temp++;
            }
            res=max(res,temp);
            x--;
        }
        return res;
    }
};