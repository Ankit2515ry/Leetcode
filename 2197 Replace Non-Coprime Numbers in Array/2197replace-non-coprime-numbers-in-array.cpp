class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // vector<bool>pr(100001,true);
        // pr[0]=pr[1]=false;
        // for(int i=2;i<pr.size();i++){
        //     if(pr[i]){
        //         for(long long j=1LL*i*i;j<pr.size();j+=i){
        //             pr[j]=false;
        //         }
        //     }
        // }
        // int n=nums.size();
        // vector<int>res;
        // int pre=nums[0];
        // for(int i=1;i<n;i++){
        //     if(gcd(pre,nums[i])>1)pre=lcm(pre,nums[i]);
        //     else{
        //         res.push_back(pre);
        //         pre=nums[i];
        //     }
        // }
        // res.push_back(pre);
        // return res;
        //it would not check backgoing case like if i push 12 and its next become later 6 then i would not check for that
        vector<int>res;
        for (int x : nums) {
            res.push_back(x);
            while (res.size() > 1) {
                int a = res.back(); 
                int b = res[res.size()-2];
                int g = gcd(a, b);
                if (g == 1) break;
                res.pop_back();
                res.back() = lcm(a, b);
            }
        }
        return res;
    }
};