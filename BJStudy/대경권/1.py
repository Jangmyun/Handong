def can_remove_boxes(boxes):
    rows = len(boxes)
    cols = len(boxes[0]) if rows > 0 else 0

    # 결과를 저장할 2차원 배열 초기화
    result = [[0] * cols for _ in range(rows)]

    for i in range(rows - 1, 0, -1):  # 밑에서부터 위로
        for j in range(cols):
            if boxes[i][j] == 0:
                continue
            for k in range(i - 1, -1, -1):  # 현재 박스 위에 있는 박스들과 비교
                if boxes[k][j] != 0:  # 현재 박스 위에 있는 박스 발견
                    if (boxes[i][j] <= boxes[k][j]) and (boxes[i][j] >= boxes[k][j] - (i - k)):
                        result[i][j] = 1  # 떨어지는 경우
                    break

    return result


# Example usage:
input_boxes = [
    [5, 2, 3],
    [2, 2, 6],
    [2, 3, 5]
]

result = can_remove_boxes(input_boxes)
for row in result:
    print(row)
