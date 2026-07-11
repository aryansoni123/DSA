class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        diff = float('inf')

        ans = 0

        dick = {}

        n = len(nums)
        nums.sort()

        # print(nums)

        for k in range(n):
            i = k+1
            j = n-1

            while i<j:

                if i == k:
                    i+=1

                if j == k:
                    j-=1

                a = nums[i]+nums[j]+nums[k]
                
                if abs(target - a)<diff:
                    diff = abs(a-target)
                    ans = a

                if a>target:
                    j-=1

                else:
                    i+=1

        
        return ans