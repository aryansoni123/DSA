class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:

        n = len(s)

        freq = [0] * 26

        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        # Check whether a palindrome is possible
        odd = -1

        for i in range(26):
            if freq[i] % 2:
                if odd != -1:
                    return ""
                odd = i

        # Characters available for the left half
        half = [0] * 26

        for i in range(26):
            half[i] = freq[i] // 2

        half_len = n // 2

        mid = ""
        if n % 2:
            mid = chr(ord('a') + odd)

        ans = [''] * half_len

        def build():

            left = ''.join(ans)
            return left + mid + left[::-1]

        def f(i, greater):

            # Finished constructing left half
            if i == half_len:
                cur = build()

                if cur > target:
                    return cur

                return ""

            # Once we are already greater,
            # put the smallest possible remaining chars.
            if greater:

                for j in range(26):
                    while half[j] > 0:
                        ans[i] = chr(ord('a') + j)
                        half[j] -= 1
                        i += 1

                res = build()

                return res if res > target else ""

            # Still equal to target.
            for j in range(26):

                if half[j] == 0:
                    continue

                ch = chr(ord('a') + j)

                # Can't make this position smaller
                if ch < target[i]:
                    continue

                ans[i] = ch
                half[j] -= 1

                new_greater = (ch > target[i])

                res = f(i + 1, new_greater)

                if res != "":
                    return res

                half[j] += 1
                ans[i] = ''

            return ""

        return f(0, False)
