#include <stdio.h>

int main()
{
  int myNum[] = {25, 50, 75, 100, 125};
  int length = sizeof(myNum) / sizeof(myNum[0]);

  for (int i = 0; i < length; i++)
  {
    printf("%d\n", myNum[i]);
  }
  return 0;
}