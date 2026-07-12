class Solution:
    def arrayRankTransform(self, arr):

        nums = sorted(set(arr))
        rank = {}

        r = 1
        for num in nums:
            rank[num] = r
            r += 1

        ans = []

        for num in arr:
            ans.append(rank[num])

        return ans
        