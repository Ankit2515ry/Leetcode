/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function(nums) {
    let n=nums.length+1;
    let arr=new Array(n).fill(0);
    for(let i=0;i<n-1;i++){
        arr[nums[i]]++;
    }
    // for(let i=1;i<n;i++){
    //     console.log(arr[i]);
    // }
    let res=[];
    for(let i=1;i<n;i++){
        if(arr[i]==2)res.push(i);
    }
    for(let i=1;i<n;i++){
        if(arr[i]==0)res.push(i);
    }
    return res;
};