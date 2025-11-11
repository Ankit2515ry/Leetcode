class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> temp = nums1;
        // for (auto& it : nums2)
        //     temp.push_back(it);
        // sort(temp.begin(), temp.end());
        // int n = temp.size();
        // double res = 0;
        // if (n % 2 == 0) {
        //     res = temp[(n / 2) - 1] + temp[n / 2];
        //     res /= 2;
        // } else
        //     res = temp[n / 2];
        // return res;
        int n = nums1.size(), m = nums2.size();
        int total = n + m;
        int mid1 = (total - 1) / 2, mid2 = total / 2;
        int i = 0, j = 0;
        double res = 0, prev = 0, curr = 0;
        for (int k = 0; k <= mid2; k++) {
            prev = curr;
            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
        }
        if (total % 2 == 0)
            res = (prev + curr) / 2.0;
        else
            res = curr;
        return res;
    }
};