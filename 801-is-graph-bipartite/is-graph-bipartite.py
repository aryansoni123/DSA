class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)

        # test

        vis = [-1]*n
        # f = 1
        for j in range(n):
            if vis[j] != -1:
                continue

            vis[j] = 1
            q = deque()
            q.append(j)
            # cnt = 0

            while len(q):
                node = q.popleft()
                # cnt+=1

                if vis[node]:
                    f = 0
                else:
                    f = 1

                for i in graph[node]:

                    if vis[i] == -1:
                        vis[i] = f
                        q.append(i)

                    if vis[node] == vis[i]:
                        return False

        # if cnt!=n:
        #     return False

        # print(not 0)

        return True
