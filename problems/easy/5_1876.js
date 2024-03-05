/**
 * @param {string} s
 * @return {number}
 */
var countGoodSubstrings = function(s) {
   if (s.length < 3) return 0;

   let count = 0;
   
    for (let i = 2; i < s.length; i++) { // O(n)
        let c1 = s[i-2];
        let c2 = s[i-1];
        let c3 = s[i];

        let isDistinct = c1 !== c2 && c1 !== c3 && c2 !== c3;

        if (isDistinct) count++;
    } 

    return count;
};

console.log(countGoodSubstrings("aababcabc"));