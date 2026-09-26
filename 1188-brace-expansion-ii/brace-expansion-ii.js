/**
 * @param {string} expression
 * @return {string[]}
 */
var braceExpansionII = function(expression) {
    function dfs(s) {
        let res = new Set();
        let parts = [];
        let cur = new Set([""]);

        for (let i = 0; i < s.length; i++) {

            if (s[i] === '{') {
                let j = i;
                let cnt = 0;

                while (j < s.length) {
                    if (s[j] === '{') cnt++;
                    if (s[j] === '}') cnt--;

                    if (cnt === 0) break;
                    j++;
                }

                let inside = s.slice(i + 1, j);

                // Split top-level comma-separated parts
                let split = [];
                let start = 0;
                cnt = 0;

                for (let k = 0; k < inside.length; k++) {
                    if (inside[k] === '{') cnt++;
                    else if (inside[k] === '}') cnt--;
                    else if (inside[k] === ',' && cnt === 0) {
                        split.push(inside.slice(start, k));
                        start = k + 1;
                    }
                }

                split.push(inside.slice(start));

                let group = new Set();

                for (const part of split) {
                    for (const x of dfs(part)) {
                        group.add(x);
                    }
                }

                // Concatenate current result with group
                let next = new Set();

                for (const a of cur) {
                    for (const b of group) {
                        next.add(a + b);
                    }
                }

                cur = next;
                i = j;
            }
            else if (s[i] === ',') {
                for (const x of cur) {
                    res.add(x);
                }

                cur = new Set([""]);
            }
            else {
                // Consecutive normal characters
                let next = new Set();

                for (const x of cur) {
                    next.add(x + s[i]);
                }

                cur = next;
            }
        }

        for (const x of cur) {
            res.add(x);
        }

        return res;
    }

    return [...dfs(expression)].sort();
};