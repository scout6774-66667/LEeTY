from typing import List
from bisect import bisect_right

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        vals = sorted(set(nums))
        m = len(vals)

        idx = {v: i for i, v in enumerate(vals)}

        # Furthest value reachable in one edge
        reach = [0] * m
        for i in range(m):
            reach[i] = bisect_right(vals, vals[i] + maxDiff) - 1

        # Connected components
        comp = [0] * m
        cid = 0
        for i in range(1, m):
            if vals[i] - vals[i - 1] > maxDiff:
                cid += 1
            comp[i] = cid

        LOG = m.bit_length()

        up = [[0] * m for _ in range(LOG)]
        up[0] = reach[:]

        for k in range(1, LOG):
            for i in range(m):
                up[k][i] = up[k - 1][up[k - 1][i]]

        ans = []

        for u, v in queries:
            if u == v:
                ans.append(0)
                continue

            if nums[u] == nums[v]:
                ans.append(1)
                continue

            a = idx[nums[u]]
            b = idx[nums[v]]

            if a > b:
                a, b = b, a

            if comp[a] != comp[b]:
                ans.append(-1)
                continue

            cur = a
            steps = 0

            for k in range(LOG - 1, -1, -1):
                if up[k][cur] < b:
                    cur = up[k][cur]
                    steps += 1 << k

            ans.append(steps + 1)

        return ans