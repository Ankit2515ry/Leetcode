class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //O(n2) solution

        // int res=0;
        // int n=prices.size();
        // for(int i=0;i<n;i++){
        //     int temp=0;
        //     for(int j=i;j<n;j++){
        //         temp=max(temp,prices[j]-prices[i]);
        //     }
        //     res=max(res,temp);
        // }
        // return res;

        //O(n) solution uses O(n) space

        // int res=0;
        // int n=prices.size();
        // vector<int>suf(n,0);
        // suf[n-1]=prices[n-1];
        // for(int i=n-2;i>=0;i--){
        //     suf[i]=max(suf[i+1],prices[i]);
        // }
        // for(int i=0;i<n;i++){
        //     res=max(res,suf[i]-prices[i]);
        // }
        // return res;

        int res=0;
        int n=prices.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            res=max(res,prices[i]-mini);
        }
        return res;
    }
};