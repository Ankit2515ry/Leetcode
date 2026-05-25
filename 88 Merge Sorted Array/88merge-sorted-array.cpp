class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //brute force ((m+n)log(m+n))
        
        // int j=m;
        // for(int i=0;i<n;i++){
        //     nums1[j]=nums2[i];
        //     j++;
        // }
        // sort(nums1.begin(),nums1.end());


        nums1.resize(m+n);
        int i=m+n-1;
        int j=n-1;
        int k=m-1;
        while(i>=0){
            if(j>=0&&k>=0&&nums2[j]>nums1[k]){
                nums1[i]=nums2[j];
                j--;
            }else{
                if(j>=0&&k>=0){
                    nums1[i]=nums1[k];
                    k--;
                }else if(j>=0){
                    nums1[i]=nums2[j];
                    j--;
                }
            }
            i--;
        }
    }
};