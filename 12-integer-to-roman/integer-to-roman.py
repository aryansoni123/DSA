class Solution:
    def intToRoman(self, num: int) -> str:
        # dick = {
        thou = ['', 'M', 'MM', 'MMM']
        hund =['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
        tens=['', 'X','XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
        ones=['', 'I','II','III','IV', 'V','VI','VII','VIII','IX']
        # }

        ans = ''

        n = str(num)

        if len(n)==4:
            # print(int(n[0]))
            ans+= thou[int(n[-4])]

        if len(n)>=3:
            ans+= hund[int(n[-3])]

        if len(n)>=2:
            ans+= tens[int(n[-2])]

        if len(n)>=1:
            ans+= ones[int(n[-1])]
            
        # return thou[int(n[0])-1] + hund[int(n[1])-1] + tens[int(n[2])-1] + ones[int(n[3])-1]
        return ans