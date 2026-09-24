from collections import deque

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])
        vis = [[-1 for _ in range(m)]for _ in range(n)]
        queue = deque()

        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    vis[i][j] = 0
                    queue.append([i,j])

        while len(queue):
            r, c = queue.popleft()

            dr = (0,1,0,-1)
            dc = (1,0,-1,0)

            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]

                if nr>=0 and nc>=0 and nr<n and nc<m and vis[nr][nc] == -1:
                    vis[nr][nc] = vis[r][c] + 1
                    queue.append([nr,nc])

        return vis



