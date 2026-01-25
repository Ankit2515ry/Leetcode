/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimumDifference = function(nums, k) {
    if (k === 1) return 0;
    nums.sort((a, b) => a - b);//normal sort convert to string then sort lexicographically
    let res = Infinity;
    for (let i = 0; i + k - 1 < nums.length; i++) {
        res = Math.min(res, nums[i + k - 1] - nums[i]);
    }
    return res;
};
