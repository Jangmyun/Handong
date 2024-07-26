from queue import PriorityQueue
import sys

read = sys.stdin.readline()

N = int(read)
arr = []
q = PriorityQueue()

for i in range(N):
    a = int(read)
    if (a == 0):
        if (q.empty()):
            arr.append(0)
        else:
            arr.append(q.get())
    elif (a > 0):
        q.put(a)
    else:
        q.put(-a)

print(*arr)
