from bisect import bisect_left

class Solution:
    def gcdValues(self, nums, queries):
        m = max(nums)

        # Frequency of each number
        freq = [0] * (m + 1)
        for x in nums:
            freq[x] += 1

        # Count numbers divisible by each i
        div = [0] * (m + 1)
        for i in range(1, m + 1):
            for j in range(i, m + 1, i):
                div[i] += freq[j]

        # Count pairs with exact GCD = i
        gcdCount = [0] * (m + 1)
        for i in range(m, 0, -1):
            gcdCount[i] = div[i] * (div[i] - 1) // 2
            for j in range(2 * i, m + 1, i):
                gcdCount[i] -= gcdCount[j]

        # Prefix sum of pair counts
        prefix = []
        values = []
        total = 0

        for i in range(1, m + 1):
            if gcdCount[i]:
                total += gcdCount[i]
                prefix.append(total)
                values.append(i)

        # Answer queries
        ans = []
        for q in queries:
            ans.append(values[bisect_left(prefix, q + 1)])

        return ans