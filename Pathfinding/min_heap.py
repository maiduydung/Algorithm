import heapq

Q = []

#push tuple (value, index) to heap
heapq.heappush(Q, (5, 1))
heapq.heappush(Q, (3, 2))

min_val, argmin_idx = heapq.heappop(Q)

print(min_val, argmin_idx)