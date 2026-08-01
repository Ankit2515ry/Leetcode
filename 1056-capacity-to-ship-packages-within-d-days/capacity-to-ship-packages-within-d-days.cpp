class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=0;
        int r=0;
        for(auto it:weights){
            r+=it;
            l=max(l,it);
        }
        while(l<r){
            int mid=(r-l)/2+l;
            int d=0;
            int sum=0;
            for(auto it:weights){
                if(sum+it>mid){
                    d++;
                    sum=it;
                }else{
                    sum+=it;
                }
            }
            d++;
            if(d>days){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        //cout<<l<<" "<<r<<endl;
        return r;
    }
};