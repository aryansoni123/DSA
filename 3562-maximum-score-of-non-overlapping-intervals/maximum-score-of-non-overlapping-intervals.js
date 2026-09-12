/**
 * @param {number[][]} intervals
 * @return {number[]}
 */
var maximumWeight = function(intervals) {
    const n = intervals.length;

    // [l, r, weight, originalIndex]
    const a = intervals.map((x, i) => [x[0], x[1], x[2], i]);

    // Sort by starting point.
    a.sort((x, y) => x[0] - y[0]);

    // next[i] = first interval whose start > a[i].end
    const next = new Int32Array(n);

    for (let i = 0; i < n; i++) {
        let lo = i + 1, hi = n;

        while (lo < hi) {
            const mid = (lo + hi) >> 1;

            if (a[mid][0] > a[i][1]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        next[i] = lo;
    }

    /*
        dp[i][k] = best result using intervals from i onward,
                   choosing at most k intervals.

        Since k <= 4, we can store:
        - score
        - selected original indices

        Doing arrays directly would be expensive, so we use
        persistent linked nodes for the chosen indices.
    */

    // nodeScore[node], nodeIndex[node], nodeNext[node]
    const nodeScore = [];
    const nodeIndex = [];
    const nodeNext = [];

    function makeNode(score, index, nextNode) {
        const id = nodeScore.length;
        nodeScore.push(score);
        nodeIndex.push(index);
        nodeNext.push(nextNode);
        return id;
    }

    // dpScore[k] and dpNode[k] for each position.
    //
    // We process from right to left.
    const dpScore = Array.from({ length: n + 1 }, () => new Float64Array(5));
    const dpNode = Array.from({ length: n + 1 }, () => new Int32Array(5));

    // 0 means empty list.
    // Nodes are created in increasing original-index order? Not guaranteed,
    // so comparison explicitly constructs up to 4 indices.
    
    function getIndices(node) {
        const res = [];

        while (node !== 0) {
            res.push(nodeIndex[node]);
            node = nodeNext[node];
        }

        res.sort((x, y) => x - y);
        return res;
    }

    function better(score1, node1, score2, node2) {
        if (score1 !== score2) return score1 > score2;

        const x = getIndices(node1);
        const y = getIndices(node2);

        const len = Math.min(x.length, y.length);

        for (let i = 0; i < len; i++) {
            if (x[i] !== y[i]) return x[i] < y[i];
        }

        return x.length < y.length;
    }

    // Empty-list node.
    nodeScore.push(0);
    nodeIndex.push(-1);
    nodeNext.push(0);

    for (let i = n - 1; i >= 0; i--) {
        const [l, r, w, originalIndex] = a[i];

        for (let k = 1; k <= 4; k++) {
            // Option 1: skip this interval.
            let bestScore = dpScore[i + 1][k];
            let bestNode = dpNode[i + 1][k];

            // Option 2: take this interval.
            const j = next[i];

            const takeScore = w + dpScore[j][k - 1];

            // Add current index to the persistent list.
            const takeNode = makeNode(
                takeScore,
                originalIndex,
                dpNode[j][k - 1]
            );

            if (better(takeScore, takeNode, bestScore, bestNode)) {
                bestScore = takeScore;
                bestNode = takeNode;
            }

            dpScore[i][k] = bestScore;
            dpNode[i][k] = bestNode;
        }
    }

    return getIndices(dpNode[0][4]);
};