class Solution:
    def sumAndMultiply(self, n: int) -> int:
        s=0
        digi = []
        for i in str(n):
            if i == '0':
                continue 

            digi.append(i)
            s+=int(i)

        if len(digi) == 0:
            return 0

        digi = int("".join(digi))

        return digi*s
        