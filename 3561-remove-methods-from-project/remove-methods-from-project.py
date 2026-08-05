class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        adj1 = [[] for _ in range(n)]
        indeg = [0] * n

        for u, v in invocations:
            adj[u].append(v)


        q = deque()
        q.append(k)
        vis = [0]*n
        vis[k] = 1

        while len(q):
            node = q.popleft()

            for i in adj[node]:
                if not vis[i]:
                    q.append(i)
                    vis[i] = 1

        ans = []

        for u, v in invocations:
            if not vis[u] and vis[v]:
                return list(range(n))


        for i in range(n):
            if not vis[i]:
                ans.append(i)

        return ans