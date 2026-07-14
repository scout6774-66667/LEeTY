from math import gcd

class Solution:
    def subsequencePairCount(self, nums):

        MOD = 10**9 + 7
        dp = {(0, 0): 1}

        for x in nums:
            new = dp.copy()

            for (g1, g2), cnt in dp.items():

                ng1 = x if g1 == 0 else gcd(g1, x)
                ng2 = x if g2 == 0 else gcd(g2, x)

                new[(ng1, g2)] = (new.get((ng1, g2), 0) + cnt) % MOD
                new[(g1, ng2)] = (new.get((g1, ng2), 0) + cnt) % MOD

            dp = new

        ans = 0

        for (g1, g2), cnt in dp.items():
            if g1 == g2 and g1 != 0:
                ans = (ans + cnt) % MOD

        return ans