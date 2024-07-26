from queue import PriorityQueue
import heapq
import sys

read = sys.stdin.readline().rstrip()

N = int(read)

minQ = PriorityQueue()
maxQ = PriorityQueue()

n = 0
mid = 0
tmp = 0
for i in range(N):
    n = int(read)
    if (i == 0):
        mid = n
        maxQ.put(mid)
    else:
        if n > mid:
            minQ.put([-n, n])
        else:
            maxQ.put(n)
