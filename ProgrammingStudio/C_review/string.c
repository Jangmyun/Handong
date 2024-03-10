#include <stdio.h>
#include <string.h>

int main()
{
  char str1[20] = "Hello ";
  // strcat 쓸 때 첫번째 매개변수로 들어가는 char array는 합칠 두개의 char array의 길이보다 같거나 길어야함.
  char str2[] = "World!";

  strcat(str1, str2);
  printf("%s\n", str1);
  printf("%s", str2);
}