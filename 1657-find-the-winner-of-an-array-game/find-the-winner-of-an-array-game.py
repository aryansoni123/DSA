class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        
        nums = arr.copy()
        n = len(nums)
        i = 0
        d = {}

        if k >= n:
            return max(nums)

        while True:
            if nums[i] > nums[i+1]:
                nums.append(nums[i+1])

                if nums[i] not in d:
                    d[nums[i]] = 1
                
                    if k == 1:
                        return nums[i]
                
                else:
                    d[nums[i]]+=1

                    if d[nums[i]] == k:
                        return nums[i]
                    
                    # else:
                    #     d[nums[i]]+=1
                
                nums[i], nums[i+1] = nums[i+1], nums[i]

                i+=1

            else:
                nums.append(nums[i])
                
                if nums[i+1] not in d:
                    d[nums[i+1]] = 1
                
                    if k == 1:
                        return nums[i+1]
                
                else:
                    d[nums[i+1]]+=1

                    if d[nums[i+1]] == k:
                        return nums[i+1]

                    # else:
                    #     d[nums[i+1]]+=1
                
                i+=1

            # k-=1





                