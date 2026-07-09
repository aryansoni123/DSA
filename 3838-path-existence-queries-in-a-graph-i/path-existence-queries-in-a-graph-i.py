class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:

        def find(x):
            if parent[x]!=x:
                parent[x] = find(parent[x])

            return parent[x]

        parent = [i for i in range(n)]

        for i in range(1, n):
            if nums[i]<=nums[i-1] + maxDiff:
                
                pu = find(i-1)
                pv = find(i)

                parent[pv] = pu

        answer = []

        for i in queries:
            u = i[0]
            v = i[1]

            if find(u) == find(v):
                answer.append(True)

            else:
                answer.append(False)

        return answer

        # print(parent)
