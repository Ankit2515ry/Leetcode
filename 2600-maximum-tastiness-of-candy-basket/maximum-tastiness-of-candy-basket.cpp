class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        int l=0;
        int r=0;
        sort(price.begin(),price.end());
        r=price[n-1];
        int ans = 0;
        while(l<=r){
            int mid=(r-l)/2+l;
            int c=1;
            int np=price[0]+mid;
            for(auto it:price){
                if(it>=np){
                    c++;
                    np=it+mid;
                }
            }
            if(c<k){
                r=mid-1;
            }else{
                ans=max(ans,mid);
                l=mid+1;
            }
        }
        return ans;
    }
};