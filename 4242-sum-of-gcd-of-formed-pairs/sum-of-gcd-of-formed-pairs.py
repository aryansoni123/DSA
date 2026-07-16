class Solution:
    def gcdSum(self, nums: list[int]) -> int:

        n = len(nums)
        
        # def gcd(x,y):
        #     for i in range(y,0,-1):
        #         if not x%i and not y%i:
        #             return i

        mx = nums[0]
        pre = []

        for i in range(n):
            mx = max(nums[i],mx)

            if nums[i]==mx:
                pre.append(nums[i])
                continue

            pre.append(gcd(mx, nums[i]))

        pre.sort()
        s = 0

        for i in range(n):
            if i >= n-1-i:
                break
            s += gcd(pre[n-1-i], pre[i])
        
        return s