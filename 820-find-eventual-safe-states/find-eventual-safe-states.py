class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        V = len(graph)
        indegree = [0] * V
        adj = [[] for _ in range(V)]

        for i in range(V):
            for j in graph[i]:
                adj[j].append(i)
                indegree[i]+=1

        # for i in range(V):
        #     for j in graph[i]:
        #         indegree[j]+=1

        q = deque()

        for i in range(V):
            if indegree[i] == 0:
                q.append(i)

        topo = []

        while len(q):
            node = q.popleft()
            topo.append(node)

            for i in adj[node]:
                indegree[i]-=1
                if indegree[i] == 0:
                    q.append(i)
                    
        topo.sort()
        return topo