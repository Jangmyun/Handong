import sys
read = sys.stdin.readline().rstrip()
N = int(read)

answer = 1
while N >= answer:
    N -= answer
    answer += 1

print(answer-1)
