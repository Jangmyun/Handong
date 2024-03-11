#include <stdio.h>
#include <string.h>

struct myStructure
{
  int myNum;
  char myChar;
  char myString[30];
};

int main()
{
  struct myStructure s1;
  s1.myNum = 1;
  s1.myChar = 'A';
  strcpy(s1.myString, "Some Text");

  return 0;
}