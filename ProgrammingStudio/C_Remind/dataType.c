#include <stdio.h>
#define MONTHS 12

int main(void)
{
  double monthSalary = 1000.5;
  printf("$ %.2f\n", monthSalary * MONTHS);

  int cc = 'A';
  printf("%d\n", cc);

  int x = 100;
  printf("10진수 : %d\n", x);
  printf("8진수 : %o\n", x);
  printf("16진수 : %x\n", x);

  return 0;
}
