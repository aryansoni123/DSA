/**
 * @param {number[]} stones
 * @return {number}
 */
var stoneGameVIII = function(stones) {
    const n = stones.length;

    // prefix sum
    for (let i = 1; i < n; i++) {
        stones[i] += stones[i - 1];
    }

    // Initially, the only possible move is taking the first n-1 stones.
    let ans = stones[n - 1];

    // Work backwards
    for (let i = n - 2; i >= 1; i--) {
        ans = Math.max(ans, stones[i] - ans);
    }

    return ans;
};