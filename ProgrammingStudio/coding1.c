#include <stdio.h>

int main()
{
  char name[20];
  char title[][20] = {"국어", "영어", "수학"};
  int score[3];
  int sum = 0, i;
  double avg;

  printf("학생 이름 입력: ");
  scanf("%s", name);
  for (int i = 0; i < 3; i++)
  {
    printf("%s점수 입력: ", title[i]);
    scanf("%d", &score[i]);
    sum += score[i];
  }
  avg = sum / 3.0;
  printf("%s 학생 합계 %d\n평균 %.2f", name, sum, avg);
}