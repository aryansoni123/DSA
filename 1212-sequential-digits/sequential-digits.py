class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        s = '123456789'
        ans = []

        for i in range(2, 10):
            for j in range(10-i):
                val = int(s[j:j+i])
                if low<=val<=high:
                    ans.append(val)

        return ans