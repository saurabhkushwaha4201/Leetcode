/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let n = arr.length;
    const a = new Array();
    // for(let i = 0;i<n;i++)
    // {
    //     if(fn(arr[i],i))
    //     a.push(arr[i]);
    // }
    arr.forEach((val,idx)=>{
        if(fn(val,idx))
        a.push(val);
    })
    return a;
};
