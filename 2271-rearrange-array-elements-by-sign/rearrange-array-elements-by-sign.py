class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos=[]
        neg = []

        for i in nums:
            if i<0:
                neg.append(i)

            if i>=0:
                pos.append(i)


        ans = [0]*len(nums)
        # ans[0::2] = pos
        # ans[1::2] = neg

        for i in range(len(nums)):
            if i%2 == 0:
                ans[i] = pos[i//2]

            else:
                ans[i] = neg[i//2]

        return ans
        
            