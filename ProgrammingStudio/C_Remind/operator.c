#include <stdio.h>
#define SECOND_PER_MINUTE 60

int main(void)
{
  // + - * / %
  int inputSecond = 1000;
  int minute = inputSecond / SECOND_PER_MINUTE;
  int second = inputSecond % SECOND_PER_MINUTE;

  printf("%d초 %d분 %d초임\n", inputSecond, minute, second);

  // 증감 연산자
  int x = 0;
  printf("%d\n", x);
  x++;
  printf("%d\n", x);

  // 복합 대입 연산자
  int y = 100;
  printf("y = %d\n", y);
  y += 50; // y = y + 50;
  printf("y = %d\n", y);
  y %= 3;
  printf("y = %d\n", y);

  // 관계 연산자 거짓=0 참=1
  x = 5;
  y = 3;
  printf("%d\n", x == y);
  printf("%d\n", x != y);
  printf("%d\n", x = y);

  return 0;
}