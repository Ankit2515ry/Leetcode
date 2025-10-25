class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long res=0;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            res+=abs((long long)(nums1[i]-nums2[i]));
            //cout<<res<<endl;
        }
        res+=1;
        int a=nums2[n];
        long long x=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(a>nums1[i]&&a<nums2[i]||a<nums1[i]&&a>nums2[i]){
                x=0;
                break;
            }
            x=min(x,abs((long long)(nums2[i]-a)));
            x=min(x,abs((long long)(nums1[i]-a)));
        }
        return res+x;
    }
};