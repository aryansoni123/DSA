class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        # odd = n*n
        # even = n*(n-1)

        # # for i in range(1, n+1):
        # #     odd += 2*i-1
        # #     even += 2*i

        # for i in range(min(odd, even), 0, -1):
        #     if odd%i == 0 and even%i == 0:
        #         return i

        return n