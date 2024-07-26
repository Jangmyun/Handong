import sys
read = sys.stdin.readline()

N = int(read())
N, M = map(int, read())

N = int(input())

seatList = [[0] * N for _ in range(N)]

for i in range(N):
    input_string = input()

    for j in range(N):
        seatList[i][j] = input_string[j]


width = 0
height = 0

for i in range(N-1):
    for j in range(N-1):
        if (seatList[i][j] == '.' and seatList[i]):
    print(seatList)
