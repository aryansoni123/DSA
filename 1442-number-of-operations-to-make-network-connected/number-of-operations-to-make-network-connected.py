class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        def find(x):
            if parent[x]!=x:
                parent[x] = find(parent[x])

            return parent[x]

        
        parent = [i for i in range(n)]

        for u, v in connections:
            pu = find(u)
            pv = find(v)

            if pu!=pv:
                parent[pv] = pu
                
        for i in range(n):
            find(i)

        # print(parent)

        need = len(set(parent)) - 1
        
        # print(need)

        if n-1>len(connections):
            return -1

        return need