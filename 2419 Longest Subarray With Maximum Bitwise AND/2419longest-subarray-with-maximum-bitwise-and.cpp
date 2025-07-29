class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //a number have max number of 1's bit means not to be its the max element
        int maxNum = *max_element(nums.begin(), nums.end());
        int res = 0, temp = 0;
        for (int x : nums) {
            if (x == maxNum) temp++;
            else temp = 0;
            res = max(res, temp);
        }
        return res;
    }
};