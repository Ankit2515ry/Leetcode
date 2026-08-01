class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long l=1;
        long long r=INT_MAX;
        for(auto it:time)r=min(r,1LL*it);
        r*=totalTrips;
        while(l<r){
            long long mid=(r-l)/2+l;
            long long tn=0;
            for(auto it:time){
                tn+=mid/it;
            }
            if(tn<totalTrips){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return r;
    }
};