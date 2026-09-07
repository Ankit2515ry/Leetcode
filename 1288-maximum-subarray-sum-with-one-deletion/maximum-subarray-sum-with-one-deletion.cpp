class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=max(arr[i],pre[i-1]+arr[i]);
        }
        vector<int>suf(n,0);
        suf[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=max(arr[i],suf[i+1]+arr[i]);
        }
        int res=max(arr[0],arr[n-1]);
        for(int i=1;i<n-1;i++){
            if(arr[i]<0){
                res=max({res,pre[i],suf[i]});
                res=max(res,pre[i-1]+suf[i+1]);
            }else{
                res=max({res,pre[i],suf[i]});
                res=max(res,pre[i-1]+arr[i]+suf[i+1]);
            }
        }
        return res;
    }
};