class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        s = set()

        n = len(A)
        C = [0]*n

        # print(A[:])

        for i in range(1, n+1):
            s1 = set(A[:i])
            s2 = set(B[:i])
            
            C[i-1] = len(s1&s2)
            

        return C
