class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        # n = len(edges)

        parent = [i for i in range(n)]

        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def find(x):
            if parent[x]!=x:
                parent[x] = find(parent[x])

            return parent[x]

        for u, v in edges:
            pu = find(u)
            pv = find(v)

            parent[pu] = pv

        cid = -1 

        conn = {}
        s = set()

        for i in range(n):
            parent[i] = find(i)
            s.add(parent[i])
            if parent[i] not in conn:
                conn[parent[i]] = [i]

            else:
                conn[parent[i]].append(i)

            # conn[parent[i]].append(i)

        # print(parent)
        # print(s)
        # print(conn)

        cnt = 0

        while len(s):
            node = s.pop()
            # a = b = 0
            b = 0

            for i in conn[node]:
                b+=len(adj[i])

            c = len(conn[node])

            # print(b, c*(c-1))

            if b == c*(c-1):
                cnt+=1

            
            # print(b)
            # print(len(b))
            
            # if len(b)==0 and c ==:
                # print('s')


        # print(a, s)


        return cnt