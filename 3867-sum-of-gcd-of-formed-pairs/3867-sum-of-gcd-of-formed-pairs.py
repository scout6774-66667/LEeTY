from math import gcd

class Solution:
    def gcdSum(self, nums):
        arr = []
        mx = 0

        for num in nums:
            mx = max(mx, num)
            arr.append(gcd(num, mx))

        arr.sort()

        ans = 0
        left = 0
        right = len(arr) - 1

        while left < right:
            ans += gcd(arr[left], arr[right])
            left += 1
            right -= 1

        return ans