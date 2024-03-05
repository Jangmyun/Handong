#include <stdio.h>

int main()
{
  // 리터럴 기초
  printf("%d\n", 10);
  printf("%f\n", 0.1);
  printf("%c\n", 'a');
  printf("%s\n", "Hello, World!");

  // 정수 리터럴 표기 방법
  printf("%d\n", 19);     // decimal
  printf("0%o\n", 017);   // octal number
  printf("0x%x\n", 0x1F); // hexadecimal

  printf("%f\n", 0.1f);
  printf("%f\n", 0.1F);
  printf("%f\n", 1.0E-5F); // 실수 지수 표기법

  return 0;
}