class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos=[]
        neg = []

        for i in nums:
            if i<0:
                neg.append(i)

            if i>=0:
                pos.append(i)

        # f = nums[0]>=0

        # print(f)

        # ans = []

        # if f:
        #     ans.append(pos.pop())

        ans = [0]*(len(nums))
        ans[0::2] = pos
        ans[1::2] = neg

        # n = len(nums)

        # while n>0:
        #     if len(pos):
        #         ans.append(pos.pop())

        #     if len(neg):
        #         ans.append(neg.pop())
        #     n-=2
        
        return ans
        
            