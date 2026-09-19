/**
 * @param {string} s
 * @return {string[]}
 */
var maxNumOfSubstrings = function(s) {
    const n = s.length;

    // First and last occurrence of each character
    const first = Array(26).fill(n);
    const last = Array(26).fill(-1);

    for (let i = 0; i < n; i++) {
        const c = s.charCodeAt(i) - 97;
        first[c] = Math.min(first[c], i);
        last[c] = i;
    }

    const intervals = [];

    // Try creating a valid interval starting from each character
    for (let c = 0; c < 26; c++) {
        if (last[c] === -1) continue;

        let l = first[c];
        let r = last[c];
        let valid = true;

        for (let i = l; i <= r; i++) {
            const x = s.charCodeAt(i) - 97;

            // This character appeared before our current left boundary
            if (first[x] < l) {
                valid = false;
                break;
            }

            // Need to include the entire occurrence range
            r = Math.max(r, last[x]);
        }

        if (valid) {
            intervals.push([l, r]);
        }
    }

    // Earliest ending interval first
    intervals.sort((a, b) => a[1] - b[1]);

    const ans = [];
    let prevEnd = -1;

    for (const [l, r] of intervals) {
        if (l > prevEnd) {
            ans.push(s.slice(l, r + 1));
            prevEnd = r;
        }
    }

    return ans;
};