class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=0;
        for(auto it:piles)r=max(r,it);
        while(l<r){
            int mid=(r-l)/2+l;
            int temp=0;
            // cout<<mid<<endl;
            for(auto it:piles){
                temp+=it/mid;
                if(it%mid!=0)temp++;
                // cout<<temp<<" ";
            }
            // cout<<endl;
            if(temp<=h)r=mid;
            else l=mid+1;
        }
        return r;
    }
};