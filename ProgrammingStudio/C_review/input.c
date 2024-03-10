#include <stdio.h>

int main()
{
  int myNum;
  printf("Type: ");
  scanf("%d", &myNum);
  printf("myNum: %d", myNum);

  char fullName[30];
  printf("Full Name: ");
  fgets(fullName, sizeof(fullName), stdin); // 공백이 있는 문자열을 저장하고 싶을 때
  // 매개변수 : string변수, sizeof(string변수), stdin
  printf("Name : %s", fullName);
}