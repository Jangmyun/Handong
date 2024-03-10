#include <stdio.h>

int main()
{
  int num = 20;
  int *numPtr = &num;
  printf("%p\n", &num);
  printf("%p\n", numPtr);  // 포인터값 자체는 포인터가 가리키는 변수의 주소
  printf("%d\n", *numPtr); // 해당 포인터 주소의 값
}