/**
 * @param {number[]} nums
 * @return {number}
 */
var repeatedNTimes = function(nums) {
    let st=new Set();
    for(let a of nums){
        if(st.has(a))return a;
        else st.add(a);
    }
    return -1;
};