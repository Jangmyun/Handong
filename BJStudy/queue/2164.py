import sys
from collections import deque

read = sys.stdin.readline().rstrip()

N = int(read)

queue = deque([i for i in range(1, N+1)])
output = 0

i = 0
while (len(queue) != 1):
    if (i % 2 == 0):
        queue.popleft()

    else:
        tmp = queue.popleft()
        queue.append(tmp)
    i += 1

print(queue[0])
