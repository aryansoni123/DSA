/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number[][]} queries
 * @return {number[]}
 */
var resultArray = function(nums, k, queries) {
    const n = nums.length;

    // tree[node] = [product, cnt0, cnt1, ..., cnt(k-1)]
    const tree = Array(4 * n);

    function makeNode() {
        return [1, ...Array(k).fill(0)];
    }

    function merge(a, b) {
        const res = makeNode();

        // Product of the whole segment
        res[0] = (a[0] * b[0]) % k;

        for (let r = 0; r < k; r++) {
            // Prefix lies completely in left
            res[r + 1] += a[r + 1];

            // Prefix = whole left + prefix of right
            const nr = (a[0] * r) % k;
            res[nr + 1] += b[r + 1];
        }

        return res;
    }

    function build(node, l, r) {
        if (l === r) {
            const x = nums[l] % k;

            const cur = makeNode();
            cur[0] = x;
            cur[x + 1] = 1;

            tree[node] = cur;
            return;
        }

        const mid = Math.floor((l + r) / 2);

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    function update(node, l, r, idx, val) {
        if (l === r) {
            const x = val % k;

            const cur = makeNode();
            cur[0] = x;
            cur[x + 1] = 1;

            tree[node] = cur;
            return;
        }

        const mid = Math.floor((l + r) / 2);

        if (idx <= mid) {
            update(node * 2, l, mid, idx, val);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, val);
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    function query(node, l, r, ql, qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        const mid = Math.floor((l + r) / 2);

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        const left = query(node * 2, l, mid, ql, qr);
        const right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    build(1, 0, n - 1);

    const ans = [];

    for (const q of queries) {
        const [index, value, start, x] = q;

        // Change nums[index]
        update(1, 0, n - 1, index, value);

        // Consider nums[start ... n-1]
        const res = query(1, 0, n - 1, start, n - 1);

        // cnt[x] is stored at index x + 1
        ans.push(res[x + 1]);
    }

    return ans;
};