/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let st=new Set();
    for(let v of nums1)st.add(v);
    let st2=new Set();
    for(let v of nums2){
        if(st.has(v))st2.add(v);
    }
    let res=[];
    for(let key of st2){
        res.push(key);
    }
    let ans=Array.from(st2);
    return ans;
    //return res;
};