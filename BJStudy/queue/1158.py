import sys
read = sys.stdin.readline().rstrip()

N, K = map(int, read.split())
removeIndex = K

q = [i for i in range(1, N+1)]
resultArr = []

for i in range(0, len(q)-1):
    for k in range(0, K-1):
        q.append(q.pop(0))
    resultArr.append(q.pop(0))
resultArr.append(q.pop(0))

print(resultArr)


# 1234567 / 124567 / 12457/ 1457 / 145 / 14 / 4
