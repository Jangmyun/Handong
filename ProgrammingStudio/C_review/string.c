#include <stdio.h>
#include <string.h>

int main()
{
  char str1[20] = "Hello ";
  // strcat 쓸 때 첫번째 매개변수로 들어가는 char array는 합칠 두개의 char array의 길이보다 같거나 길어야함.
  char str2[20] = "World!";

  strcat(str1, str2);
  printf("%s\n", str1);

  strcpy(str2, str1);
  printf("%s\n", str2);

  printf("%d\n", strcmp(str1, str2));
  // strcmp (string compare) 같으면 0 다르면 0아닌값
}