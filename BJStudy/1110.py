N = int(input())

if (not (0 <= +N <= 99)):
    print("Error")

result = N
output = 0


while (True):

    tens = (result // 10)
    ones = result % 10

    resultNew = (tens + ones) % 10
    resultOnes = result % 10
    result = resultOnes*10 + resultNew

    output += 1

    if (result == N):
        break

print(output)
