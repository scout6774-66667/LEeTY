class Solution:
    def sumAndMultiply(self, n):

        x = 0
        total = 0

        for ch in str(n):
            if ch != '0':
                d = int(ch)
                x = x * 10 + d
                total += d

        return x * total