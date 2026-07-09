class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:

        # def find(x):
        #     if parent[x]!=x:
        #         parent[x] = find(parent[x])

        #     return parent[x]

        # parent = [i for i in range(n)]
        parent = [0]*n

        # for i in range(1, n):
        #     if nums[i]<=nums[i-1] + maxDiff:
                
        #         pu = find(i-1)
        #         pv = find(i)

        #         parent[pv] = pu

        cid = 0

        for i in range(1, n):
            if nums[i] > nums[i-1] + maxDiff:
                cid+=1

            parent[i] = cid

        answer = []

        for i in queries:
            u = i[0]
            v = i[1]
            
            answer.append(parent[u] == parent[v])

        return answer

        # print(parent)
