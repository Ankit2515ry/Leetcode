class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(r-l)/2+l;
            if(arr[mid]>arr[r]&&mid!=n-1&&arr[mid]>arr[mid+1])r=mid;
            else l=mid+1;
        }
        if(arr[l]>arr[r])return l;
        return r;
    }
};