import sys
from collections import deque
read = sys.stdin.readline().rstrip()

N, K = map(int, read.split())
removeIndex = K

q = deque([i for i in range(1, N+1)])
resultArr = []


for i in range(0, len(q)-1):
    for k in range(0, K-1):
        q.append(q.popleft())
    resultArr.append(q.popleft())
resultArr.append(q.popleft())

print('<', end="")
print(resultArr[0], end="")
for i in range(1, len(resultArr)):
    print(",", resultArr[i], end="")
print(">")


# 1234567 / 124567 / 12457/ 1457 / 145 / 14 / 4
