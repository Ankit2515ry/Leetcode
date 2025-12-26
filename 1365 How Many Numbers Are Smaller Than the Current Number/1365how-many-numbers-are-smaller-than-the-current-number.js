/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    let res=[];
    for(let i=0;i<nums.length;i++){
        let temp=0;
        for(let j=0;j<nums.length;j++){
            if(i==j)continue;
            else if(nums[i]>nums[j])temp++;
        }
        res.push(temp);
    }
    return res;
};