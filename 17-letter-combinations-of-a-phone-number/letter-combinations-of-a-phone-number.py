class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dick = {
            2:'abc',
            3:'def',
            4:'ghi',
            5:'jkl',
            6:'mno',
            7:'pqrs',
            8:'tuv',
            9:'wxyz'
        }

        ans = []

        if len(digits)==4:
            for i in dick[int(digits[-4])]:
                for j in dick[int(digits[-3])]:
                    for k in dick[int(digits[-2])]:
                        for l in dick[int(digits[-1])]:
                            a = i+j+k+l
                            ans.append(a)
        if len(digits)==3:
            for i in dick[int(digits[-3])]:
                for j in dick[int(digits[-2])]:
                    for k in dick[int(digits[-1])]:
                        # for l in dick[int(digits[-1])]:
                        a = i+j+k
                        ans.append(a)

        if len(digits)==2:
            for i in dick[int(digits[-2])]:
                for j in dick[int(digits[-1])]:
                    # for k in dick[int(digits[-2])]:
                    #     for l in dick[int(digits[-1])]:
                    a = i+j
                    ans.append(a)

        if len(digits)==1:
            for i in dick[int(digits[-1])]:
                # for j in dick[int(digits[-3])]:
                #     for k in dick[int(digits[-2])]:
                #         for l in dick[int(digits[-1])]:
                a = i
                ans.append(a)


        return ans

        # print(n)

        return []

        
        