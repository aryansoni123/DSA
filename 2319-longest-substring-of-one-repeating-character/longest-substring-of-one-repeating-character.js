/**
 * @param {string} s
 * @param {string} queryCharacters
 * @param {number[]} queryIndices
 * @return {number[]}
 */
var longestRepeating = function(s, queryCharacters, queryIndices) {
    let tree = new SegmentTree([...s]);
    let ans = [];

    for (let i = 0; i < queryIndices.length; i++) {
        tree.update(queryIndices[i], queryCharacters[i]);
        ans.push(tree.query());
    }

    return ans;
};

class SegmentTree {
    constructor(s) {
        this.root = this.constructTree(0, s.length - 1, s);
    }

    constructTree(l, r, s) {
        if (l === r) {
            return new Node(
                s[l], s[r],
                1, 1, 1,
                l, r,
                true
            );
        }

        let mid = Math.floor((l + r) / 2);

        let left = this.constructTree(l, mid, s);
        let right = this.constructTree(mid + 1, r, s);

        let startChar = s[l];
        let endChar = s[r];

        let startFreq;
        let endFreq;
        let maxFreq = Math.max(left.maxFreq, right.maxFreq);
        let isSame = false;

        if (left.isSame && right.isSame &&
            left.endChar === right.startChar) {

            startFreq = left.startFreq + right.startFreq;
            endFreq = startFreq;
            maxFreq = Math.max(maxFreq, startFreq);
            isSame = true;

        } else if (left.isSame &&
                   left.endChar === right.startChar) {

            startFreq = left.startFreq + right.startFreq;
            endFreq = right.endFreq;
            maxFreq = Math.max(maxFreq, startFreq);

        } else if (right.isSame &&
                   left.endChar === right.startChar) {

            startFreq = left.startFreq;
            endFreq = left.endFreq + right.startFreq;
            maxFreq = Math.max(maxFreq, endFreq);

        } else {

            startFreq = left.startFreq;
            endFreq = right.endFreq;

            if (left.endChar === right.startChar) {
                maxFreq = Math.max(
                    maxFreq,
                    left.endFreq + right.startFreq
                );
            }
        }

        let node = new Node(
            startChar,
            endChar,
            startFreq,
            endFreq,
            maxFreq,
            l,
            r,
            isSame
        );

        node.left = left;
        node.right = right;

        return node;
    }

    query() {
        return this.root.maxFreq;
    }

    update(idx, ch) {
        this._update(idx, ch, this.root);
    }

    _update(idx, ch, curr) {
        // Leaf node
        if (curr.startIdx === idx && curr.endIdx === idx) {
            curr.startChar = ch;
            curr.endChar = ch;
            return;
        }

        let mid = Math.floor(
            (curr.startIdx + curr.endIdx) / 2
        );

        if (idx <= mid) {
            this._update(idx, ch, curr.left);
        } else {
            this._update(idx, ch, curr.right);
        }

        let left = curr.left;
        let right = curr.right;

        curr.startChar = left.startChar;
        curr.endChar = right.endChar;

        curr.maxFreq = Math.max(
            left.maxFreq,
            right.maxFreq
        );

        if (left.isSame &&
            right.isSame &&
            left.endChar === right.startChar) {

            curr.isSame = true;

            curr.startFreq =
                left.startFreq + right.startFreq;

            curr.endFreq = curr.startFreq;

            curr.maxFreq = curr.startFreq;

        } else if (left.isSame &&
                   left.endChar === right.startChar) {

            curr.isSame = false;

            curr.startFreq =
                left.startFreq + right.startFreq;

            curr.endFreq = right.endFreq;

            curr.maxFreq = Math.max(
                curr.startFreq,
                right.maxFreq
            );

        } else if (right.isSame &&
                   left.endChar === right.startChar) {

            curr.isSame = false;

            curr.startFreq = left.startFreq;

            curr.endFreq =
                left.endFreq + right.startFreq;

            curr.maxFreq = Math.max(
                left.maxFreq,
                curr.endFreq
            );

        } else {

            curr.isSame = false;

            curr.startFreq = left.startFreq;
            curr.endFreq = right.endFreq;

            if (left.endChar === right.startChar) {
                curr.maxFreq = Math.max(
                    curr.maxFreq,
                    left.endFreq + right.startFreq
                );
            }
        }
    }
}

class Node {
    constructor(
        startChar,
        endChar,
        startFreq,
        endFreq,
        maxFreq,
        startIdx,
        endIdx,
        isSame
    ) {
        this.startChar = startChar;
        this.endChar = endChar;

        this.startFreq = startFreq;
        this.endFreq = endFreq;
        this.maxFreq = maxFreq;

        this.startIdx = startIdx;
        this.endIdx = endIdx;

        this.isSame = isSame;

        this.left = null;
        this.right = null;
    }
}