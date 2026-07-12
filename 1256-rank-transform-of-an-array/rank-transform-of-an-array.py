class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        
        n = len(arr)
        a = sorted(set(arr))
        dick = {}

        for i in range(len(a)):
            # if dick[ai]
            dick[a[i]] = i+1

        # print(dick)

        ans = []

        for i in arr:
            ans.append(dick[i])

        return ans
