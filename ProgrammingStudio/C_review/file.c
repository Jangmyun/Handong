#include <stdio.h>

int main()
{
  FILE *fptr;
  fptr = fopen("filename.txt", "r");

  char fileText[20];
  scanf("%s", fileText);
  fprintf(fptr, "%s", fileText);
  fclose(fptr);
}