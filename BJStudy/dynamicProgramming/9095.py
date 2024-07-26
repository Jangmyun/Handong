import sys

read = sys.stdin.readline()

N = int(read)
arr = []


def plus123(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    if n == 3:
        return 4

    return plus123(n-1) + plus123(n-2) + plus123(n-3)


for i in range(N):
    a = int(input())
    print(plus123(a))
