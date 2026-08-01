class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(1LL*n<1LL*m*k)return -1;
        int l=1;
        int r=1;
        for(auto it:bloomDay)r=max(r,it);
        while(l<r){
            int mid=(r-l)/2+l;
            int c=0;
            int sum=0;
            for(auto it:bloomDay){
                if(it<=mid){
                    sum++;
                    if(sum==k){
                        c++;
                        sum=0;
                    }
                }else{
                    sum=0;
                }
            }
            if(c<m)l=mid+1;
            else r=mid;
        }
        return r;
    }
};