class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:

        freq = [0] * 26

        print(ord('a') - ord('a'))

        for i in s:
            val = ord(i) - ord('a')
            freq[val]+=1

        print(freq)

        ans = [' '] * len(s)

        def f(i, tar, freq, ans, flag):
            if i == len(tar):
                if flag:
                    return ans
                return '0'                    

            if(flag==1):
                k = i

                for j in range(26):
                    while freq[j] > 0:
                        ans[k] = chr(j + ord('a'))
                        freq[j] -= 1
                        k += 1

                return ans.copy()


            for j in range(26):
                val = chr(j + ord('a'))

                if(val>=tar[i] and freq[j] != 0):
                    ans[i] = val
                    freq[j]-=1

                    nflag = flag

                    if(val > tar[i]):
                        nflag = 1

                    a = f(i+1, tar, freq, ans, nflag) 

                    if a != '0':
                        return a

                    freq[j]+=1
                    ans[i] = ' '

                # else:
                #     if (freq[j]!=0):
                #         ans[i] = val
                #         freq[j]-=1

                #         a = f(i+1, tar, freq, ans, flag) 

                #         if a != '0':
                #             return a

                #         ans[i] = ' '
                #         freq[j]+=1

            return '0'

        a = f(0, target, freq, ans, 0)

        # print(a)

        ans = ''.join(a)

        if(ans == "0"):
            return ""

        return ans

                    


            