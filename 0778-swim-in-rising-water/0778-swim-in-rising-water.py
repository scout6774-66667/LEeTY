import heapq

class Solution:
    def swimInWater(self, grid):
        n = len(grid)

        dist = [[float("inf")] * n for _ in range(n)]
        dist[0][0] = grid[0][0]

        pq = [(grid[0][0], 0, 0)]   # (time, row, col)
        dirs = [(1,0), (-1,0), (0,1), (0,-1)]

        while pq:
            time, r, c = heapq.heappop(pq)

            if (r, c) == (n - 1, n - 1):
                return time

            if time > dist[r][c]:
                continue

            for dr, dc in dirs:
                nr, nc = r + dr, c + dc

                if 0 <= nr < n and 0 <= nc < n:
                    new_time = max(time, grid[nr][nc])

                    if new_time < dist[nr][nc]:
                        dist[nr][nc] = new_time
                        heapq.heappush(pq, (new_time, nr, nc))