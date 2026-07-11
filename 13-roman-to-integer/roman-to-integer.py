class Solution:
    def romanToInt(self, s: str) -> int:
        val = {
            'I': 1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000,   
        }

        n = len(s)

        i = n-2
        m = s[-1]
        ans = val[m]

        # print(ans, m)

        while i>=0:
            # print(i)
            if val[s[i]]<val[m]:
                # print('a', s[i])
                ans-=val[s[i]]

            elif val[s[i]]>=val[m]:
                # print('b', s[i])
                ans+=val[s[i]]
                m = s[i]

            i-=1

        return ans


        