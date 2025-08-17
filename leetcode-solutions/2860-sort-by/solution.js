/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    const sortedArr = arr;
    return sortedArr.sort((a,b)=>fn(a)-fn(b));

};
