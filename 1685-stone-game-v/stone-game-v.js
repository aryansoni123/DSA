/**
 * @param {number[]} stoneValue
 * @return {number}
 */
var stoneGameV = function(stoneValue) {
    const n = stoneValue.length;

    // prefix[i] = sum of stoneValue[0 ... i-1]
    const prefix = new Array(n + 1).fill(0);

    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    // dp[l][r] = maximum score for subarray [l, r]
    const dp = Array.from(
        { length: n },
        () => new Array(n).fill(0)
    );

    // length of subarray
    for (let len = 2; len <= n; len++) {
        for (let l = 0; l + len <= n; l++) {
            const r = l + len - 1;

            for (let k = l; k < r; k++) {

                const left = prefix[k + 1] - prefix[l];
                const right = prefix[r + 1] - prefix[k + 1];

                if (left < right) {
                    dp[l][r] = Math.max(
                        dp[l][r],
                        left + dp[l][k]
                    );
                }
                else if (left > right) {
                    dp[l][r] = Math.max(
                        dp[l][r],
                        right + dp[k + 1][r]
                    );
                }
                else {
                    dp[l][r] = Math.max(
                        dp[l][r],
                        left + Math.max(
                            dp[l][k],
                            dp[k + 1][r]
                        )
                    );
                }
            }
        }
    }

    return dp[0][n - 1];
};