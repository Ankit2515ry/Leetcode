/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function(matrix) {
    let sum=0;
    let c=0;
    let n=Number.MAX_SAFE_INTEGER;
    for(x of matrix){
        for(i of x){
            sum+=Math.abs(i);
            if(Math.abs(i)<n)n=Math.abs(i);
            if(i<0)c++;
        }
    }
    if(c%2==1)sum-=2*n;
    return sum;
};