import heapq

class Solution(object):
    def swimInWater(self, grid):

        n = len(grid)

        heap = [(grid[0][0], 0, 0)]
        visited = set()
        visited.add((0, 0))

        directions = [(1,0), (-1,0), (0,1), (0,-1)]

        while heap:
            time, x, y = heapq.heappop(heap)

            if x == n - 1 and y == n - 1:
                return time

            for dx, dy in directions:
                nx, ny = x + dx, y + dy

                if 0 <= nx < n and 0 <= ny < n and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    heapq.heappush(heap, (max(time, grid[nx][ny]), nx, ny))