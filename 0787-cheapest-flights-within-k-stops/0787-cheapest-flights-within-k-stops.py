from collections import deque

class Solution:
    def findCheapestPrice(self, n, flights, src, dst, k):
        graph = [[] for _ in range(n)]

        # Build graph
        for u, v, w in flights:
            graph[u].append((v, w))

        dist = [float('inf')] * n
        dist[src] = 0

        q = deque([(src, 0, 0)])   # (city, cost, stops)

        while q:
            city, cost, stops = q.popleft()

            if stops > k:
                continue

            for nei, price in graph[city]:
                new_cost = cost + price

                if new_cost < dist[nei]:
                    dist[nei] = new_cost
                    q.append((nei, new_cost, stops + 1))

        return -1 if dist[dst] == float('inf') else dist[dst]