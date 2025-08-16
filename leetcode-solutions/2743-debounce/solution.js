/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timerId;
    return function(...args) {
        // If a timer is already running, cancel it
        if(timerId){
            clearTimeout(timerId);
        }
        // Schedule a new timer for fn with the latest arguments
        timerId = setTimeout(() => {
            fn(...args);
        }, t);  
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
