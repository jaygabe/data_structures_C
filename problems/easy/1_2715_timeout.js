/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    var timeout = setTimeout(() => 
        fn(...args)
    , t)

    var cancelFn = () => clearTimeout(timeout);

    return cancelFn;
};

const fn1 = (x) => x * 5; 
const args1 = [2]; 
const t1 = 20; 
const cancelT = 50;

const fn2 = (x) => x**2;
const args2 = [2]; 
const t2 = 100;
const cancelT2 = 50;

const fn3 = (x1, x2) => x1 * x2;
const args3 = [2,4];
const t3 = 30;
const cancelT3 = 100;

console.log(cancellable((x) => x * 5, [2], 20));
console.log(cancellable((x) => x**2, [2], 100));
console.log(cancellable((x1, x2) => x1 * x2, [2, 4], 30));