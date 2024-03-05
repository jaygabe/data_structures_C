/**
 * @param {number[]} nums
 * @return {boolean}
 */
// var isPossibleToSplit = function(nums) { // O(nlogn)

//     nums.sort((a, b) => a - b);

//     for (let i = 0; i < nums.length - 2; i++) {

//         const one = nums[i];
//         const two = nums[i+1];
//         const three = nums[i+2];

//         if (one === two && one === three) return false;
//     }

//     return true;
// };

// var isPossibleToSplit = function(nums) {
//     const storage = new Map();

//     for (let i = 0; i < nums.length; i++) {
//         const cur = nums[i];
//         const existing = storage.get(cur);
//         if (existing === 2) return false;
//         existing ? storage.set(cur, existing + 1) : storage.set(cur, 1);
//     }

//     return true;
// };

var isPossibleToSplit = function(nums) {
    const counter = new Array(100).fill(0);
    let possible = true;

    for (let i = 0; i < nums.length; i++) {
        possible = counter[nums[i] - 1] === 2 ? false : true;
        if (!possible) return false;
        counter[nums[i] - 1]++;
    }

    return possible;
};

// [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ...]

// [1,1,2,2,3,4]

// const existing = storage.get(nums[i])

// {
//     6: 1,
//     1: 1,
// }
// n = 8

// O(n)

//      i
// [6,1,3,1,1,8,9,2]

console.log(isPossibleToSplit([1,1,2,2,3,4]));
console.log(isPossibleToSplit([1,1,1,1]));
console.log(isPossibleToSplit([6,1,3,1,1,8,9,2]));