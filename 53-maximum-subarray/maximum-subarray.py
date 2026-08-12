class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = float('-inf')
        n = len(nums)
        s1 = 0

        for i in range(n):
            if s1<0:
                s1 = 0
            s1+=nums[i]
            ans = max(s1,ans)

        return ans

        s1 = -3
        ans = -1

            
        