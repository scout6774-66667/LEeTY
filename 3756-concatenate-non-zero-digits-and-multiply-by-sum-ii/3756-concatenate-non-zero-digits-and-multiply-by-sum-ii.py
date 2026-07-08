from bisect import bisect_left, bisect_right

class Solution:
    def sumAndMultiply(self, s, queries):

        MOD = 10**9 + 7

        pos = []
        digits = []

        # Store non-zero digits and their positions
        for i, ch in enumerate(s):
            if ch != '0':
                pos.append(i)
                digits.append(int(ch))

        m = len(digits)

        # Prefix sum of digits
        preSum = [0] * (m + 1)

        # Prefix number (mod MOD)
        preNum = [0] * (m + 1)

        # Powers of 10
        power = [1] * (m + 1)

        for i in range(m):
            preSum[i + 1] = preSum[i] + digits[i]
            preNum[i + 1] = (preNum[i] * 10 + digits[i]) % MOD
            power[i + 1] = (power[i] * 10) % MOD

        ans = []

        for l, r in queries:

            left = bisect_left(pos, l)
            right = bisect_right(pos, r)

            if left == right:
                ans.append(0)
                continue

            length = right - left

            x = (preNum[right] - preNum[left] * power[length]) % MOD
            sm = preSum[right] - preSum[left]

            ans.append((x * sm) % MOD)

        return ans