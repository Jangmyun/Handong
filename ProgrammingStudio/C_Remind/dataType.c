#include <stdio.h>
#define MONTHS 12

int main(void)
{
  double monthSalary = 1000.5;
  printf("$ %.2f\n", monthSalary * MONTHS);

  int cc = 65;
  printf("%c\n", cc);
  return 0;
}
