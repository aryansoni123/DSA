/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number[]}
 */
var lexicographicallySmallestArray = function(nums, limit) {
    const n = nums.length;

    // [value, originalIndex]
    let arr = [];

    for (let i = 0; i < n; i++) {
        arr.push([nums[i], i]);
    }

    // Sort by value
    arr.sort((a, b) => a[0] - b[0]);

    let ans = new Array(n);

    let start = 0;

    while (start < n) {
        let end = start;

        // Find the group
        while (
            end + 1 < n &&
            arr[end + 1][0] - arr[end][0] <= limit
        ) {
            end++;
        }

        // Get original indices
        let indices = [];

        for (let i = start; i <= end; i++) {
            indices.push(arr[i][1]);
        }

        // Put values at smallest original indices
        indices.sort((a, b) => a - b);

        for (let i = 0; i < indices.length; i++) {
            ans[indices[i]] = arr[start + i][0];
        }

        start = end + 1;
    }

    return ans;
};