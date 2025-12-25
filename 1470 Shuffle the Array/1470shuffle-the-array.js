/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle = function(nums, n) {
    // let k=n;
    // let a=[];
    // let i=0;
    // for(i;i<n;i++){
    //     a.push(nums[i]);
    // }
    // let b=[];
    // for(i;i<nums.length;i++){
    //     b.push(nums[i]);
    // }
    // let res=[];
    // i=0;
    // for(i;i<n;i++){
    //     res.push(a[i]);
    //     res.push(b[i]);
    // }
    // return res;
    let res=[];
    for(let i=0;i<n;i++){
        res.push(nums[i]);
        res.push(nums[i+n]);
    }
    return res;
};