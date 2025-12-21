/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    let l=this.length-1
    if(l<0)return -1;
    else{
        return this[l];
    }
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */