from collections import deque
import sys

read = sys.stdin.readline().rstrip()

N = int(read)

queue = deque([i for i in range(1, N+1)])

while (len(queue) != 1):
    queue.popleft()
    queue.append(queue.popleft())

print(queue[0])
