#include <stdio.h>

int main()
{
  int num = 20;
  int *numPtr = &num;
  printf("%p\n", &num);
  printf("%p\n", numPtr);  // 포인터값 자체는 포인터가 가리키는 변수의 주소
  printf("%d\n", *numPtr); // 해당 포인터 주소의 값

  int numbers[] = {11, 22, 33, 44};
  int *numbersPtr = numbers;

  for (int i = 0; i < 4; i++)
  {
    printf("%p\n", &numbers[i]); // numbers 배열 각 인덱스의 주소
  }
  // 배열의 이름 = 배열의 첫번째의 포인터
  printf("%p\n", numbers);
  printf("%d\n", *numbers);
  printf("%p\n", &numbers[0]);

  printf("%d , %d", *(numbers + 1), *(numbers + 2));
  return 0;
}