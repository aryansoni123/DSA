/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var smallestPalindrome = function(s, k) {
    const LIMIT = 1000001;

    // 1. Count character frequencies
    const freq = new Array(26).fill(0);
    for (let i = 0; i < s.length; i++) {
        freq[s.charCodeAt(i) - 97]++;
    }

    // 2. Extract left half character counts and middle character (if odd length)
    const halfCount = new Array(26).fill(0);
    let halfLen = 0;
    let midChar = "";

    for (let i = 0; i < 26; i++) {
        halfCount[i] = Math.floor(freq[i] / 2);
        halfLen += halfCount[i];
        if (freq[i] % 2 === 1) {
            midChar = String.fromCharCode(97 + i);
        }
    }

    // Helper: Combinations nCr capped at LIMIT
    function nCr(n, r) {
        if (r < 0 || r > n) return 0;
        if (r === 0 || r === n) return 1;
        r = Math.min(r, n - r);
        let res = 1;
        for (let i = 1; i <= r; i++) {
            res = Math.floor((res * (n - i + 1)) / i);
            if (res >= LIMIT) return LIMIT;
        }
        return res;
    }

    // Helper: Count distinct arrangements of available characters
    function countArrangements(counts) {
        let total = 0;
        for (let c of counts) total += c;

        let res = 1;
        for (let c of counts) {
            if (c > 0) {
                res *= nCr(total, c);
                if (res >= LIMIT) return LIMIT;
                total -= c;
            }
        }
        return res;
    }

    // Check if total possible permutations < k
    if (countArrangements(halfCount) < k) {
        return "";
    }

    // 3. Greedily build the left half
    const leftHalf = [];
    for (let pos = 0; pos < halfLen; pos++) {
        for (let i = 0; i < 26; i++) {
            if (halfCount[i] === 0) continue;

            halfCount[i]--; // Try placing character 'a' + i
            const ways = countArrangements(halfCount);

            if (ways >= k) {
                leftHalf.push(String.fromCharCode(97 + i));
                break;
            } else {
                k -= ways;
                halfCount[i]++; // Backtrack and try next character
            }
        }
    }

    const leftStr = leftHalf.join("");
    const rightStr = leftHalf.slice().reverse().join("");

    return leftStr + midChar + rightStr;
};