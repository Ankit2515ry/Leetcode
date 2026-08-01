class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        int l=0;
        int r=0;
        int ans=0;
        sort(position.begin(),position.end());
        r=position[n-1];
        while(l<=r){
            int c=1;
            int mid=(r-l)/2+l;
            int np=position[0]+mid;
            for(auto it:position){
                if(it>=np){
                    c++;
                    np=it+mid;
                }
            }
            if(c<m){
                r=mid-1;
            }else{
                ans=max(ans,mid);
                l=mid+1;
            }
            // cout<<l<<" "<<r<<endl;
        }
        return ans;
    }
};