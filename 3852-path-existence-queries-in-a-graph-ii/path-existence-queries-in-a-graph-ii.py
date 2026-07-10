from typing import List

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        # Sort indices by value
        order = sorted(range(n), key=lambda i: nums[i])

        # Position of each original node in sorted order
        pos = [0] * n
        vals = [0] * n
        for i, idx in enumerate(order):
            pos[idx] = i
            vals[i] = nums[idx]

        # next[i] = farthest index reachable in one edge
        nxt = list(range(n))
        r = 0
        for l in range(n):
            while r + 1 < n and vals[r + 1] - vals[l] <= maxDiff:
                r += 1
            nxt[l] = r

        LOG = n.bit_length()

        up = [nxt]
        for _ in range(1, LOG):
            prev = up[-1]
            curr = [0] * n
            for i in range(n):
                curr[i] = prev[prev[i]]
            up.append(curr)

        ans = []

        for u, v in queries:
            if u == v:
                ans.append(0)
                continue

            l = pos[u]
            r = pos[v]
            if l > r:
                l, r = r, l

            # Not connected
            if nxt[l] == l:
                ans.append(-1)
                continue

            cur = l
            steps = 0

            for k in range(LOG - 1, -1, -1):
                if up[k][cur] < r:
                    cur = up[k][cur]
                    steps += 1 << k

            cur = nxt[cur]
            steps += 1

            if cur >= r:
                ans.append(steps)
            else:
                ans.append(-1)

        return ans