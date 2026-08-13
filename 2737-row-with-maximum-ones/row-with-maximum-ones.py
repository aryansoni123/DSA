class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        ans = [0, 0]

        for i in range(len(mat)):
            cnt = 0
            for j in range(len(mat[0])):
                if mat[i][j] == 1:
                    cnt+=1

            if cnt>ans[1]:
                ans = [i, cnt]

        return ans
        